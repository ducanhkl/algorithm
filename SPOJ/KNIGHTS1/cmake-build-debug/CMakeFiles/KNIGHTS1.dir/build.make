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
CMAKE_SOURCE_DIR = F:\coding\algorithm\SPOJ\KNIGHTS1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KNIGHTS1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KNIGHTS1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KNIGHTS1.dir/flags.make

CMakeFiles/KNIGHTS1.dir/main.cpp.obj: CMakeFiles/KNIGHTS1.dir/flags.make
CMakeFiles/KNIGHTS1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KNIGHTS1.dir/main.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\KNIGHTS1.dir\main.cpp.obj -c F:\coding\algorithm\SPOJ\KNIGHTS1\main.cpp

CMakeFiles/KNIGHTS1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KNIGHTS1.dir/main.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\coding\algorithm\SPOJ\KNIGHTS1\main.cpp > CMakeFiles\KNIGHTS1.dir\main.cpp.i

CMakeFiles/KNIGHTS1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KNIGHTS1.dir/main.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\coding\algorithm\SPOJ\KNIGHTS1\main.cpp -o CMakeFiles\KNIGHTS1.dir\main.cpp.s

# Object files for target KNIGHTS1
KNIGHTS1_OBJECTS = \
"CMakeFiles/KNIGHTS1.dir/main.cpp.obj"

# External object files for target KNIGHTS1
KNIGHTS1_EXTERNAL_OBJECTS =

KNIGHTS1.exe: CMakeFiles/KNIGHTS1.dir/main.cpp.obj
KNIGHTS1.exe: CMakeFiles/KNIGHTS1.dir/build.make
KNIGHTS1.exe: CMakeFiles/KNIGHTS1.dir/linklibs.rsp
KNIGHTS1.exe: CMakeFiles/KNIGHTS1.dir/objects1.rsp
KNIGHTS1.exe: CMakeFiles/KNIGHTS1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KNIGHTS1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KNIGHTS1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KNIGHTS1.dir/build: KNIGHTS1.exe

.PHONY : CMakeFiles/KNIGHTS1.dir/build

CMakeFiles/KNIGHTS1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KNIGHTS1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KNIGHTS1.dir/clean

CMakeFiles/KNIGHTS1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\coding\algorithm\SPOJ\KNIGHTS1 F:\coding\algorithm\SPOJ\KNIGHTS1 F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug F:\coding\algorithm\SPOJ\KNIGHTS1\cmake-build-debug\CMakeFiles\KNIGHTS1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KNIGHTS1.dir/depend

