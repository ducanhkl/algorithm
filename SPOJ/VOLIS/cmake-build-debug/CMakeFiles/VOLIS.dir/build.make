# CMAKE generated file: DO NOT EDIT!
<<<<<<< HEAD
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15
=======
# Generated by "Unix Makefiles" Generator, CMake Version 3.15
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f

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

<<<<<<< HEAD
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f
=======
# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/chuducanh/Downloads/CLion-2019.2.5/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/chuducanh/Downloads/CLion-2019.2.5/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = E:\coding\algorithm\SPOJ\VOLIS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug
=======
CMAKE_SOURCE_DIR = /media/chuducanh/D/algorithm/SPOJ/VOLIS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f

# Include any dependencies generated for this target.
include CMakeFiles/VOLIS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VOLIS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VOLIS.dir/flags.make

<<<<<<< HEAD
CMakeFiles/VOLIS.dir/main.cpp.obj: CMakeFiles/VOLIS.dir/flags.make
CMakeFiles/VOLIS.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VOLIS.dir/main.cpp.obj"
	C:\MINGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\VOLIS.dir\main.cpp.obj -c E:\coding\algorithm\SPOJ\VOLIS\main.cpp

CMakeFiles/VOLIS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VOLIS.dir/main.cpp.i"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\coding\algorithm\SPOJ\VOLIS\main.cpp > CMakeFiles\VOLIS.dir\main.cpp.i

CMakeFiles/VOLIS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VOLIS.dir/main.cpp.s"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\coding\algorithm\SPOJ\VOLIS\main.cpp -o CMakeFiles\VOLIS.dir\main.cpp.s

# Object files for target VOLIS
VOLIS_OBJECTS = \
"CMakeFiles/VOLIS.dir/main.cpp.obj"
=======
CMakeFiles/VOLIS.dir/main.cpp.o: CMakeFiles/VOLIS.dir/flags.make
CMakeFiles/VOLIS.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VOLIS.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VOLIS.dir/main.cpp.o -c /media/chuducanh/D/algorithm/SPOJ/VOLIS/main.cpp

CMakeFiles/VOLIS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VOLIS.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/chuducanh/D/algorithm/SPOJ/VOLIS/main.cpp > CMakeFiles/VOLIS.dir/main.cpp.i

CMakeFiles/VOLIS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VOLIS.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/chuducanh/D/algorithm/SPOJ/VOLIS/main.cpp -o CMakeFiles/VOLIS.dir/main.cpp.s

# Object files for target VOLIS
VOLIS_OBJECTS = \
"CMakeFiles/VOLIS.dir/main.cpp.o"
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f

# External object files for target VOLIS
VOLIS_EXTERNAL_OBJECTS =

<<<<<<< HEAD
VOLIS.exe: CMakeFiles/VOLIS.dir/main.cpp.obj
VOLIS.exe: CMakeFiles/VOLIS.dir/build.make
VOLIS.exe: CMakeFiles/VOLIS.dir/linklibs.rsp
VOLIS.exe: CMakeFiles/VOLIS.dir/objects1.rsp
VOLIS.exe: CMakeFiles/VOLIS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VOLIS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\VOLIS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VOLIS.dir/build: VOLIS.exe
=======
VOLIS: CMakeFiles/VOLIS.dir/main.cpp.o
VOLIS: CMakeFiles/VOLIS.dir/build.make
VOLIS: CMakeFiles/VOLIS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VOLIS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VOLIS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VOLIS.dir/build: VOLIS
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f

.PHONY : CMakeFiles/VOLIS.dir/build

CMakeFiles/VOLIS.dir/clean:
<<<<<<< HEAD
	$(CMAKE_COMMAND) -P CMakeFiles\VOLIS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/VOLIS.dir/clean

CMakeFiles/VOLIS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\coding\algorithm\SPOJ\VOLIS E:\coding\algorithm\SPOJ\VOLIS E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug E:\coding\algorithm\SPOJ\VOLIS\cmake-build-debug\CMakeFiles\VOLIS.dir\DependInfo.cmake --color=$(COLOR)
=======
	$(CMAKE_COMMAND) -P CMakeFiles/VOLIS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VOLIS.dir/clean

CMakeFiles/VOLIS.dir/depend:
	cd /media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/chuducanh/D/algorithm/SPOJ/VOLIS /media/chuducanh/D/algorithm/SPOJ/VOLIS /media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug /media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug /media/chuducanh/D/algorithm/SPOJ/VOLIS/cmake-build-debug/CMakeFiles/VOLIS.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> b6b83ad5bc17155acd94b2ea3dec96baacb96f9f
.PHONY : CMakeFiles/VOLIS.dir/depend

