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
include src/CMakeFiles/minijava.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/minijava.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/minijava.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/minijava.dir/flags.make

src/CMakeFiles/minijava.dir/codegen:
.PHONY : src/CMakeFiles/minijava.dir/codegen

src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/accessflag/classAccFlg.cpp
src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o -MF CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o.d -o CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/accessflag/classAccFlg.cpp

src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/accessflag/classAccFlg.cpp > CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.i

src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/accessflag/classAccFlg.cpp -o CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.s

src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/accessflag/fieldAccFlg.cpp
src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o -MF CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o.d -o CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/accessflag/fieldAccFlg.cpp

src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/accessflag/fieldAccFlg.cpp > CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.i

src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/accessflag/fieldAccFlg.cpp -o CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.s

src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/accessflag/methodAccFlg.cpp
src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o -MF CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o.d -o CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/accessflag/methodAccFlg.cpp

src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/accessflag/methodAccFlg.cpp > CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.i

src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/accessflag/methodAccFlg.cpp -o CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.s

src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_info.cpp
src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o -MF CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o.d -o CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_info.cpp

src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/attribute/attribute_info.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_info.cpp > CMakeFiles/minijava.dir/attribute/attribute_info.cpp.i

src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/attribute/attribute_info.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_info.cpp -o CMakeFiles/minijava.dir/attribute/attribute_info.cpp.s

src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_utils.cpp
src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o -MF CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o.d -o CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_utils.cpp

src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_utils.cpp > CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.i

src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/attribute/attribute_utils.cpp -o CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.s

src/CMakeFiles/minijava.dir/classfile.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/classfile.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/classfile.cpp
src/CMakeFiles/minijava.dir/classfile.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/minijava.dir/classfile.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/classfile.cpp.o -MF CMakeFiles/minijava.dir/classfile.cpp.o.d -o CMakeFiles/minijava.dir/classfile.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/classfile.cpp

src/CMakeFiles/minijava.dir/classfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/classfile.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/classfile.cpp > CMakeFiles/minijava.dir/classfile.cpp.i

src/CMakeFiles/minijava.dir/classfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/classfile.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/classfile.cpp -o CMakeFiles/minijava.dir/classfile.cpp.s

src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/constant/cp_info.cpp
src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o -MF CMakeFiles/minijava.dir/constant/cp_info.cpp.o.d -o CMakeFiles/minijava.dir/constant/cp_info.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/constant/cp_info.cpp

src/CMakeFiles/minijava.dir/constant/cp_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/constant/cp_info.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/constant/cp_info.cpp > CMakeFiles/minijava.dir/constant/cp_info.cpp.i

src/CMakeFiles/minijava.dir/constant/cp_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/constant/cp_info.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/constant/cp_info.cpp -o CMakeFiles/minijava.dir/constant/cp_info.cpp.s

src/CMakeFiles/minijava.dir/minijava.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/minijava.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/minijava.cpp
src/CMakeFiles/minijava.dir/minijava.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/minijava.dir/minijava.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/minijava.cpp.o -MF CMakeFiles/minijava.dir/minijava.cpp.o.d -o CMakeFiles/minijava.dir/minijava.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/minijava.cpp

src/CMakeFiles/minijava.dir/minijava.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/minijava.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/minijava.cpp > CMakeFiles/minijava.dir/minijava.cpp.i

src/CMakeFiles/minijava.dir/minijava.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/minijava.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/minijava.cpp -o CMakeFiles/minijava.dir/minijava.cpp.s

src/CMakeFiles/minijava.dir/parser.cpp.o: src/CMakeFiles/minijava.dir/flags.make
src/CMakeFiles/minijava.dir/parser.cpp.o: /Users/catkin/workspace/hygon/minijiva/src/parser.cpp
src/CMakeFiles/minijava.dir/parser.cpp.o: src/CMakeFiles/minijava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/minijava.dir/parser.cpp.o"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minijava.dir/parser.cpp.o -MF CMakeFiles/minijava.dir/parser.cpp.o.d -o CMakeFiles/minijava.dir/parser.cpp.o -c /Users/catkin/workspace/hygon/minijiva/src/parser.cpp

src/CMakeFiles/minijava.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minijava.dir/parser.cpp.i"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/catkin/workspace/hygon/minijiva/src/parser.cpp > CMakeFiles/minijava.dir/parser.cpp.i

src/CMakeFiles/minijava.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minijava.dir/parser.cpp.s"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/catkin/workspace/hygon/minijiva/src/parser.cpp -o CMakeFiles/minijava.dir/parser.cpp.s

# Object files for target minijava
minijava_OBJECTS = \
"CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o" \
"CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o" \
"CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o" \
"CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o" \
"CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o" \
"CMakeFiles/minijava.dir/classfile.cpp.o" \
"CMakeFiles/minijava.dir/constant/cp_info.cpp.o" \
"CMakeFiles/minijava.dir/minijava.cpp.o" \
"CMakeFiles/minijava.dir/parser.cpp.o"

# External object files for target minijava
minijava_EXTERNAL_OBJECTS = \
"/Users/catkin/workspace/hygon/minijiva/build/src/accessflag/CMakeFiles/accessflag.dir/classAccFlg.cpp.o" \
"/Users/catkin/workspace/hygon/minijiva/build/src/accessflag/CMakeFiles/accessflag.dir/fieldAccFlg.cpp.o" \
"/Users/catkin/workspace/hygon/minijiva/build/src/accessflag/CMakeFiles/accessflag.dir/methodAccFlg.cpp.o" \
"/Users/catkin/workspace/hygon/minijiva/build/src/constant/CMakeFiles/constant.dir/cp_info.cpp.o" \
"/Users/catkin/workspace/hygon/minijiva/build/src/attribute/CMakeFiles/attribute.dir/attribute_info.cpp.o" \
"/Users/catkin/workspace/hygon/minijiva/build/src/attribute/CMakeFiles/attribute.dir/attribute_utils.cpp.o"

lib/libminijava.a: src/CMakeFiles/minijava.dir/accessflag/classAccFlg.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/accessflag/fieldAccFlg.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/accessflag/methodAccFlg.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/attribute/attribute_info.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/attribute/attribute_utils.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/classfile.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/constant/cp_info.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/minijava.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/parser.cpp.o
lib/libminijava.a: src/accessflag/CMakeFiles/accessflag.dir/classAccFlg.cpp.o
lib/libminijava.a: src/accessflag/CMakeFiles/accessflag.dir/fieldAccFlg.cpp.o
lib/libminijava.a: src/accessflag/CMakeFiles/accessflag.dir/methodAccFlg.cpp.o
lib/libminijava.a: src/constant/CMakeFiles/constant.dir/cp_info.cpp.o
lib/libminijava.a: src/attribute/CMakeFiles/attribute.dir/attribute_info.cpp.o
lib/libminijava.a: src/attribute/CMakeFiles/attribute.dir/attribute_utils.cpp.o
lib/libminijava.a: src/CMakeFiles/minijava.dir/build.make
lib/libminijava.a: src/CMakeFiles/minijava.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/catkin/workspace/hygon/minijiva/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library ../lib/libminijava.a"
	cd /Users/catkin/workspace/hygon/minijiva/build/src && $(CMAKE_COMMAND) -P CMakeFiles/minijava.dir/cmake_clean_target.cmake
	cd /Users/catkin/workspace/hygon/minijiva/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minijava.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/minijava.dir/build: lib/libminijava.a
.PHONY : src/CMakeFiles/minijava.dir/build

src/CMakeFiles/minijava.dir/clean:
	cd /Users/catkin/workspace/hygon/minijiva/build/src && $(CMAKE_COMMAND) -P CMakeFiles/minijava.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/minijava.dir/clean

src/CMakeFiles/minijava.dir/depend:
	cd /Users/catkin/workspace/hygon/minijiva/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/catkin/workspace/hygon/minijiva /Users/catkin/workspace/hygon/minijiva/src /Users/catkin/workspace/hygon/minijiva/build /Users/catkin/workspace/hygon/minijiva/build/src /Users/catkin/workspace/hygon/minijiva/build/src/CMakeFiles/minijava.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/minijava.dir/depend

