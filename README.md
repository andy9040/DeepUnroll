# DeepUnroll: Leveraging Deep Learning for Intelligent Loop Unrolling in LLVM  

## Introduction  

**DeepUnroll** is an LLVM-based framework that uses deep learning to predict optimal **loop unroll factors**, improving runtime performance in high-performance computing (HPC) workloads. Traditional **heuristic-based** compiler optimizations struggle to generalize across different architectures and code structures. DeepUnroll overcomes these limitations by using **XGBoost, Feedforward Neural Networks (FNN), and BERT** to analyze loop characteristics and predict the **best unroll factor dynamically**.  

### **Why DeepUnroll?**

- Our ML-based approach **automatically** extracts a massive range of complex, non-linear loop features, enabling **precise unroll factors** that outperform handcrafted heuristics, which are **expensive** and **time-consuming** to develop
- Optimal unroll factors **significantly** improves program performance by increasing opportunities for **instruction-level parallelism (ILP)** and **memory locality**
- Our pass seamlessly integrates with **existing LLVM pass frameworks**
- DeepUnroll is trained on thousands of real-world code, and is **easily adaptable** to a wide range of programs and architectures

---

## **How It Works**  

1. **LLVM Passes Extract Features** → Custom **LLVM passes** gather loop attributes like iteration count, dependencies, and memory operations  
2. **Machine Learning Model Predicts Unroll Factor** → A trained ML model predicts the **optimal unroll factor**  
3. **LLVM Applies Predicted Unroll Factor** → The transformation is **automatically applied** to optimize performance  
4. **Performance Evaluation** → Benchmarks compare **DeepUnroll vs. traditional heuristics**  

DeepUnroll is trained on **IBM's Project CodeNet**, a large dataset of real-world C code, ensuring that the learned optimizations are **generalizable** across diverse programming patterns.  

---



## Running DeepUnroll

### Script Requirements
1. **Installed Tools:** Have python3, pip, LLVM, clang, and opt installed and available.
2. **Dependencies**: Install the necessary python dependencies: `pip install -r requirements.txt`. May need to additioanlly do: `pip install scipy --upgrade` and `pip install xgboost --upgrade`. 
3. **Input File:** Have a .c source file to be processed

### Step 1 - Compile LLVM Pass
Naviagte to the build directory of `DeepUnrollFunction` or create one if one does not exist. Then configure and build the project.
```
cd DeepUnroll/DeepUnrollFunction/build
cmake ..
make
```

Note: If there are errors when running cmake .. or make, run the following in the build directory and then redo the commands above.
```
make clean
rm -rf *
```

### Step 2 - Selecting Model
In the `/DeepUnroll/Models` directory, there are 3 models to choose from. Once selecting a model:

1. For the chosen model, move those files into the `/DeepUnroll/DeepUnrollFunction` directory. 
2. In `/DeepUnroll/DeepUnrollFunction/DeepUnrollPass/Pass.cpp`, go to the TODO and select the command that mathces your model and comment the rest out:
    ```
    std::string command = "python3 scriptBoost.py " + filename;
    std::string command = "python3 script.py " + filename;
    std::string command = "python3 scriptBERT.py " + InputFileName + " " filename;
    ```

    Note: The script we will call will run this DeepUnroll LVM pass, which in turn calls our model. The model relies on pre-trained parameters such as 'xgb_model.json' and 'scaler.pkl'.
### Step 3 - Running the Script
Select if you want to run the evaluation for 1 file (`evaluation.sh`) or for a directory (`directoryEval.sh`), which are both location in `DeepUnroll/DeepUnrollFunction`. 

Run the `evaluation.sh` script like so:
```
./evaluation.sh <path to .c file> 
```
OR

Run the `directoryEval.sh` script like so:
```
./directoryEval.sh <path to directory of .c files> 
```




### Step 4 - Script Outputs
#### `evaluation.sh` Output
Terminal output giving execution times for these cases: O0,O1,O2,O3,optimized,optimized.O1,optimized.O2,optimized.O3

#### `directoryEval.sh` Output
The main output is a `results.csv` file with these headers: O0,O1,O2,O3,optimized,optimized.O1,optimized.O2,optimized.O3

#### Intermediate output (that get cleaned up automatically)
##### 1. Baseline Executables
- `O0_executable`: Executable compiled with no optimizations (-O0).
- `O1_executable`: Executable compiled with basic optimizations (-O1).
- `O2_executable`: Executable compiled with moderate optimizations (-O2).
- `O3_executable`: Executable compiled with aggressive optimizations (-O3).
##### 2. Custom Pass Executable
- `optimized_executable`: Executable generated after applying the custom LLVM pass without further optimizations.
##### 3. Further Optimized Executables
- `optimized.O1_executable`: Executable generated by applying the custom LLVM pass, followed by -O1 optimizations.
- `optimized.O2_executable`: Executable generated by applying the custom LLVM pass, followed by -O2 optimizations.
- `optimized.O3_executable`: Executable generated by applying the custom LLVM pass, followed by -O3 optimizations.

### Step 5 - Perform Analysis
Run `python3 analysis.py <results file>` to generate summary stats on the reusults generated from `directoryEval.sh`. This file with remove outliers and calculate the average for each column.

---

## Generating Optimal Loop Unroll Data

### Script Requirements
1. **LLVM Pass Shared Object(.so):** Ensure that your custom LLVM pass is compiled into a shared object file.
2. **Input Directory:** Have a directory (e.g., ./codeFiles) containing .c source files to be processed.
3. **Installed Tools:** Have LLVM, clang, and opt installed and available.

### Step 1 - Compile LLVM Pass
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
### Step 2 - Prepare Input Files
Create a directory (e.g., codeFiles) in the project root and add all your .c source files to it.
NOTE: There are premade folders with names that can be used so this step can be SKIPPED. The following is just how to move files to a more convenient location if desired.
```
mkdir codeFiles
cp /path/to/source/files/*.c ./codeFiles/
```

Usefule note: To get number of files in a folder, run:
```
find path/to/dir/ -type f | wc -l
```

### Step 3 - Running the Script
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

### Step 4 - Results
Output Files:
- IR files (.ll) and executables (_exec) are generated temporarily and cleaned up after processing.

Result File:
- The script appends the fastest loop unroll factor for each loop to a specified output file named at the top of the script. By defauly, it's `"${DIRECTORY##*/}_output.txt"`

---

## FAQ: General Running LLVM Passes

### Building and Compiling
Building and compiling in this context involve creating a shared object (`.so`) file for your pass that can be dynamically loaded into the opt tool. The opt tool is the command-line utility provided by LLVM for working with its Intermediate Representation (IR).

```
cd build 
cmake ..
make
```

### Applying Individual Pass

Compile a source file (e.g., `test.c`) into LLVM IR using clang:
```
clang -emit-llvm -S -Xclang -disable-O0-optnone test.c -o test.ll
```
Note: The optnone attribute, added by Clang when compiling with -O0, instructs the LLVM optimizer and analysis passes to skip processing functions entirely, preserving their exact structure for debugging. While useful for debugging, this attribute prevents custom LLVM passes from analyzing or transforming these functions. Using -Xclang -disable-O0-optnone ensures unoptimized IR is generated without the optnone attribute, allowing all functions to be fully processed by LLVM passes while maintaining their unoptimized state for analysis.


Use the `opt` tool to apply the pass (e.g., `GatherDataFunctionPass`) to the LLVM IR:
```
opt -disable-output -load-pass-plugin=./build/GatherDataFunctionPass/GatherDataFunctionPass.so -passes="loop-info" test.ll 
```
or
```
opt -disable-output -load-pass-plugin=./build/LoopUnrollFunctionPass/LoopUnrollFunctionPass.so -passes="loop-unroll-emit" test.ll
```
or
```
opt -disable-output -load-pass-plugin=./build/DeepUnrollPass/DeepUnrollPass.so -passes="deep-unroll" -input-filename=test.c test.ll
```

If there's json out, you can prettify the json output:
```
python3 -m json.tool output.json > pretty_output.json
```

## Potentional CSV Output Consideration
| Depth | BasicBlocks | TotalInstructions | MemoryOperations | BranchInstructions | PHINodes | FlowDeps | AntiDeps | OutputDeps | InputDeps | IsSimplified | NormalizedBlockFrequencies | BranchProbabilities | IDEAL_LOOP_UNROLL_FACTOR |
|-------|--------------|------------------|-----------------|--------------------|---------|----------|----------|------------|-----------|---------------|----------------------------|---------------------|--------------------------|

## Set up
Server/Execution Requirements - Install LLVM 18.1.8
Python Requirements - 'pip3 install llvmlite'

---

## Contributors
- Andre Nandi, University of Michigan
- Vatsal Joshi, University of Michigan
- Omkar Yadav, University of Michigan
- Radhika Patel, University of Michigan
- Sai Vaka, University of Michigan
