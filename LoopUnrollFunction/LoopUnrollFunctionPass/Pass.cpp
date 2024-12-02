#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"

using namespace llvm;

int globalOrder = 0;

namespace {
struct LoopUnrollEmitPass : public PassInfoMixin<LoopUnrollEmitPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        auto &LoopInfo = FAM.getResult<LoopAnalysis>(F);
        auto &ScalarEvolution = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &TTI = FAM.getResult<TargetIRAnalysis>(F);
        auto &DT = FAM.getResult<DominatorTreeAnalysis>(F);
        auto &AC = FAM.getResult<AssumptionAnalysis>(F);

        for (Loop *L : LoopInfo.getLoopsInPreorder()) {
            // if (!L->isInnermost())
            //     continue;

            // if (!L->isLoopSimplifyForm()) {
            //     errs() << "Loop is not in simplified form, skipping.\n";
            //     continue;
            // }

            // errs() << "Processing loop in function: " << F.getName() << "\n";

            for (unsigned UnrollFactor = 1; UnrollFactor <= 8; ++UnrollFactor) {
                // Configure UnrollLoopOptions
                UnrollLoopOptions ULO;
                ULO.Count = UnrollFactor;
                ULO.Force = true;
                ULO.AllowExpensiveTripCount = true;

                // Attempt to unroll the loop
                auto UnrollResult = UnrollLoop(L, ULO, &LoopInfo, &ScalarEvolution, &DT, &AC, &TTI, nullptr, false);

                // Check if unrolling was successful
                if (UnrollResult != LoopUnrollResult::FullyUnrolled &&
                    UnrollResult != LoopUnrollResult::PartiallyUnrolled) {
                    errs() << "Failed to unroll loop with factor: " << UnrollFactor << "\n";
                    continue;
                }

                // Save the modified function to a file
                std::string FileName = "unrolled_factor_loop" + std::to_string(globalOrder) +
                                       "_factor_" + std::to_string(UnrollFactor) + ".ll";
                std::error_code EC;
                llvm::raw_fd_ostream Out(FileName, EC, llvm::sys::fs::OF_None);

                if (!EC) {
                    // Print the module to a file, ensuring compatibility with older LLVM
                    F.getParent()->print(Out, nullptr);
                    // errs() << "Saved IR for unroll factor " << UnrollFactor << " to " << FileName << "\n";
                } else {
                    errs() << "Failed to write file: " << FileName << "\n";
                }
            }
            globalOrder++;
        }

        return PreservedAnalyses::all();
    }
};
} // namespace

// Plugin Registration
extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
    return {
        LLVM_PLUGIN_API_VERSION, "LoopUnrollEmitPass", "v0.1",
        [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                    if (Name == "loop-unroll-emit") {
                        FPM.addPass(LoopUnrollEmitPass());
                        return true;
                    }
                    return false;
                });
        }};
}
