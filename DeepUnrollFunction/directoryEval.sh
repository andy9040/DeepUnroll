#!/bin/bash

# Ensure this script is executable by running: chmod +x directoryEval.sh


if [ $# -ne 1 ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

DIRECTORY=$1

# Check if the directory exists
if [ ! -d "$DIRECTORY" ]; then
  echo "Error: Directory $DIRECTORY not found."
  exit 1
fi

# Initialize the results CSV with a header (if not already created)
RESULTS_FILE="results.csv"
if [[ ! -f $RESULTS_FILE ]]; then
  echo "Filename,O0,O1,O2,O3,optimized,optimized.O1,optimized.O2,optimized.O3" > $RESULTS_FILE
fi

# Loop through all .c files in the directory
for SOURCE_FILE in "$DIRECTORY"/*.c; do
  # Skip if no .c files are found
  if [[ ! -f "$SOURCE_FILE" ]]; then
    echo "No .c files found in directory $DIRECTORY."
    break
  fi

  BASENAME=$(basename "$SOURCE_FILE" .c)

  # Generate LLVM IR
  echo "Generating LLVM IR for $SOURCE_FILE..."
  clang -emit-llvm -S -Xclang -disable-O0-optnone "$SOURCE_FILE" -o "$BASENAME.ll" || {
    echo "Error: Failed to generate LLVM IR for $SOURCE_FILE."
    continue
  }

  # Apply your LLVM pass
  echo "Applying LLVM pass to $SOURCE_FILE..."
  opt -S -load-pass-plugin=./build/DeepUnrollPass/DeepUnrollPass.so -passes="deep-unroll" -input-filename="$SOURCE_FILE" "$BASENAME.ll" -o "$BASENAME.optimized.ll" || {
    echo "Error: Failed to apply LLVM pass for $SOURCE_FILE."
    continue
  }

  # Further optimize your pass's output with -O1, -O2, and -O3
  echo "Further optimizing the output of your pass for $SOURCE_FILE..."
  opt -S -O1 "$BASENAME.optimized.ll" -o "$BASENAME.optimized.O1.ll" || echo "Warning: Failed to apply -O1 optimization."
  opt -S -O2 "$BASENAME.optimized.ll" -o "$BASENAME.optimized.O2.ll" || echo "Warning: Failed to apply -O2 optimization."
  opt -S -O3 "$BASENAME.optimized.ll" -o "$BASENAME.optimized.O3.ll" || echo "Warning: Failed to apply -O3 optimization."

  # Compile executables
  echo "Compiling executables for $SOURCE_FILE..."
  clang "$BASENAME.ll" -o "$BASENAME.O0_executable" -O0 || echo "Warning: Failed to compile $BASENAME.O0_executable"
  clang "$BASENAME.ll" -o "$BASENAME.O1_executable" -O1 || echo "Warning: Failed to compile $BASENAME.O1_executable"
  clang "$BASENAME.ll" -o "$BASENAME.O2_executable" -O2 || echo "Warning: Failed to compile $BASENAME.O2_executable"
  clang "$BASENAME.ll" -o "$BASENAME.O3_executable" -O3 || echo "Warning: Failed to compile $BASENAME.O3_executable"
  clang "$BASENAME.optimized.ll" -o "$BASENAME.optimized_executable" || echo "Warning: Failed to compile $BASENAME.optimized_executable"
  clang "$BASENAME.optimized.O1.ll" -o "$BASENAME.optimized.O1_executable" || echo "Warning: Failed to compile $BASENAME.optimized.O1_executable"
  clang "$BASENAME.optimized.O2.ll" -o "$BASENAME.optimized.O2_executable" || echo "Warning: Failed to compile $BASENAME.optimized.O2_executable"
  clang "$BASENAME.optimized.O3.ll" -o "$BASENAME.optimized.O3_executable" || echo "Warning: Failed to compile $BASENAME.optimized.O3_executable"

  # Function to measure execution time
  measure_time() {
    local executable=$1
    local runs=$2
    local total_time=0
    local inner_runs=100  # Number of times the executable runs in each iteration

    # Ensure the file is executable
    if [[ ! -x "$executable" ]]; then
      echo "Warning: $executable is not executable. Attempting to fix..."
      chmod +x "$executable" || {
        echo "Error: Failed to set executable permissions for $executable."
        echo "0"
        return
      }
    fi

    for i in $(seq 1 "$runs"); do
      # Capture the start time in nanoseconds
      start_time=$(date +%s%N)

      # Run the executable multiple times
      for j in $(seq 1 $inner_runs); do
        ./"$executable" > /dev/null 2>&1
      done

      # Capture the end time in nanoseconds
      end_time=$(date +%s%N)

      # Calculate elapsed time in seconds
      elapsed_time_ns=$((end_time - start_time))
      elapsed_time=$(echo "scale=6; $elapsed_time_ns / 1000000000" | bc)

      # Calculate per-run average
      per_run_time=$(echo "scale=6; $elapsed_time / $inner_runs" | bc)
      total_time=$(echo "$total_time + $per_run_time" | bc)
    done

    # Calculate average runtime over all iterations
    avg_time=$(echo "scale=6; $total_time / $runs" | bc)
    echo "$avg_time"
  }

  # Number of runs for each executable
  NUM_RUNS=10

  # Measure execution times
  echo "Measuring execution times for $SOURCE_FILE..."
  declare -A RESULTS

  for OPT in O0 O1 O2 O3 optimized optimized.O1 optimized.O2 optimized.O3; do
    EXECUTABLE="$BASENAME.${OPT}_executable"
    echo "Running $EXECUTABLE..."
    RESULTS[$OPT]=$(measure_time "$EXECUTABLE" $NUM_RUNS)
  done

  # Prepare a CSV row and append to results.csv
  ROW="$SOURCE_FILE"
  for OPT in O0 O1 O2 O3 optimized optimized.O1 optimized.O2 optimized.O3; do
    ROW="$ROW,${RESULTS[$OPT]}"
  done
  echo "$ROW" >> $RESULTS_FILE

  rm *.ll
  rm *_executable

done

echo "Results have been saved to $RESULTS_FILE"
