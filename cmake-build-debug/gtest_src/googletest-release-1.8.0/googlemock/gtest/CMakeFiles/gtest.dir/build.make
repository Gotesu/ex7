# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/gotesu/Desktop/AP/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/gotesu/Desktop/AP/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gotesu/CLionProjects/ex5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gotesu/CLionProjects/ex5/cmake-build-debug

# Include any dependencies generated for this target.
include gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../gtest_src/googletest-release-1.8.0/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gotesu/CLionProjects/ex5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/gotesu/CLionProjects/ex5/gtest_src/googletest-release-1.8.0/googletest/src/gtest-all.cc

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gotesu/CLionProjects/ex5/gtest_src/googletest-release-1.8.0/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gotesu/CLionProjects/ex5/gtest_src/googletest-release-1.8.0/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build.make gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

gtest_src/googletest-release-1.8.0/googlemock/gtest/libgtest.a: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
gtest_src/googletest-release-1.8.0/googlemock/gtest/libgtest.a: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build.make
gtest_src/googletest-release-1.8.0/googlemock/gtest/libgtest.a: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gotesu/CLionProjects/ex5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build: gtest_src/googletest-release-1.8.0/googlemock/gtest/libgtest.a

.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/build

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/requires: gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/requires

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/clean

gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/gotesu/CLionProjects/ex5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gotesu/CLionProjects/ex5 /home/gotesu/CLionProjects/ex5/gtest_src/googletest-release-1.8.0/googletest /home/gotesu/CLionProjects/ex5/cmake-build-debug /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest /home/gotesu/CLionProjects/ex5/cmake-build-debug/gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest_src/googletest-release-1.8.0/googlemock/gtest/CMakeFiles/gtest.dir/depend

