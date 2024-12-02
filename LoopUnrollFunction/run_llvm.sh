#!/bin/bash

# Ensure this script is executable by running: chmod +x optimize_and_find_fastest.sh

# Input validation
if [ $# -eq 0 ]; then
    echo "No base filename provided. Usage: ./optimize_and_find_fastest.sh <base_filename>"
    exit 1
fi

BASE_FILENAME=$1
FASTEST_FACTOR=0
FASTEST_TIME=0

# echo "Running optimizations and benchmarking for $BASE_FILENAME..."

for i in {1..8}; do
    LLVM_IR_FILE="${BASE_FILENAME}_${i}.ll"
    BASENAME=$(basename $LLVM_IR_FILE .ll)
    OPTIMIZED_BC="${BASENAME}_opt.bc"
    EXECUTABLE="${BASENAME}_exec"

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

    # Ensure the executable was created successfully
    if [ ! -f $EXECUTABLE ]; then
        # echo "Error: The executable $EXECUTABLE was not created. Skipping..."
        continue
    fi

    # Run the executable and measure execution time
    # echo "Running $EXECUTABLE..."
    START_TIME=$(date +%s.%N)
    ./$EXECUTABLE > /dev/null 2>&1
    END_TIME=$(date +%s.%N)

    EXECUTION_TIME=$(echo "$END_TIME - $START_TIME" | bc)
    # echo "Execution Time for factor $i: $EXECUTION_TIME seconds"

    # Track the fastest factor
    if [ $FASTEST_FACTOR -eq 0 ] || (( $(echo "$EXECUTION_TIME < $FASTEST_TIME" | bc -l) )); then
        FASTEST_FACTOR=$i
        FASTEST_TIME=$EXECUTION_TIME
    fi

    # Clean up (optional, uncomment to keep intermediate files)
    rm $OPTIMIZED_BC $EXECUTABLE
done

if [ $FASTEST_FACTOR -ne 0 ]; then
    echo $FASTEST_FACTOR
else
    echo "Invalid."
fi
