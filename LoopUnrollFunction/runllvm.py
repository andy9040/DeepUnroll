import llvmlite.binding as llvm
import os

# Initialize the LLVM JIT compiler
llvm.initialize()
llvm.initialize_native_target()
llvm.initialize_native_asmprinter()

# Load the LLVM IR code from the file
with open("unrolled_factor_1.ll", "r") as f:
    llvm_ir = f.read()

# Parse the LLVM IR code
try:
    mod = llvm.parse_assembly(llvm_ir)
    mod.verify()
except RuntimeError as e:
    print(f"Error parsing LLVM IR: {e}")
    exit(1)

# Create an execution engine
target_machine = llvm.Target.from_default_triple().create_target_machine()
backing_mod = llvm.create_mcjit_compiler(mod, target_machine)

# Finalize the module (required for MCJIT)
backing_mod.finalize_object()
backing_mod.run_static_constructors()

# Lookup the function to execute
func_name = "main"  # Change this to the entry function of your LLVM IR code
func_ptr = backing_mod.get_function_address(func_name)

# Create a Python callable from the function pointer
from ctypes import CFUNCTYPE, c_int

main_func = CFUNCTYPE(c_int)(func_ptr)

# Call the function
result = main_func()
print(f"Result of `{func_name}`: {result}")

# Run static destructors
backing_mod.run_static_destructors()
