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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /lhome/micmink/Tools/home_iot/cpp_stuff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /lhome/micmink/Tools/home_iot/cpp_stuff/build

# Include any dependencies generated for this target.
include CMakeFiles/tmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tmp.dir/flags.make

CMakeFiles/tmp.dir/main.cpp.o: CMakeFiles/tmp.dir/flags.make
CMakeFiles/tmp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lhome/micmink/Tools/home_iot/cpp_stuff/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tmp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tmp.dir/main.cpp.o -c /lhome/micmink/Tools/home_iot/cpp_stuff/main.cpp

CMakeFiles/tmp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tmp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lhome/micmink/Tools/home_iot/cpp_stuff/main.cpp > CMakeFiles/tmp.dir/main.cpp.i

CMakeFiles/tmp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tmp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lhome/micmink/Tools/home_iot/cpp_stuff/main.cpp -o CMakeFiles/tmp.dir/main.cpp.s

# Object files for target tmp
tmp_OBJECTS = \
"CMakeFiles/tmp.dir/main.cpp.o"

# External object files for target tmp
tmp_EXTERNAL_OBJECTS =

tmp: CMakeFiles/tmp.dir/main.cpp.o
tmp: CMakeFiles/tmp.dir/build.make
tmp: CMakeFiles/tmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/lhome/micmink/Tools/home_iot/cpp_stuff/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tmp.dir/build: tmp

.PHONY : CMakeFiles/tmp.dir/build

CMakeFiles/tmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tmp.dir/clean

CMakeFiles/tmp.dir/depend:
	cd /lhome/micmink/Tools/home_iot/cpp_stuff/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /lhome/micmink/Tools/home_iot/cpp_stuff /lhome/micmink/Tools/home_iot/cpp_stuff /lhome/micmink/Tools/home_iot/cpp_stuff/build /lhome/micmink/Tools/home_iot/cpp_stuff/build /lhome/micmink/Tools/home_iot/cpp_stuff/build/CMakeFiles/tmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tmp.dir/depend

