input_file = "LoopUnrollFunction/Radhika_output.txt"   # Replace with your input .txt file name
output_file = "LoopUnrollFunction_output.csv"  # Replace with your desired output .csv file name

# Open the input and output files
with open(input_file, "r") as infile, open(output_file, "w") as outfile:
    current_file = None
    index = 1  # Row index for numbers
    
    for line in infile:
        line = line.strip()  # Remove leading/trailing whitespace
        
        if line == "skipped" or not line:  # Ignore 'skipped' or empty lines
            continue
        
        if line.endswith(".c"):  # Found a file
            current_file = line  # Update current filename
            index = 1  # Reset index
        elif current_file and line.isdigit():  # Found a number after a filename
            outfile.write(f"{current_file},{index},{line}\n")  # Write row
            index += 1  # Increment index