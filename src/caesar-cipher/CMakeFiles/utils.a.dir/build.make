# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/bin/cmake

# The command to remove a file.
RM = /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/Caesar-Cipher-1-comp-339-439-ds-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/Caesar-Cipher-1-comp-339-439-ds-1

# Include any dependencies generated for this target.
include src/caesar-cipher/CMakeFiles/utils.a.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/caesar-cipher/CMakeFiles/utils.a.dir/compiler_depend.make

# Include the progress variables for this target.
include src/caesar-cipher/CMakeFiles/utils.a.dir/progress.make

# Include the compile flags for this target's objects.
include src/caesar-cipher/CMakeFiles/utils.a.dir/flags.make

src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o: src/caesar-cipher/CMakeFiles/utils.a.dir/flags.make
src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o: src/caesar-cipher/utils.cpp
src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o: src/caesar-cipher/CMakeFiles/utils.a.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o -MF CMakeFiles/utils.a.dir/utils.cpp.o.d -o CMakeFiles/utils.a.dir/utils.cpp.o -c /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/utils.cpp

src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.a.dir/utils.cpp.i"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/utils.cpp > CMakeFiles/utils.a.dir/utils.cpp.i

src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.a.dir/utils.cpp.s"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/utils.cpp -o CMakeFiles/utils.a.dir/utils.cpp.s

# Object files for target utils.a
utils_a_OBJECTS = \
"CMakeFiles/utils.a.dir/utils.cpp.o"

# External object files for target utils.a
utils_a_EXTERNAL_OBJECTS =

src/caesar-cipher/libutils.a.a: src/caesar-cipher/CMakeFiles/utils.a.dir/utils.cpp.o
src/caesar-cipher/libutils.a.a: src/caesar-cipher/CMakeFiles/utils.a.dir/build.make
src/caesar-cipher/libutils.a.a: src/caesar-cipher/CMakeFiles/utils.a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a.a"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && $(CMAKE_COMMAND) -P CMakeFiles/utils.a.dir/cmake_clean_target.cmake
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/caesar-cipher/CMakeFiles/utils.a.dir/build: src/caesar-cipher/libutils.a.a
.PHONY : src/caesar-cipher/CMakeFiles/utils.a.dir/build

src/caesar-cipher/CMakeFiles/utils.a.dir/clean:
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && $(CMAKE_COMMAND) -P CMakeFiles/utils.a.dir/cmake_clean.cmake
.PHONY : src/caesar-cipher/CMakeFiles/utils.a.dir/clean

src/caesar-cipher/CMakeFiles/utils.a.dir/depend:
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/CMakeFiles/utils.a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/caesar-cipher/CMakeFiles/utils.a.dir/depend

