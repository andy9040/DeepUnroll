#!/bin/bash

# Ensure this script is executable: chmod +x process_and_benchmark.sh

TIMEOUT_DURATION=60  # Timeout duration for long-running tasks

# Input validation
if [ $# -lt 3 ]; then
    echo "Usage: ./process_and_benchmark.sh <directory_path> <offset> <iterations>"
    exit 1
fi

DIRECTORY=$1
OFFSET=$2
ITERATIONS=$3
LLVM_PASS="./build/LoopUnrollFunctionPass/LoopUnrollFunctionPass.so"

# Set output file based on the directory name
OUTPUT_FILE="${DIRECTORY##*/}_output.txt"  # Extract the base directory name and append _output.txt

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

# Get all .c files in the directory, sorted, and apply offset and limit
FILES=$(ls "$DIRECTORY"/*.c | sort | tail -n +"$OFFSET" | head -n "$ITERATIONS")

# Process each file in the subset
for SOURCE_FILE in $FILES; do
    BASE_NAME=$(basename "$SOURCE_FILE" .c)
    LLVM_IR_FILE="${BASE_NAME}.ll"
    echo "Processing file: $SOURCE_FILE"
    echo "$SOURCE_FILE" >> "$OUTPUT_FILE"

    # Step 1: Compile the source file into LLVM IR
    echo "Compiling $SOURCE_FILE into LLVM IR..."
    clang -emit-llvm -S -Xclang -disable-O0-optnone "$SOURCE_FILE" -o "$LLVM_IR_FILE"
    if [ $? -ne 0 ]; then
        echo "Error: Failed to generate LLVM IR for $SOURCE_FILE"
        continue
    fi

    # Step 2: Run the LLVM pass
    echo "Running LLVM pass on $LLVM_IR_FILE..."
    opt -disable-output -load-pass-plugin="$LLVM_PASS" -passes="loop-unroll-emit" "$LLVM_IR_FILE"
    if [ $? -ne 0 ]; then
        echo "Error: Failed to run the LLVM pass."
        continue
    fi

    # Step 3: Find all generated unrolled IR files
    UNROLLED_FILES=$(ls unrolled_factor_loop*_factor_*.ll 2> /dev/null)
    if [ -z "$UNROLLED_FILES" ]; then
        echo "Error: No unrolled IR files found. Ensure your pass is generating them correctly."
        continue
    fi

    # Step 4: Generate executables
    echo "Generating executables from unrolled IR files..."
    for FILE in $UNROLLED_FILES; do
        BASENAME=$(basename "$FILE" .ll)
        OPTIMIZED_BC="${BASENAME}_opt.bc"
        EXECUTABLE="${BASENAME}_exec"

        # Optimize the LLVM IR
        echo "Create .bc file: $OPTIMIZED_BC"
        if ! timeout $TIMEOUT_DURATION opt -O3 "$FILE" -o "$OPTIMIZED_BC"; then
            echo "Error: Bitcode generation of $FILE took too long and was skipped."
            continue
        fi

        # Compile to an executable
        echo "Create exec file: $EXECUTABLE"
        if ! timeout $TIMEOUT_DURATION clang "$OPTIMIZED_BC" -o "$EXECUTABLE" -O3 -fPIE -pie; then
            echo "Error: Compilation of $OPTIMIZED_BC took too long and was skipped."
            continue
        fi
    done

    # Step 5: Benchmark and find the fastest factor for each global loop ID
    echo "Benchmarking executables by global loop ID..."
    GLOBAL_IDS=$(echo "$UNROLLED_FILES" | grep -oP 'loop\d+' | sort | uniq)

    for GLOBAL_ID in $GLOBAL_IDS; do
        FASTEST_FACTOR=0
        FASTEST_TIME=""

        LOOP_FILES=$(echo "$UNROLLED_FILES" | grep "$GLOBAL_ID")
        if [ -z "$LOOP_FILES" ]; then
            echo "No files found for $GLOBAL_ID. Skipping..."
            continue
        fi

        for FILE in $LOOP_FILES; do
            FACTOR=$(echo "$FILE" | grep -oP 'factor_\d+' | grep -oP '\d+')
            EXECUTABLE="unrolled_factor_${GLOBAL_ID}_factor_${FACTOR}_exec"

            if [ ! -f "$EXECUTABLE" ]; then
                echo "Error: Executable $EXECUTABLE not found. Skipping..."
                continue
            fi

            # Generate inputs dynamically while the program requests them
            START_TIME=$(date +%s.%N)

            # Use a coprocess to provide inputs dynamically
            coproc INPUT_FEEDER {
                while true; do
                    RANDOM_INPUT=$((RANDOM % 101)) # Generate a random input
                    echo "$RANDOM_INPUT" # Send the input
                    sleep 0.01 # Slight delay to simulate user interaction
                done
            }

            # Run the executable and attach the coprocess input
            timeout 5 ./$EXECUTABLE <&"${INPUT_FEEDER[0]}" > /dev/null 2>&1

            # Kill the input feeder once the executable is done
            kill "${INPUT_FEEDER_PID}" 2>/dev/null

            END_TIME=$(date +%s.%N)
            EXECUTION_TIME=$(echo "$END_TIME - $START_TIME" | bc)

            if [ -z "$FASTEST_TIME" ] || (( $(echo "$EXECUTION_TIME < $FASTEST_TIME" | bc -l) )); then
                FASTEST_TIME=$EXECUTION_TIME
                FASTEST_FACTOR=$FACTOR
            fi
        done

        if [ "$FASTEST_FACTOR" -ne 0 ]; then
            echo "Finished a loop"
            echo "$FASTEST_FACTOR" >> "$OUTPUT_FILE"
        else
            echo "No valid unroll factor found for $GLOBAL_ID."
            echo "skipped" >> "$OUTPUT_FILE"
        fi
    done

    echo "Done with file: $SOURCE_FILE"
    rm -f *.bc *.ll *_exec
done

# Step 6: Clean up intermediate files (optional)
echo "Processing complete for the selected files."
