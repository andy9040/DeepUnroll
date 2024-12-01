#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
struct LoopUnrollBenchmarkPass : public FunctionPass {
    static char ID;
    LoopUnrollBenchmarkPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
    auto &LoopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    auto &ScalarEvolution = getAnalysis<ScalarEvolutionWrapperPass>().getSE();

    for (Loop *L : LoopInfo.getLoopsInPreorder()) {
        if (!L->isInnermost()) continue;

        errs() << "Testing unroll factors for loop in function: " << F.getName() << "\n";

        unsigned BestUnrollFactor = 1;
        double BestTime = std::numeric_limits<double>::max();

        for (unsigned UnrollFactor = 1; UnrollFactor <= 8; ++UnrollFactor) {
            // Clone the function
            ValueToValueMapTy VMap;
            Function *ClonedFunction = CloneFunction(&F, VMap);
            auto &ClonedLoopInfo = getAnalysis<LoopInfoWrapperPass>(*ClonedFunction).getLoopInfo();
            Loop *ClonedLoop = ClonedLoopInfo.getLoopFor(L->getHeader());

            // Configure UnrollLoopOptions
            UnrollLoopOptions ULO;
            ULO.UnrollFactor = UnrollFactor;
            ULO.Count = 0;
            ULO.Force = true;
            ULO.AllowRuntime = true;
            ULO.AllowExpensiveTripCount = true;

            // Unroll the loop
            bool Unrolled = UnrollLoop(
                ClonedLoop, ULO, &ClonedLoopInfo, &ScalarEvolution, nullptr, nullptr, false);

            if (!Unrolled) {
                errs() << "Failed to unroll loop with factor: " << UnrollFactor << "\n";
                continue;
            }

            // Mock benchmark (replace with real benchmarking)
            double ExecutionTime = mockRunBenchmark(ClonedFunction);

            if (ExecutionTime < BestTime) {
                BestTime = ExecutionTime;
                BestUnrollFactor = UnrollFactor;
            }

            // Clean up cloned function
            ClonedFunction->eraseFromParent();
        }

        errs() << "Best unroll factor for this loop: " << BestUnrollFactor
               << " with time: " << BestTime << " ms\n";
    }

    return false; // No modifications to the original function
}


    void getAnalysisUsage(AnalysisUsage &AU) const override {
        AU.addRequired<LoopInfoWrapperPass>();
        AU.addRequired<ScalarEvolutionWrapperPass>();
    }

private:
    double mockRunBenchmark(Function *F) {
        static double MockTime = 100.0;
        return MockTime - (rand() % 10);
    }
};

char LoopUnrollBenchmarkPass::ID = 0;
static RegisterPass<LoopUnrollBenchmarkPass> X(
    "loop-unroll-benchmark", "Benchmark loop unrolling factors",
    false, false);
} // namespace
