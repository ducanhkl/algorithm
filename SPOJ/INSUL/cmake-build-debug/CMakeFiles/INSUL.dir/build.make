# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\coding\algorithm\SPOJ\INSUL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/INSUL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/INSUL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/INSUL.dir/flags.make

CMakeFiles/INSUL.dir/main.cpp.obj: CMakeFiles/INSUL.dir/flags.make
CMakeFiles/INSUL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/INSUL.dir/main.cpp.obj"
	C:\MINGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\INSUL.dir\main.cpp.obj -c E:\coding\algorithm\SPOJ\INSUL\main.cpp

CMakeFiles/INSUL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/INSUL.dir/main.cpp.i"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\coding\algorithm\SPOJ\INSUL\main.cpp > CMakeFiles\INSUL.dir\main.cpp.i

CMakeFiles/INSUL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/INSUL.dir/main.cpp.s"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\coding\algorithm\SPOJ\INSUL\main.cpp -o CMakeFiles\INSUL.dir\main.cpp.s

# Object files for target INSUL
INSUL_OBJECTS = \
"CMakeFiles/INSUL.dir/main.cpp.obj"

# External object files for target INSUL
INSUL_EXTERNAL_OBJECTS =

INSUL.exe: CMakeFiles/INSUL.dir/main.cpp.obj
INSUL.exe: CMakeFiles/INSUL.dir/build.make
INSUL.exe: CMakeFiles/INSUL.dir/linklibs.rsp
INSUL.exe: CMakeFiles/INSUL.dir/objects1.rsp
INSUL.exe: CMakeFiles/INSUL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable INSUL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\INSUL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/INSUL.dir/build: INSUL.exe

.PHONY : CMakeFiles/INSUL.dir/build

CMakeFiles/INSUL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\INSUL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/INSUL.dir/clean

CMakeFiles/INSUL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\coding\algorithm\SPOJ\INSUL E:\coding\algorithm\SPOJ\INSUL E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug E:\coding\algorithm\SPOJ\INSUL\cmake-build-debug\CMakeFiles\INSUL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/INSUL.dir/depend
