# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/catkin/workspace/hygon/minijiva

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/catkin/workspace/hygon/minijiva/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_parser_split.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_parser_split.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_parser_split.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_parser_split.dir/flags.make

test/CMakeFiles/test_parser_split.dir/codegen:
.PHONY : test/CMakeFiles/test_parser_split.dir/codegen

test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o: test/CMakeFiles/test_parser_split.dir/flags.make
test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o: /Users/catkin/workspace/hygon/minijiva/test/test_parser_split.cpp
test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o: test/CMakeFiles/test_parser_split.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o -MF CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o.d -o CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o -c /Users/catkin/workspace/hygon/minijiva/test/test_parser_split.cpp

test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_parser_split.dir/test_parser_split.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/test/test_parser_split.cpp > CMakeFiles/test_parser_split.dir/test_parser_split.cpp.i

test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_parser_split.dir/test_parser_split.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/test/test_parser_split.cpp -o CMakeFiles/test_parser_split.dir/test_parser_split.cpp.s

# Object files for target test_parser_split
test_parser_split_OBJECTS = \
"CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o"

# External object files for target test_parser_split
test_parser_split_EXTERNAL_OBJECTS =

test/test_parser_split: test/CMakeFiles/test_parser_split.dir/test_parser_split.cpp.o
test/test_parser_split: test/CMakeFiles/test_parser_split.dir/build.make
test/test_parser_split: lib/libminijava.a
test/test_parser_split: lib/libgtest.a
test/test_parser_split: lib/libattribute.a
test/test_parser_split: test/CMakeFiles/test_parser_split.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_parser_split"
	cd /Users/catkin/workspace/hygon/minijiva/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_parser_split.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/catkin/workspace/hygon/minijiva/build/test && /opt/homebrew/bin/cmake -D TEST_TARGET=test_parser_split -D TEST_EXECUTABLE=/Users/catkin/workspace/hygon/minijiva/build/test/test_parser_split -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/catkin/workspace/hygon/minijiva/build/test -D "TEST_EXTRA_ARGS=--gtest_output=xml:/Users/catkin/workspace/hygon/minijiva/build/test/test_parser_split.xml;--gtest_catch_exceptions=0" -D "TEST_PROPERTIES=TIMEOUT;120" -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_parser_split_TESTS -D CTEST_FILE=/Users/catkin/workspace/hygon/minijiva/build/test/test_parser_split[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=120 -D TEST_DISCOVERY_EXTRA_ARGS= -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/test_parser_split.dir/build: test/test_parser_split
.PHONY : test/CMakeFiles/test_parser_split.dir/build

test/CMakeFiles/test_parser_split.dir/clean:
	cd /Users/catkin/workspace/hygon/minijiva/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_parser_split.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_parser_split.dir/clean

test/CMakeFiles/test_parser_split.dir/depend:
	cd /Users/catkin/workspace/hygon/minijiva/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/catkin/workspace/hygon/minijiva /Users/catkin/workspace/hygon/minijiva/test /Users/catkin/workspace/hygon/minijiva/build /Users/catkin/workspace/hygon/minijiva/build/test /Users/catkin/workspace/hygon/minijiva/build/test/CMakeFiles/test_parser_split.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/test_parser_split.dir/depend

