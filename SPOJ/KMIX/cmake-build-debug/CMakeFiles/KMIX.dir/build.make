# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\coding\algorithm\SPOJ\KMIX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KMIX.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KMIX.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KMIX.dir/flags.make

CMakeFiles/KMIX.dir/main.cpp.obj: CMakeFiles/KMIX.dir/flags.make
CMakeFiles/KMIX.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KMIX.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\KMIX.dir\main.cpp.obj -c F:\coding\algorithm\SPOJ\KMIX\main.cpp

CMakeFiles/KMIX.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KMIX.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\coding\algorithm\SPOJ\KMIX\main.cpp > CMakeFiles\KMIX.dir\main.cpp.i

CMakeFiles/KMIX.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KMIX.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\coding\algorithm\SPOJ\KMIX\main.cpp -o CMakeFiles\KMIX.dir\main.cpp.s

# Object files for target KMIX
KMIX_OBJECTS = \
"CMakeFiles/KMIX.dir/main.cpp.obj"

# External object files for target KMIX
KMIX_EXTERNAL_OBJECTS =

KMIX.exe: CMakeFiles/KMIX.dir/main.cpp.obj
KMIX.exe: CMakeFiles/KMIX.dir/build.make
KMIX.exe: CMakeFiles/KMIX.dir/linklibs.rsp
KMIX.exe: CMakeFiles/KMIX.dir/objects1.rsp
KMIX.exe: CMakeFiles/KMIX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KMIX.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KMIX.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KMIX.dir/build: KMIX.exe

.PHONY : CMakeFiles/KMIX.dir/build

CMakeFiles/KMIX.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KMIX.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KMIX.dir/clean

CMakeFiles/KMIX.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\coding\algorithm\SPOJ\KMIX F:\coding\algorithm\SPOJ\KMIX F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug F:\coding\algorithm\SPOJ\KMIX\cmake-build-debug\CMakeFiles\KMIX.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KMIX.dir/depend

