#!/bin/bash

# Ensure this script is executable by running: chmod +x generate_exec.sh

# Input validation
if [ $# -eq 0 ]; then
    echo "No base filename provided. Usage: ./optimize_and_find_fastest.sh <base_filename>"
    exit 1
fi

BASE_FILENAME=$1

# echo "Running optimizations and benchmarking for $BASE_FILENAME..."

for i in {1..8}; do
    LLVM_IR_FILE="${BASE_FILENAME}_${i}.ll"
    BASENAME=$(basename $LLVM_IR_FILE .ll)
    OPTIMIZED_BC="${BASENAME}_opt.bc"
    EXECUTABLE="${BASENAME}_exec"
    echo $EXECUTABLE


    if [ ! -f $LLVM_IR_FILE ]; then
        # echo "Error: File $LLVM_IR_FILE not found. Skipping..."
        continue
    fi

    # Optimize the LLVM IR
    # echo "Optimizing $LLVM_IR_FILE..."
    opt -O3 $LLVM_IR_FILE -o $OPTIMIZED_BC

    # Compile and link the optimized bitcode directly to an executable with PIE support
    # echo "Compiling $OPTIMIZED_BC..."
    clang $OPTIMIZED_BC -o $EXECUTABLE -O3 -fPIE -pie
    rm $OPTIMIZED_BC
    
done
