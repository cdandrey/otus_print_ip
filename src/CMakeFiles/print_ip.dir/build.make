# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/cmake-3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/cdandrey/otus_print_ip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/cdandrey/otus_print_ip

# Include any dependencies generated for this target.
include src/CMakeFiles/print_ip.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/print_ip.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/print_ip.dir/flags.make

src/CMakeFiles/print_ip.dir/main.cpp.o: src/CMakeFiles/print_ip.dir/flags.make
src/CMakeFiles/print_ip.dir/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/cdandrey/otus_print_ip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/print_ip.dir/main.cpp.o"
	cd /home/travis/build/cdandrey/otus_print_ip/src && /usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/print_ip.dir/main.cpp.o -c /home/travis/build/cdandrey/otus_print_ip/src/main.cpp

src/CMakeFiles/print_ip.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/print_ip.dir/main.cpp.i"
	cd /home/travis/build/cdandrey/otus_print_ip/src && /usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/cdandrey/otus_print_ip/src/main.cpp > CMakeFiles/print_ip.dir/main.cpp.i

src/CMakeFiles/print_ip.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/print_ip.dir/main.cpp.s"
	cd /home/travis/build/cdandrey/otus_print_ip/src && /usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/cdandrey/otus_print_ip/src/main.cpp -o CMakeFiles/print_ip.dir/main.cpp.s

# Object files for target print_ip
print_ip_OBJECTS = \
"CMakeFiles/print_ip.dir/main.cpp.o"

# External object files for target print_ip
print_ip_EXTERNAL_OBJECTS =

src/print_ip: src/CMakeFiles/print_ip.dir/main.cpp.o
src/print_ip: src/CMakeFiles/print_ip.dir/build.make
src/print_ip: lib/liblibipp.a
src/print_ip: src/CMakeFiles/print_ip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/cdandrey/otus_print_ip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable print_ip"
	cd /home/travis/build/cdandrey/otus_print_ip/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print_ip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/print_ip.dir/build: src/print_ip

.PHONY : src/CMakeFiles/print_ip.dir/build

src/CMakeFiles/print_ip.dir/clean:
	cd /home/travis/build/cdandrey/otus_print_ip/src && $(CMAKE_COMMAND) -P CMakeFiles/print_ip.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/print_ip.dir/clean

src/CMakeFiles/print_ip.dir/depend:
	cd /home/travis/build/cdandrey/otus_print_ip && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/cdandrey/otus_print_ip /home/travis/build/cdandrey/otus_print_ip/src /home/travis/build/cdandrey/otus_print_ip /home/travis/build/cdandrey/otus_print_ip/src /home/travis/build/cdandrey/otus_print_ip/src/CMakeFiles/print_ip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/print_ip.dir/depend

