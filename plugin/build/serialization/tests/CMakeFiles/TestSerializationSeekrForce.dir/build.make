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
CMAKE_SOURCE_DIR = /home/astokely/SEEKR/openseekr/plugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/astokely/SEEKR/openseekr/plugin/build

# Include any dependencies generated for this target.
include serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/depend.make

# Include the progress variables for this target.
include serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/progress.make

# Include the compile flags for this target's objects.
include serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/flags.make

serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o: serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/flags.make
serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o: ../serialization/tests/TestSerializationSeekrForce.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/astokely/SEEKR/openseekr/plugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o"
	cd /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o -c /home/astokely/SEEKR/openseekr/plugin/serialization/tests/TestSerializationSeekrForce.cpp

serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.i"
	cd /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/astokely/SEEKR/openseekr/plugin/serialization/tests/TestSerializationSeekrForce.cpp > CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.i

serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.s"
	cd /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/astokely/SEEKR/openseekr/plugin/serialization/tests/TestSerializationSeekrForce.cpp -o CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.s

# Object files for target TestSerializationSeekrForce
TestSerializationSeekrForce_OBJECTS = \
"CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o"

# External object files for target TestSerializationSeekrForce
TestSerializationSeekrForce_EXTERNAL_OBJECTS =

serialization/tests/TestSerializationSeekrForce: serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/TestSerializationSeekrForce.cpp.o
serialization/tests/TestSerializationSeekrForce: serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/build.make
serialization/tests/TestSerializationSeekrForce: libSeekrPlugin.so
serialization/tests/TestSerializationSeekrForce: serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/astokely/SEEKR/openseekr/plugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSerializationSeekrForce"
	cd /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSerializationSeekrForce.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/build: serialization/tests/TestSerializationSeekrForce

.PHONY : serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/build

serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/clean:
	cd /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestSerializationSeekrForce.dir/cmake_clean.cmake
.PHONY : serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/clean

serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/depend:
	cd /home/astokely/SEEKR/openseekr/plugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/astokely/SEEKR/openseekr/plugin /home/astokely/SEEKR/openseekr/plugin/serialization/tests /home/astokely/SEEKR/openseekr/plugin/build /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests /home/astokely/SEEKR/openseekr/plugin/build/serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serialization/tests/CMakeFiles/TestSerializationSeekrForce.dir/depend

