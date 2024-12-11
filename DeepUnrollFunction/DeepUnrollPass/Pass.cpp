
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
#include <fstream>
#include <iostream>
#include <sstream>



using namespace llvm;

namespace {

static llvm::cl::opt<std::string> InputFileName(
    "input-filename", 
    llvm::cl::desc("Name of the input file"), 
    llvm::cl::init(""));

  struct LoopInfoGatherPass : public PassInfoMixin<LoopInfoGatherPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        // llvm::outs() << "DeepUnrollPass is running on function: " << F.getName() << "\n";

        
        if (InputFileName.empty()) {
            llvm::outs() << "Input file name not provided.\n";
        }

        std::string filename = "output.csv";
        

        auto &LoopInfo = FAM.getResult<LoopAnalysis>(F);
        auto &ScalarEvolution = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &DA = FAM.getResult<DependenceAnalysis>(F);
        auto &BFI = FAM.getResult<BlockFrequencyAnalysis>(F);
        auto &BPI = FAM.getResult<BranchProbabilityAnalysis>(F);
        auto &TTI = FAM.getResult<TargetIRAnalysis>(F);
        auto &DT = FAM.getResult<DominatorTreeAnalysis>(F);
        auto &AC = FAM.getResult<AssumptionAnalysis>(F);


        double BaselineFrequency = static_cast<double>(BFI.getEntryFreq().getFrequency());

        // Print CSV header
        // llvm::outs() << "Function,Depth,BasicBlocks,TripCount,TotalInstructions,MemoryOperations,"
        //              << "BranchInstructions,PHINodes,FlowDeps,AntiDeps,OutputDeps,InputDeps,"
        //              << "ParentDepth,IsSimplified,NormalizedBlockFrequencies,BranchProbabilities\n";

        int loopId = 0;
        for (auto *loop : LoopInfo.getLoopsInPreorder()) {
            if (!loop->isInnermost()){
                loopId++;
                llvm::outs() << "SKIP" << "\n";
                continue;
            }
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

            std::ofstream file;
            file.open(filename, std::ios::out);
            // Print CSV row
            file << InputFileName<<","<<loopId << ","<<Depth << "," << BasicBlocks << ","
                         << TotalInstructions << "," << MemOps << "," << Branches << "," << PHINodes << ","
                         << FlowDeps << "," << AntiDeps << "," << OutputDeps << "," << InputDeps << ","
                         << "," << IsSimplified << ",\"" << BlockFreqsStr << "\",\""
                         << BranchProbsStr << "\"\n";
            file.close();

            //Disable loop unrolling from LLVM
            loop->setLoopID(MDNode::get(F.getContext(), MDString::get(F.getContext(), "llvm.loop.unroll.disable")));

            //Use ML model
            // std::string command = "python3 predict_boost.py " + filename;
            std::string command = "python3 scriptFNN.py " + InputFileName + " " filename;

            FILE* pipe = popen(command.c_str(), "r");
            if (!pipe) {
                llvm::outs() << "Failed to run Python script!" << "\n";
            }
            int outputValue;
            if (fscanf(pipe, "%d", &outputValue) != 1) {
                llvm::outs() << "Failed to parse output!" << "\n";
                pclose(pipe);
            }
            pclose(pipe);

            //Set the unroll factor
            unsigned UnrollFactor = outputValue+1;
            UnrollLoopOptions ULO;
            ULO.Count = UnrollFactor;
            ULO.Force = true;
            ULO.AllowExpensiveTripCount = true;

            // Attempt to unroll the loop
            auto UnrollResult = UnrollLoop(loop, ULO, &LoopInfo, &ScalarEvolution, &DT, &AC, &TTI, nullptr, false);

            // Check if unrolling was successful
            if (UnrollResult != LoopUnrollResult::FullyUnrolled &&
                UnrollResult != LoopUnrollResult::PartiallyUnrolled) {
                errs() << "Failed to unroll loop with factor: " << UnrollFactor << "\n";
                continue;
            }
            
            loopId++;
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
          if (Name == "deep-unroll") {
            FPM.addPass(LoopInfoGatherPass());
            return true;
          }
          return false;
        });
    }
  };
}
