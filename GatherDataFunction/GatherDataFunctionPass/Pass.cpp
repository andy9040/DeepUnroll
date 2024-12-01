#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/JSON.h"

using namespace llvm;

namespace {
  struct LoopInfoGatherPass : public PassInfoMixin<LoopInfoGatherPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        auto &LoopInfo = FAM.getResult<LoopAnalysis>(F);
        auto &ScalarEvolution = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &DA = FAM.getResult<DependenceAnalysis>(F);
        auto &BFI = FAM.getResult<BlockFrequencyAnalysis>(F);
        auto &BPI = FAM.getResult<BranchProbabilityAnalysis>(F);

        json::Array LoopsArray;
        double BaselineFrequency = static_cast<double>(BFI.getEntryFreq().getFrequency());


        // Iterate over loops in the function
        for (auto *loop : LoopInfo.getLoopsInPreorder()) {
            json::Object LoopObj;

            // Basic loop properties
            LoopObj["Function"] = F.getName().str();
            LoopObj["Depth"] = loop->getLoopDepth();
            LoopObj["BasicBlocks"] = loop->getNumBlocks();

            // Static trip count estimate
            if (ScalarEvolution.hasLoopInvariantBackedgeTakenCount(loop)) {
                std::string TripCountStr;
                llvm::raw_string_ostream RSO(TripCountStr);
                ScalarEvolution.getBackedgeTakenCount(loop)->print(RSO);
                LoopObj["TripCount"] = RSO.str();
            } else {
                LoopObj["TripCount"] = "Unknown";
            }

            // Instruction analysis
            unsigned TotalInstructions = 0, MemOps = 0, Branches = 0, PHINodes = 0;
            for (auto *BB : loop->blocks()) {
                for (auto &I : *BB) {
                    TotalInstructions++;
                    if (isa<LoadInst>(I) || isa<StoreInst>(I)) {
                        MemOps++;
                    }
                    if (isa<BranchInst>(I)) {
                        Branches++;
                    }
                    if (isa<PHINode>(I)) {
                        PHINodes++;
                    }
                }
            }
            LoopObj["TotalInstructions"] = TotalInstructions;
            LoopObj["MemoryOperations"] = MemOps;
            LoopObj["BranchInstructions"] = Branches;
            LoopObj["PHINodes"] = PHINodes;

            // Dependency analysis (counts only)
            unsigned FlowDeps = 0, AntiDeps = 0, OutputDeps = 0, InputDeps = 0;
            for (auto *BB : loop->blocks()) {
                for (auto &I : *BB) {
                    for (auto &J : *BB) {
                        if (auto Dep = DA.depends(&I, &J, true)) {
                            if (Dep->isFlow()) FlowDeps++;
                            if (Dep->isAnti()) AntiDeps++;
                            if (Dep->isOutput()) OutputDeps++;
                            if (Dep->isInput()) InputDeps++;
                        }
                    }
                }
            }
            LoopObj["DependencyCounts"] = json::Object({
                {"Flow", FlowDeps},
                {"Anti", AntiDeps},
                {"Output", OutputDeps},
                {"Input", InputDeps}
            });

            // Parent loop information
            if (auto *Parent = loop->getParentLoop()) {
                LoopObj["ParentDepth"] = Parent->getLoopDepth();
            } else {
                LoopObj["ParentDepth"] = "None";
            }

            // Simplified form check
            LoopObj["IsSimplified"] = loop->isLoopSimplifyForm() ? "Yes" : "No";

            // Block Frequency Analysis
            json::Array BlockFrequencies;

            for (auto *BB : loop->blocks()) {
                double NormalizedFreq = BFI.getBlockFreq(BB).getFrequency() / BaselineFrequency;
                BlockFrequencies.push_back(NormalizedFreq);
            }


            LoopObj["NormalBlockFrequencies"] = std::move(BlockFrequencies);

            // Branch Probability Analysis
            json::Array BranchProbabilities;
            for (auto *BB : loop->blocks()) {
                for (auto &I : *BB) {
                    if (auto *BI = dyn_cast<BranchInst>(&I)) {
                        if (BI->isConditional()) {
                            auto Prob = BPI.getEdgeProbability(BB, BI->getSuccessor(0));
                            BranchProbabilities.push_back(Prob.getNumerator() / (double)Prob.getDenominator());
                        }
                    }
                }
            }
            LoopObj["BranchProbabilities"] = std::move(BranchProbabilities);

            // Add this loop's JSON to the array
            LoopsArray.push_back(std::move(LoopObj));
        }

        // Only print if there are loops
        if (!LoopsArray.empty()) {
            json::Object Output;
            Output["Loops"] = std::move(LoopsArray);

            // Print the complete JSON object
            llvm::outs() << json::Value(std::move(Output)) << "\n";
        }

        return PreservedAnalyses::all();
    }
  };
}; // namespace

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
  return {
    LLVM_PLUGIN_API_VERSION, "LoopInfoGatherPass", "v1.6",
    [](PassBuilder &PB) {
      PB.registerPipelineParsingCallback(
        [](StringRef Name, FunctionPassManager &FPM,
           ArrayRef<PassBuilder::PipelineElement>) {
          if (Name == "loop-info") {
            FPM.addPass(LoopInfoGatherPass());
            return true;
          }
          return false;
        });
    }
  };
}
