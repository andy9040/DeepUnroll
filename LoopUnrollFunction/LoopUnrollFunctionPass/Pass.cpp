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
#include <limits>
#include <cstdlib>

using namespace llvm;

namespace {
struct LoopUnrollBenchmarkPass : public PassInfoMixin<LoopUnrollBenchmarkPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        auto &LoopInfo = FAM.getResult<LoopAnalysis>(F);
        auto &ScalarEvolution = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &TTI = FAM.getResult<TargetIRAnalysis>(F);
        auto &DT = FAM.getResult<DominatorTreeAnalysis>(F);
        auto &AC = FAM.getResult<AssumptionAnalysis>(F);

        for (Loop *L : LoopInfo.getLoopsInPreorder()) {
            if (!L->isInnermost())
                continue;

            if (!L->isLoopSimplifyForm()) {
                errs() << "Loop is not in simplified form, skipping.\n";
                continue;
            }

            errs() << "Testing unroll factors for loop in function: " << F.getName() << "\n";

            unsigned BestUnrollFactor = 1;
            double BestTime = std::numeric_limits<double>::max();

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

                // Mock benchmarking result
                double ExecutionTime = mockRunBenchmark(UnrollFactor);

                if (ExecutionTime < BestTime) {
                    BestTime = ExecutionTime;
                    BestUnrollFactor = UnrollFactor;
                }
            }

            errs() << "Best unroll factor for this loop: " << BestUnrollFactor
                   << " with time: " << BestTime << " ms\n";
        }

        return PreservedAnalyses::all();
    }

private:
    double mockRunBenchmark(unsigned UnrollFactor) {
        static double BaseTime = 100.0;
        return BaseTime - (rand() % (UnrollFactor * 5));
    }
};
} // namespace

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
    return {
        LLVM_PLUGIN_API_VERSION, "LoopUnrollBenchmarkPass", "v0.2",
        [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                    if (Name == "loop-unroll-benchmark") {
                        FPM.addPass(LoopUnrollBenchmarkPass());
                        return true;
                    }
                    return false;
                });
        }};
}
