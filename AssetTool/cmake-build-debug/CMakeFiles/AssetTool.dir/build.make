# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AssetTool.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/AssetTool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AssetTool.dir/flags.make

CMakeFiles/AssetTool.dir/main.cpp.obj: CMakeFiles/AssetTool.dir/flags.make
CMakeFiles/AssetTool.dir/main.cpp.obj: CMakeFiles/AssetTool.dir/includes_CXX.rsp
CMakeFiles/AssetTool.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AssetTool.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AssetTool.dir\main.cpp.obj -c C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\main.cpp

CMakeFiles/AssetTool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssetTool.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\main.cpp > CMakeFiles\AssetTool.dir\main.cpp.i

CMakeFiles/AssetTool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssetTool.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\main.cpp -o CMakeFiles\AssetTool.dir\main.cpp.s

# Object files for target AssetTool
AssetTool_OBJECTS = \
"CMakeFiles/AssetTool.dir/main.cpp.obj"

# External object files for target AssetTool
AssetTool_EXTERNAL_OBJECTS =

AssetTool.exe: CMakeFiles/AssetTool.dir/main.cpp.obj
AssetTool.exe: CMakeFiles/AssetTool.dir/build.make
AssetTool.exe: D:/SFML/lib/libsfml-graphics-d.a
AssetTool.exe: D:/SFML/lib/libsfml-network-d.a
AssetTool.exe: D:/SFML/lib/libsfml-audio-d.a
AssetTool.exe: D:/SFML/lib/libsfml-window-d.a
AssetTool.exe: D:/SFML/lib/libsfml-system-d.a
AssetTool.exe: CMakeFiles/AssetTool.dir/linklibs.rsp
AssetTool.exe: CMakeFiles/AssetTool.dir/objects1.rsp
AssetTool.exe: CMakeFiles/AssetTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AssetTool.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AssetTool.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AssetTool.dir/build: AssetTool.exe
.PHONY : CMakeFiles/AssetTool.dir/build

CMakeFiles/AssetTool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AssetTool.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AssetTool.dir/clean

CMakeFiles/AssetTool.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug C:\Users\tommy\Documents\Mateusz\CPPGameDev\bespokeassetmanagertool-mateusz-kolodziejczyk\AssetTool\cmake-build-debug\CMakeFiles\AssetTool.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AssetTool.dir/depend

