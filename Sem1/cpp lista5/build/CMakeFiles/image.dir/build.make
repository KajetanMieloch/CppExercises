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
CMAKE_SOURCE_DIR = "/home/s339562/Pulpit/Semestr2/cpp lista5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/s339562/Pulpit/Semestr2/cpp lista5/build"

# Include any dependencies generated for this target.
include CMakeFiles/image.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image.dir/flags.make

CMakeFiles/image.dir/main.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/main.cpp.o: ../main.cpp
CMakeFiles/image.dir/main.cpp.o: CMakeFiles/image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/s339562/Pulpit/Semestr2/cpp lista5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image.dir/main.cpp.o -MF CMakeFiles/image.dir/main.cpp.o.d -o CMakeFiles/image.dir/main.cpp.o -c "/home/s339562/Pulpit/Semestr2/cpp lista5/main.cpp"

CMakeFiles/image.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/s339562/Pulpit/Semestr2/cpp lista5/main.cpp" > CMakeFiles/image.dir/main.cpp.i

CMakeFiles/image.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/s339562/Pulpit/Semestr2/cpp lista5/main.cpp" -o CMakeFiles/image.dir/main.cpp.s

CMakeFiles/image.dir/image.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/image.cpp.o: ../image.cpp
CMakeFiles/image.dir/image.cpp.o: CMakeFiles/image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/s339562/Pulpit/Semestr2/cpp lista5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image.dir/image.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image.dir/image.cpp.o -MF CMakeFiles/image.dir/image.cpp.o.d -o CMakeFiles/image.dir/image.cpp.o -c "/home/s339562/Pulpit/Semestr2/cpp lista5/image.cpp"

CMakeFiles/image.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/image.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/s339562/Pulpit/Semestr2/cpp lista5/image.cpp" > CMakeFiles/image.dir/image.cpp.i

CMakeFiles/image.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/image.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/s339562/Pulpit/Semestr2/cpp lista5/image.cpp" -o CMakeFiles/image.dir/image.cpp.s

# Object files for target image
image_OBJECTS = \
"CMakeFiles/image.dir/main.cpp.o" \
"CMakeFiles/image.dir/image.cpp.o"

# External object files for target image
image_EXTERNAL_OBJECTS =

image: CMakeFiles/image.dir/main.cpp.o
image: CMakeFiles/image.dir/image.cpp.o
image: CMakeFiles/image.dir/build.make
image: CMakeFiles/image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/s339562/Pulpit/Semestr2/cpp lista5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable image"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image.dir/build: image
.PHONY : CMakeFiles/image.dir/build

CMakeFiles/image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image.dir/clean

CMakeFiles/image.dir/depend:
	cd "/home/s339562/Pulpit/Semestr2/cpp lista5/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/s339562/Pulpit/Semestr2/cpp lista5" "/home/s339562/Pulpit/Semestr2/cpp lista5" "/home/s339562/Pulpit/Semestr2/cpp lista5/build" "/home/s339562/Pulpit/Semestr2/cpp lista5/build" "/home/s339562/Pulpit/Semestr2/cpp lista5/build/CMakeFiles/image.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/image.dir/depend
