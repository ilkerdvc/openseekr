# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lvotapka/openseekr/plugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lvotapka/openseekr/plugin/build

# Utility rule file for PythonInstall.

# Include the progress variables for this target.
include python/CMakeFiles/PythonInstall.dir/progress.make

python/CMakeFiles/PythonInstall: python/SeekrPluginWrapper.cpp


python/SeekrPluginWrapper.cpp: ../python/seekrplugin.i
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lvotapka/openseekr/plugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating SeekrPluginWrapper.cpp"
	cd /home/lvotapka/openseekr/plugin/build/python && /home/lvotapka/miniconda2/bin/swig -python -c++ -o SeekrPluginWrapper.cpp -I/home/lvotapka/bin/openmm/include /home/lvotapka/openseekr/plugin/python/seekrplugin.i

PythonInstall: python/CMakeFiles/PythonInstall
PythonInstall: python/SeekrPluginWrapper.cpp
PythonInstall: python/CMakeFiles/PythonInstall.dir/build.make
	cd /home/lvotapka/openseekr/plugin/build/python && /home/lvotapka/miniconda2/bin/python setup.py build
	cd /home/lvotapka/openseekr/plugin/build/python && /home/lvotapka/miniconda2/bin/python setup.py install
.PHONY : PythonInstall

# Rule to build all files generated by this target.
python/CMakeFiles/PythonInstall.dir/build: PythonInstall

.PHONY : python/CMakeFiles/PythonInstall.dir/build

python/CMakeFiles/PythonInstall.dir/clean:
	cd /home/lvotapka/openseekr/plugin/build/python && $(CMAKE_COMMAND) -P CMakeFiles/PythonInstall.dir/cmake_clean.cmake
.PHONY : python/CMakeFiles/PythonInstall.dir/clean

python/CMakeFiles/PythonInstall.dir/depend:
	cd /home/lvotapka/openseekr/plugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lvotapka/openseekr/plugin /home/lvotapka/openseekr/plugin/python /home/lvotapka/openseekr/plugin/build /home/lvotapka/openseekr/plugin/build/python /home/lvotapka/openseekr/plugin/build/python/CMakeFiles/PythonInstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : python/CMakeFiles/PythonInstall.dir/depend

