#!/bin/bash

#TODO CHANGE INPUT FILE IN process_txt_to_csv.py
python3 process_txt_to_csv.py

awk -F, '{
    # Extract only the filename from the first column
    sub(".*/", "", $1);
    # Reconstruct and print the entire line
    print $1 FS $2 FS $3;
}' LoopUnrollFunction_output.csv > LoopUnrollFunction_parsed.csv

#TODO CHANGE DIRECTORY OF CODE
for file in LoopUnrollFunction/Radhika/*.c; do
    clang -emit-llvm -S -Xclang -disable-O0-optnone "$file" -o "${file%.c}.ll"
    opt -disable-output -load-pass-plugin=./GatherDataFunction/build/GatherDataFunctionPass/GatherDataFunctionPass.so -passes="loop-info" -input-file="$file" "${file%.c}.ll"
done

awk -F, '{
    # Extract only the filename from the first column
    sub(".*/", "", $1);
    # Print the updated line
    print $1 FS $2 FS $3 FS $4 FS $5 FS $6 FS $7 FS $8 FS $9 FS $10 FS $11 FS $12 FS $13 FS $14 FS $15;
}' output.csv > output_parsed.csv

awk -F, 'NR==FNR {
    # For each row in output_2, use the first two columns as the key and store the whole row
    key = $1 "," $2;
    output_2[key] = $0;
    next
}
{
    key = $1 "," $2;  # Create a key from the first two columns of file1
    if (key in output_2) {
        # Extract the last column of the current row in file1
        last_col = $NF;

        # Print the first two columns of file1, all of output_2, and the last column of file1
        print $1 "," $2 "," output_2[key] "," last_col;
    }
}' output_parsed.csv LoopUnrollFunction_parsed.csv > data.csv