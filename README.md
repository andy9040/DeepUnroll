# DeepUnroll
Leveraging Deep Learning for intelligent Loop Unrolling in LLVM

# Generating Optimal Loop Unroll

## Script Requirements
1. **LLVM Pass Shared Object(.so):** Ensure that your custom LLVM pass is compiled into a shared object file.
2. **Input Directory:** Have a directory (e.g., ./codeFiles) containing .c source files to be processed.
3. **Installed Tools:** Have LLVM, clang, and opt installed and available.

## Step 1 - Compile LLVM Pass
Naviagte to the build directory of `LoopUnrollFunction` or create one if one does not exist. Then configure and build the project.
```
cd DeepUnroll/LoopUnrollFunction/build
cmake ..
make
```

Note: If there are errors when running cmake .. or make, run the following in the build directory and then redo the commands above.
```
make clean
rm -rf *
```
## Step 2 - Prepare Input Files
Create a directory (e.g., codeFiles) in the project root and add all your .c source files to it.
NOTE: There are premade folders with names that can be used so this step can be SKIPPED. The following is just how to move files to a more convenient location.
```
mkdir codeFiles
cp /path/to/source/files/*.c ./codeFiles/
```

Usefule note: To get number of files in a folder, run:
```
find path/to/dir/ -type f | wc -l
```

## Step 3 - Running the Script
Run the `process_and_benchmark.sh` script like so:
```
./process_and_benchmark.sh <directory_path> <offset> <iterations>
```
- `<directory_path>`: Path to the directory containing .c files (e.g., ./codeFiles).
- `<offset>`: Start processing from the nth file in sorted order.
- `<iterations>`: Number of files to process after the offset.

NOTE: At the top of the script, there's a TIMEOUT_DURATION hyperparamter you can choose. If a file with a specific unrollment factor can't compile into byte code or into an executable after TIMEOUT_DURATION seconds, the loop unrolling factor will be skipped.

If you want to run this as a process that will continue even if you get logged out of your server, use nohup like so:
```
nohup ./process_and_benchmark.sh ../Andre 0 200 > output.log 2>&1 &
```

## Step 4 - Results
Output Files:
- IR files (.ll) and executables (_exec) are generated temporarily and cleaned up after processing.

Result File:
- The script appends the fastest loop unroll factor for each loop to a specified output file named at the top of the script. By defauly, it's `"${DIRECTORY##*/}_output.txt"`


# FAQ: General Running LLVM Passes

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
opt -disable-output -load-pass-plugin=./build/LoopUnrollFunctionPass/LoopUnrollFunctionPass.so -passes="loop-unroll-emit" test.ll
```

To prettify the json output:
```
python3 -m json.tool output.json > pretty_output.json
```

# CSV Outpt
Depth,BasicBlocks,TotalInstructions,MemoryOperations,BranchInstructions,PHINodes,FlowDeps,AntiDeps,OutputDeps,InputDeps,IsSimplified,NormalizedBlockFrequencies,BranchProbabilities, IDEAL LOOP UNROLL FACTOR

# Set up
Server/Execution Requirements - Install LLVM 18.1.8
Python Requirements - 'pip3 install llvmlite'