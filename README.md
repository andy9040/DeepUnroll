# DeepUnroll
Leveraging Deep Learning for intelligent Loop Unrolling in LLVM

# FAQ: Running LLVM Passes

## Building and Compiling
Building and compiling in this context involve creating a shared object (`.so`) file for your pass that can be dynamically loaded into the opt tool. The opt tool is the command-line utility provided by LLVM for working with its Intermediate Representation (IR).

```
cd build 
cmake ..
make
```

## Applying the Pass

Compile a source file (e.g., `test.c`) into LLVM IR using clang:
```
clang -emit-llvm -S -Xclang -disable-O0-optnone test.c -o test.ll
```
Note: The optnone attribute, added by Clang when compiling with -O0, instructs the LLVM optimizer and analysis passes to skip processing functions entirely, preserving their exact structure for debugging. While useful for debugging, this attribute prevents custom LLVM passes from analyzing or transforming these functions. Using -Xclang -disable-O0-optnone ensures unoptimized IR is generated without the optnone attribute, allowing all functions to be fully processed by LLVM passes while maintaining their unoptimized state for analysis.


Use the `opt` tool to apply the pass (e.g., `GatherDataFunctionPass`) to the LLVM IR:
```
opt -disable-output -load-pass-plugin=./build/GatherDataFunctionPass/GatherDataFunctionPass.so -passes="loop-info" test.ll > output.json
```
or
```
opt -disable-output -load-pass-plugin=./build/LoopUnrollFunctionPass/LoopUnrollFunctionPass.so -passes="loop-unroll-benchmark" test.ll
```

To prettify the json output:
```
python3 -m json.tool output.json > pretty_output.json
```