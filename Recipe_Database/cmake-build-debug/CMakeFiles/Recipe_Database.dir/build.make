# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Recipe_Database.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Recipe_Database.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Recipe_Database.dir/flags.make

CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o: CMakeFiles/Recipe_Database.dir/flags.make
CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o: ../Recipe_Database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o   -c "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Recipe_Database.c"

CMakeFiles/Recipe_Database.dir/Recipe_Database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Recipe_Database.dir/Recipe_Database.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Recipe_Database.c" > CMakeFiles/Recipe_Database.dir/Recipe_Database.c.i

CMakeFiles/Recipe_Database.dir/Recipe_Database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Recipe_Database.dir/Recipe_Database.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Recipe_Database.c" -o CMakeFiles/Recipe_Database.dir/Recipe_Database.c.s

CMakeFiles/Recipe_Database.dir/Database_Functions.c.o: CMakeFiles/Recipe_Database.dir/flags.make
CMakeFiles/Recipe_Database.dir/Database_Functions.c.o: ../Database_Functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Recipe_Database.dir/Database_Functions.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Recipe_Database.dir/Database_Functions.c.o   -c "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Database_Functions.c"

CMakeFiles/Recipe_Database.dir/Database_Functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Recipe_Database.dir/Database_Functions.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Database_Functions.c" > CMakeFiles/Recipe_Database.dir/Database_Functions.c.i

CMakeFiles/Recipe_Database.dir/Database_Functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Recipe_Database.dir/Database_Functions.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/Database_Functions.c" -o CMakeFiles/Recipe_Database.dir/Database_Functions.c.s

# Object files for target Recipe_Database
Recipe_Database_OBJECTS = \
"CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o" \
"CMakeFiles/Recipe_Database.dir/Database_Functions.c.o"

# External object files for target Recipe_Database
Recipe_Database_EXTERNAL_OBJECTS =

Recipe_Database: CMakeFiles/Recipe_Database.dir/Recipe_Database.c.o
Recipe_Database: CMakeFiles/Recipe_Database.dir/Database_Functions.c.o
Recipe_Database: CMakeFiles/Recipe_Database.dir/build.make
Recipe_Database: CMakeFiles/Recipe_Database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Recipe_Database"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Recipe_Database.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Recipe_Database.dir/build: Recipe_Database

.PHONY : CMakeFiles/Recipe_Database.dir/build

CMakeFiles/Recipe_Database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Recipe_Database.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Recipe_Database.dir/clean

CMakeFiles/Recipe_Database.dir/depend:
	cd "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database" "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database" "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug" "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug" "/Users/ezanakebede/Documents/School/Semesters/2 Spring 2021/ENEE150/CLionProjects/Recipe_Database/cmake-build-debug/CMakeFiles/Recipe_Database.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Recipe_Database.dir/depend
