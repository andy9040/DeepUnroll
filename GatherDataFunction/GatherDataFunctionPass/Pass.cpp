#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <fstream>


using namespace llvm;

namespace {
  struct LoopInfoGatherPass : public PassInfoMixin<LoopInfoGatherPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        std::string filename = "output.csv";
        std::ofstream file;
        file.open(filename, std::ios::app);

        auto &LoopInfo = FAM.getResult<LoopAnalysis>(F);
        auto &ScalarEvolution = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &DA = FAM.getResult<DependenceAnalysis>(F);
        auto &BFI = FAM.getResult<BlockFrequencyAnalysis>(F);
        auto &BPI = FAM.getResult<BranchProbabilityAnalysis>(F);

        double BaselineFrequency = static_cast<double>(BFI.getEntryFreq().getFrequency());

        // Print CSV header
        // llvm::outs() << "Function,Depth,BasicBlocks,TripCount,TotalInstructions,MemoryOperations,"
        //              << "BranchInstructions,PHINodes,FlowDeps,AntiDeps,OutputDeps,InputDeps,"
        //              << "ParentDepth,IsSimplified,NormalizedBlockFrequencies,BranchProbabilities\n";

        for (auto *loop : LoopInfo.getLoopsInPreorder()) {
            // Collect data for each loop
            std::string FunctionName = F.getName().str();
            unsigned Depth = loop->getLoopDepth();
            unsigned BasicBlocks = loop->getNumBlocks();

            std::string TripCountStr = "Unknown";
            if (ScalarEvolution.hasLoopInvariantBackedgeTakenCount(loop)) {
                llvm::raw_string_ostream RSO(TripCountStr);
                ScalarEvolution.getBackedgeTakenCount(loop)->print(RSO);
            }

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

            std::string ParentDepthStr = "None";
            if (auto *Parent = loop->getParentLoop()) {
                ParentDepthStr = std::to_string(Parent->getLoopDepth());
            }

            std::string IsSimplified = loop->isLoopSimplifyForm() ? "1" : "0";

            std::string BlockFreqsStr;
            for (auto *BB : loop->blocks()) {
                double NormalizedFreq = BFI.getBlockFreq(BB).getFrequency() / BaselineFrequency;
                if (!BlockFreqsStr.empty()) BlockFreqsStr += ";";
                BlockFreqsStr += std::to_string(NormalizedFreq);
            }

            std::string BranchProbsStr;
            for (auto *BB : loop->blocks()) {
                for (auto &I : *BB) {
                    if (auto *BI = dyn_cast<BranchInst>(&I)) {
                        if (BI->isConditional()) {
                            auto Prob = BPI.getEdgeProbability(BB, BI->getSuccessor(0));
                            if (!BranchProbsStr.empty()) BranchProbsStr += ";";
                            BranchProbsStr += std::to_string(Prob.getNumerator() / (double)Prob.getDenominator());
                        }
                    }
                }
            }

            // Print CSV row
            file << Depth << "," << BasicBlocks << ","
                         << TotalInstructions << "," << MemOps << "," << Branches << "," << PHINodes << ","
                         << FlowDeps << "," << AntiDeps << "," << OutputDeps << "," << InputDeps << ","
                         << "," << IsSimplified << ",\"" << BlockFreqsStr << "\",\""
                         << BranchProbsStr << "\"\n";
        }

        file.close();
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
