# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /s/parsons/g/under/ramscuse/cs253/hw4/testDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/parsons/g/under/ramscuse/cs253/hw4/testDir

# Include any dependencies generated for this target.
include CMakeFiles/hw4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hw4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hw4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw4.dir/flags.make

CMakeFiles/hw4.dir/Show.cc.o: CMakeFiles/hw4.dir/flags.make
CMakeFiles/hw4.dir/Show.cc.o: Show.cc
CMakeFiles/hw4.dir/Show.cc.o: CMakeFiles/hw4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/parsons/g/under/ramscuse/cs253/hw4/testDir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw4.dir/Show.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw4.dir/Show.cc.o -MF CMakeFiles/hw4.dir/Show.cc.o.d -o CMakeFiles/hw4.dir/Show.cc.o -c /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Show.cc

CMakeFiles/hw4.dir/Show.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4.dir/Show.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Show.cc > CMakeFiles/hw4.dir/Show.cc.i

CMakeFiles/hw4.dir/Show.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4.dir/Show.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Show.cc -o CMakeFiles/hw4.dir/Show.cc.s

CMakeFiles/hw4.dir/Schedule.cc.o: CMakeFiles/hw4.dir/flags.make
CMakeFiles/hw4.dir/Schedule.cc.o: Schedule.cc
CMakeFiles/hw4.dir/Schedule.cc.o: CMakeFiles/hw4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/parsons/g/under/ramscuse/cs253/hw4/testDir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw4.dir/Schedule.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw4.dir/Schedule.cc.o -MF CMakeFiles/hw4.dir/Schedule.cc.o.d -o CMakeFiles/hw4.dir/Schedule.cc.o -c /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Schedule.cc

CMakeFiles/hw4.dir/Schedule.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4.dir/Schedule.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Schedule.cc > CMakeFiles/hw4.dir/Schedule.cc.i

CMakeFiles/hw4.dir/Schedule.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4.dir/Schedule.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/parsons/g/under/ramscuse/cs253/hw4/testDir/Schedule.cc -o CMakeFiles/hw4.dir/Schedule.cc.s

# Object files for target hw4
hw4_OBJECTS = \
"CMakeFiles/hw4.dir/Show.cc.o" \
"CMakeFiles/hw4.dir/Schedule.cc.o"

# External object files for target hw4
hw4_EXTERNAL_OBJECTS =

libhw4.a: CMakeFiles/hw4.dir/Show.cc.o
libhw4.a: CMakeFiles/hw4.dir/Schedule.cc.o
libhw4.a: CMakeFiles/hw4.dir/build.make
libhw4.a: CMakeFiles/hw4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/s/parsons/g/under/ramscuse/cs253/hw4/testDir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libhw4.a"
	$(CMAKE_COMMAND) -P CMakeFiles/hw4.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw4.dir/build: libhw4.a
.PHONY : CMakeFiles/hw4.dir/build

CMakeFiles/hw4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw4.dir/clean

CMakeFiles/hw4.dir/depend:
	cd /s/parsons/g/under/ramscuse/cs253/hw4/testDir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/parsons/g/under/ramscuse/cs253/hw4/testDir /s/parsons/g/under/ramscuse/cs253/hw4/testDir /s/parsons/g/under/ramscuse/cs253/hw4/testDir /s/parsons/g/under/ramscuse/cs253/hw4/testDir /s/parsons/g/under/ramscuse/cs253/hw4/testDir/CMakeFiles/hw4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw4.dir/depend

