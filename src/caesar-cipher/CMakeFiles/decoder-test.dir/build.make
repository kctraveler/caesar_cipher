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
include src/caesar-cipher/CMakeFiles/decoder-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/caesar-cipher/CMakeFiles/decoder-test.dir/compiler_depend.make

# Include the progress variables for this target.
include src/caesar-cipher/CMakeFiles/decoder-test.dir/progress.make

# Include the compile flags for this target's objects.
include src/caesar-cipher/CMakeFiles/decoder-test.dir/flags.make

src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o: src/caesar-cipher/CMakeFiles/decoder-test.dir/flags.make
src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o: src/caesar-cipher/decoder-test.cpp
src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o: src/caesar-cipher/CMakeFiles/decoder-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o -MF CMakeFiles/decoder-test.dir/decoder-test.cpp.o.d -o CMakeFiles/decoder-test.dir/decoder-test.cpp.o -c /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/decoder-test.cpp

src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/decoder-test.dir/decoder-test.cpp.i"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/decoder-test.cpp > CMakeFiles/decoder-test.dir/decoder-test.cpp.i

src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/decoder-test.dir/decoder-test.cpp.s"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/4xs1xyj8728yvh9y5v6ji819kwgfy2fv-gcc-wrapper-10.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/decoder-test.cpp -o CMakeFiles/decoder-test.dir/decoder-test.cpp.s

# Object files for target decoder-test
decoder__test_OBJECTS = \
"CMakeFiles/decoder-test.dir/decoder-test.cpp.o"

# External object files for target decoder-test
decoder__test_EXTERNAL_OBJECTS =

bin/decoder-test: src/caesar-cipher/CMakeFiles/decoder-test.dir/decoder-test.cpp.o
bin/decoder-test: src/caesar-cipher/CMakeFiles/decoder-test.dir/build.make
bin/decoder-test: lib/libgtest_main.a
bin/decoder-test: src/caesar-cipher/libdecoder.a.a
bin/decoder-test: src/caesar-cipher/libutils.a.a
bin/decoder-test: lib/libgtest.a
bin/decoder-test: src/caesar-cipher/CMakeFiles/decoder-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/decoder-test"
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decoder-test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/bin/cmake -D TEST_TARGET=decoder-test -D TEST_EXECUTABLE=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/bin/decoder-test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=decoder-test_TESTS -D CTEST_FILE=/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/decoder-test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/share/cmake-3.24/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
src/caesar-cipher/CMakeFiles/decoder-test.dir/build: bin/decoder-test
.PHONY : src/caesar-cipher/CMakeFiles/decoder-test.dir/build

src/caesar-cipher/CMakeFiles/decoder-test.dir/clean:
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher && $(CMAKE_COMMAND) -P CMakeFiles/decoder-test.dir/cmake_clean.cmake
.PHONY : src/caesar-cipher/CMakeFiles/decoder-test.dir/clean

src/caesar-cipher/CMakeFiles/decoder-test.dir/depend:
	cd /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher /home/runner/Caesar-Cipher-1-comp-339-439-ds-1 /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher /home/runner/Caesar-Cipher-1-comp-339-439-ds-1/src/caesar-cipher/CMakeFiles/decoder-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/caesar-cipher/CMakeFiles/decoder-test.dir/depend

