# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/manuel/development/cavestory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manuel/development/cavestory/build

# Include any dependencies generated for this target.
include CMakeFiles/cavestory2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cavestory2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cavestory2.dir/flags.make

CMakeFiles/cavestory2.dir/src/game.cc.o: CMakeFiles/cavestory2.dir/flags.make
CMakeFiles/cavestory2.dir/src/game.cc.o: ../src/game.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/development/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cavestory2.dir/src/game.cc.o"
	/usr/bin/clang++-3.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cavestory2.dir/src/game.cc.o -c /home/manuel/development/cavestory/src/game.cc

CMakeFiles/cavestory2.dir/src/game.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cavestory2.dir/src/game.cc.i"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/development/cavestory/src/game.cc > CMakeFiles/cavestory2.dir/src/game.cc.i

CMakeFiles/cavestory2.dir/src/game.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cavestory2.dir/src/game.cc.s"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/development/cavestory/src/game.cc -o CMakeFiles/cavestory2.dir/src/game.cc.s

CMakeFiles/cavestory2.dir/src/graphics.cc.o: CMakeFiles/cavestory2.dir/flags.make
CMakeFiles/cavestory2.dir/src/graphics.cc.o: ../src/graphics.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/development/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cavestory2.dir/src/graphics.cc.o"
	/usr/bin/clang++-3.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cavestory2.dir/src/graphics.cc.o -c /home/manuel/development/cavestory/src/graphics.cc

CMakeFiles/cavestory2.dir/src/graphics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cavestory2.dir/src/graphics.cc.i"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/development/cavestory/src/graphics.cc > CMakeFiles/cavestory2.dir/src/graphics.cc.i

CMakeFiles/cavestory2.dir/src/graphics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cavestory2.dir/src/graphics.cc.s"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/development/cavestory/src/graphics.cc -o CMakeFiles/cavestory2.dir/src/graphics.cc.s

CMakeFiles/cavestory2.dir/src/input.cc.o: CMakeFiles/cavestory2.dir/flags.make
CMakeFiles/cavestory2.dir/src/input.cc.o: ../src/input.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/development/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cavestory2.dir/src/input.cc.o"
	/usr/bin/clang++-3.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cavestory2.dir/src/input.cc.o -c /home/manuel/development/cavestory/src/input.cc

CMakeFiles/cavestory2.dir/src/input.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cavestory2.dir/src/input.cc.i"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/development/cavestory/src/input.cc > CMakeFiles/cavestory2.dir/src/input.cc.i

CMakeFiles/cavestory2.dir/src/input.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cavestory2.dir/src/input.cc.s"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/development/cavestory/src/input.cc -o CMakeFiles/cavestory2.dir/src/input.cc.s

CMakeFiles/cavestory2.dir/src/main.cc.o: CMakeFiles/cavestory2.dir/flags.make
CMakeFiles/cavestory2.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/development/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cavestory2.dir/src/main.cc.o"
	/usr/bin/clang++-3.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cavestory2.dir/src/main.cc.o -c /home/manuel/development/cavestory/src/main.cc

CMakeFiles/cavestory2.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cavestory2.dir/src/main.cc.i"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/development/cavestory/src/main.cc > CMakeFiles/cavestory2.dir/src/main.cc.i

CMakeFiles/cavestory2.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cavestory2.dir/src/main.cc.s"
	/usr/bin/clang++-3.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/development/cavestory/src/main.cc -o CMakeFiles/cavestory2.dir/src/main.cc.s

# Object files for target cavestory2
cavestory2_OBJECTS = \
"CMakeFiles/cavestory2.dir/src/game.cc.o" \
"CMakeFiles/cavestory2.dir/src/graphics.cc.o" \
"CMakeFiles/cavestory2.dir/src/input.cc.o" \
"CMakeFiles/cavestory2.dir/src/main.cc.o"

# External object files for target cavestory2
cavestory2_EXTERNAL_OBJECTS =

cavestory2: CMakeFiles/cavestory2.dir/src/game.cc.o
cavestory2: CMakeFiles/cavestory2.dir/src/graphics.cc.o
cavestory2: CMakeFiles/cavestory2.dir/src/input.cc.o
cavestory2: CMakeFiles/cavestory2.dir/src/main.cc.o
cavestory2: CMakeFiles/cavestory2.dir/build.make
cavestory2: CMakeFiles/cavestory2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manuel/development/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable cavestory2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cavestory2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cavestory2.dir/build: cavestory2

.PHONY : CMakeFiles/cavestory2.dir/build

CMakeFiles/cavestory2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cavestory2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cavestory2.dir/clean

CMakeFiles/cavestory2.dir/depend:
	cd /home/manuel/development/cavestory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manuel/development/cavestory /home/manuel/development/cavestory /home/manuel/development/cavestory/build /home/manuel/development/cavestory/build /home/manuel/development/cavestory/build/CMakeFiles/cavestory2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cavestory2.dir/depend

