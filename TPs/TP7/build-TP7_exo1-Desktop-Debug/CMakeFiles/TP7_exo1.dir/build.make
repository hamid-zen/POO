# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/hzenine/OOP/TP7/TP7_exo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/TP7_exo1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP7_exo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP7_exo1.dir/flags.make

CMakeFiles/TP7_exo1.dir/main.cpp.o: CMakeFiles/TP7_exo1.dir/flags.make
CMakeFiles/TP7_exo1.dir/main.cpp.o: /home/hzenine/OOP/TP7/TP7_exo1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP7_exo1.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP7_exo1.dir/main.cpp.o -c /home/hzenine/OOP/TP7/TP7_exo1/main.cpp

CMakeFiles/TP7_exo1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP7_exo1.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hzenine/OOP/TP7/TP7_exo1/main.cpp > CMakeFiles/TP7_exo1.dir/main.cpp.i

CMakeFiles/TP7_exo1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP7_exo1.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hzenine/OOP/TP7/TP7_exo1/main.cpp -o CMakeFiles/TP7_exo1.dir/main.cpp.s

# Object files for target TP7_exo1
TP7_exo1_OBJECTS = \
"CMakeFiles/TP7_exo1.dir/main.cpp.o"

# External object files for target TP7_exo1
TP7_exo1_EXTERNAL_OBJECTS =

TP7_exo1: CMakeFiles/TP7_exo1.dir/main.cpp.o
TP7_exo1: CMakeFiles/TP7_exo1.dir/build.make
TP7_exo1: CMakeFiles/TP7_exo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP7_exo1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP7_exo1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP7_exo1.dir/build: TP7_exo1

.PHONY : CMakeFiles/TP7_exo1.dir/build

CMakeFiles/TP7_exo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP7_exo1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP7_exo1.dir/clean

CMakeFiles/TP7_exo1.dir/depend:
	cd /home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hzenine/OOP/TP7/TP7_exo1 /home/hzenine/OOP/TP7/TP7_exo1 /home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug /home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug /home/hzenine/OOP/TP7/build-TP7_exo1-Desktop-Debug/CMakeFiles/TP7_exo1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP7_exo1.dir/depend
