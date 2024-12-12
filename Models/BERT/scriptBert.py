import os
import sys
import pandas as pd
import torch
from transformers import BertTokenizer, BertForSequenceClassification
from pycparser import c_parser, c_ast

#Way to complete loop traversals
class LoopVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.allLoops = []

    def visit_For(self, node):
        self.allLoops.append(node)
        self.generic_visit(node)

    def visit_While(self, node):
        self.allLoops.append(node)
        self.generic_visit(node)

    def visit_DoWhile(self, node):
        self.allLoops.append(node)
        self.generic_visit(node)

#clean the file (remove comments and directives)
def remove_directives_and_comments(input_file, output_file):
    #read "dirty" version
    with open(input_file, "r") as infile:
        lines = infile.readlines()

    filtered_lines = []
    for line in lines:
        stripped_line = line.strip()
        
        #remove directives
        if stripped_line.startswith("#"):
            continue
        
        #remove comments
        if "//" in line:
            line = line.split("//")[0].rstrip()
        if line.strip():
            filtered_lines.append(line + "\n")

    #output new version
    with open(output_file, "w") as outfile:
        outfile.writelines(filtered_lines)

#get loops from the AST
def extract_loops_from_ast(ast):
    visitor = LoopVisitor()
    visitor.visit(ast)
    return visitor.allLoops

#serailize the AST
def serialize_file_ast(node):
    tokens = []

    def visit(node):
        if isinstance(node, c_ast.Node):
            tokens.append(type(node).__name__)
            for _, child in node.children():
                visit(child)
        elif isinstance(node, list):
            for item in node:
                visit(item)

    visit(node)
    return tokens


#process the csv file passed in
def process_dataset(file_path):
    df = pd.read_csv(file_path, delimiter=",", header=None)
    df = df.iloc[1:]

    df.drop(columns=[0, 12], inplace=True)

    block_frequencies = df.iloc[:, 12].apply(lambda x: ", ".join(map(str, x.split(";"))))
    branch_probabilities = df.iloc[:, 13].apply(lambda x: ", ".join(map(str, x.split(";"))))
    ast_column = df.iloc[:, -1]

    # convert the numeric inputs into text format suitable for BERT's tokenizer

    df["Text"] = df.apply(lambda row: (
        f"Depth: {row[2]}; Basic Blocks: {row[3]}; Total Instructions: {row[4]}; "
        f"Memory Operations: {row[5]}; Branches: {row[6]}; PHI Nodes: {row[7]}; "
        f"Flow Dependencies: {row[8]}; Anti Dependencies: {row[9]}; Output Dependencies: {row[10]}; "
        f"Input Dependencies: {row[11]}; Block Frequencies: {block_frequencies[row.name]}; "
        f"Branch Probabilities: {branch_probabilities[row.name]}; AST: {ast_column[row.name]}."
    ), axis=1)

    return df["Text"].tolist()


#main driver - needs .c file and and csv file with it's charateristics
def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <c_file> <csv_file>")
        sys.exit(1)

    c_file = sys.argv[1]
    csv_file = sys.argv[2]

    #store cleaned version of file
    processed_c_file = "processed.c"
    remove_directives_and_comments(c_file, processed_c_file)

    # access cleaned file
    with open(processed_c_file, "r") as file:
        text = file.read()

    #generate parster to create AST
    parser = c_parser.CParser()
    try:
        ast = parser.parse(text)
    except Exception as e:
        print(f"Error parsing C file: {e}")
        sys.exit(1)

    #get loops from AST and serialize them
    loops = extract_loops_from_ast(ast)
    serialized_loops = [serialize_file_ast(loop) for loop in loops]

    df = pd.read_csv(csv_file, header=None)
    for index, row in df.iterrows():
        df.at[index, "AST"] = str(serialized_loops[row[df.columns[1]]])

    output_csv = "ast.csv"
    df.to_csv(output_csv, index=False)

    #process csv data
    texts = process_dataset(output_csv)

    #train BERT 
    model_dir = "./trained_model"
    tokenizer = BertTokenizer.from_pretrained(model_dir)
    model = BertForSequenceClassification.from_pretrained(model_dir)
    model.eval()

    encodings = tokenizer(texts, truncation=True, padding=True, max_length=512, return_tensors="pt")
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model.to(device)
    encodings = {k: v.to(device) for k, v in encodings.items()}

    with torch.no_grad():
        outputs = model(**encodings)
        predictions = outputs.logits.argmax(dim=1).cpu().numpy() + 1

    print(predictions[0])

if __name__ == "__main__":
    main()
