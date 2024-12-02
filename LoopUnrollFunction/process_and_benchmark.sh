#!/bin/bash

# Ensure this script is executable by running: chmod +x process_and_benchmark.sh

# Input validation
if [ $# -eq 0 ]; then
    echo "Usage: ./process_and_benchmark.sh <source_file.c>"
    exit 1
fi

SOURCE_FILE=$1
BASE_NAME=$(basename "$SOURCE_FILE" .c)
LLVM_PASS="./build/LoopUnrollFunctionPass/LoopUnrollFunctionPass.so"
UNROLL_SCRIPT="./run_llvm.sh"

# Ensure required tools are available
if ! command -v clang &> /dev/null; then
    echo "Error: clang not found. Please install clang."
    exit 1
fi

if ! command -v opt &> /dev/null; then
    echo "Error: opt not found. Please install LLVM opt."
    exit 1
fi

if [ ! -f "$LLVM_PASS" ]; then
    echo "Error: LLVM pass plugin not found at $LLVM_PASS"
    exit 1
fi

if [ ! -x "$UNROLL_SCRIPT" ]; then
    echo "Error: Unroll script not found or not executable: $UNROLL_SCRIPT"
    exit 1
fi

# Step 1: Compile the source file into LLVM IR
LLVM_IR_FILE="${BASE_NAME}.ll"
echo "Compiling $SOURCE_FILE into LLVM IR..."
clang -emit-llvm -S -Xclang -disable-O0-optnone "$SOURCE_FILE" -o "$LLVM_IR_FILE"
if [ $? -ne 0 ]; then
    echo "Error: Failed to generate LLVM IR for $SOURCE_FILE"
    exit 1
fi

# Step 2: Run the LLVM pass
echo "Running LLVM pass on $LLVM_IR_FILE..."
opt -disable-output -load-pass-plugin="$LLVM_PASS" -passes="loop-unroll-emit" "$LLVM_IR_FILE"
if [ $? -ne 0 ]; then
    echo "Error: Failed to run the LLVM pass."
    exit 1
fi

# Step 3: Find all generated unrolled IR files
echo "Looking for generated unrolled IR files..."
UNROLLED_FILES=$(ls unrolled_factor_loop*_factor_*.ll 2> /dev/null)
if [ -z "$UNROLLED_FILES" ]; then
    echo "Error: No unrolled IR files found. Ensure your pass is generating them correctly."
    exit 1
fi

# Step 4: Identify unique loops by globalOrder
echo "Identifying unique loops by global order..."
declare -A BEST_FACTORS
LOOPS=$(echo "$UNROLLED_FILES" | grep -oP 'loop\d+' | sort | uniq)
echo "Found loops: $LOOPS"

# Step 5: Process each loop
for LOOP in $LOOPS; do
    echo "Processing $LOOP..."
    BEST_FACTOR=0
    BEST_TIME=""

    # Filter files for the current loop
    LOOP_FILES=$(echo "$UNROLLED_FILES" | grep "$LOOP")
    if [ -z "$LOOP_FILES" ]; then
        echo "No files found for $LOOP. Skipping..."
        continue
    fi

    echo "Files for $LOOP: $LOOP_FILES"

    # Benchmark each unroll factor for the current loop
    for FILE in $LOOP_FILES; do
        FACTOR=$(echo "$FILE" | grep -oP 'factor_\d+' | grep -oP '\d+')
        echo "Running benchmark for $FILE (factor $FACTOR)..."

        EXECUTION_TIME=$("$UNROLL_SCRIPT" "$FILE")
        echo "Execution time for $FILE: $EXECUTION_TIME"

        if [ "$EXECUTION_TIME" != "Invalid." ]; then
            # Track the best factor and execution time
            if [ -z "$BEST_TIME" ] || (( $(echo "$EXECUTION_TIME < $BEST_TIME" | bc -l) )); then
                BEST_TIME=$EXECUTION_TIME
                BEST_FACTOR=$FACTOR
            fi
        else
            echo "Invalid execution time for $FILE. Skipping..."
        fi
    done

    if [ "$BEST_FACTOR" -ne 0 ]; then
        BEST_FACTORS["$LOOP"]=$BEST_FACTOR
        echo "Best unroll factor for $LOOP: $BEST_FACTOR"
    else
        echo "No valid unroll factor found for $LOOP."
    fi
done

# Step 6: Output results
echo "Summary of Best Unroll Factors:"
for LOOP in "${!BEST_FACTORS[@]}"; do
    echo "Loop: $LOOP, Best Unroll Factor: ${BEST_FACTORS[$LOOP]}"
done

#Step 7: Clean up
# rm *.ll