# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build

# Include any dependencies generated for this target.
include DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/compiler_depend.make

# Include the progress variables for this target.
include DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/progress.make

# Include the compile flags for this target's objects.
include DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/flags.make

DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o: DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/flags.make
DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o: ../DeepUnrollPass/Pass.cpp
DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o: DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o"
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o -MF CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o.d -o CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o -c /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/DeepUnrollPass/Pass.cpp

DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeepUnrollPass.dir/Pass.cpp.i"
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/DeepUnrollPass/Pass.cpp > CMakeFiles/DeepUnrollPass.dir/Pass.cpp.i

DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeepUnrollPass.dir/Pass.cpp.s"
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/DeepUnrollPass/Pass.cpp -o CMakeFiles/DeepUnrollPass.dir/Pass.cpp.s

# Object files for target DeepUnrollPass
DeepUnrollPass_OBJECTS = \
"CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o"

# External object files for target DeepUnrollPass
DeepUnrollPass_EXTERNAL_OBJECTS =

DeepUnrollPass/DeepUnrollPass.so: DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/Pass.cpp.o
DeepUnrollPass/DeepUnrollPass.so: DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/build.make
DeepUnrollPass/DeepUnrollPass.so: DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module DeepUnrollPass.so"
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeepUnrollPass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/build: DeepUnrollPass/DeepUnrollPass.so
.PHONY : DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/build

DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/clean:
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass && $(CMAKE_COMMAND) -P CMakeFiles/DeepUnrollPass.dir/cmake_clean.cmake
.PHONY : DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/clean

DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/depend:
	cd /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/DeepUnrollPass /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass /n/eecs583a/home/andrenan/DeepUnroll/DeepUnrollFunction/build/DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DeepUnrollPass/CMakeFiles/DeepUnrollPass.dir/depend
