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
CMAKE_COMMAND = /cygdrive/c/Users/369192/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/369192/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/GSL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GSL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GSL.dir/flags.make

CMakeFiles/GSL.dir/main.cpp.o: CMakeFiles/GSL.dir/flags.make
CMakeFiles/GSL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GSL.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GSL.dir/main.cpp.o -c "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/main.cpp"

CMakeFiles/GSL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GSL.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/main.cpp" > CMakeFiles/GSL.dir/main.cpp.i

CMakeFiles/GSL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GSL.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/main.cpp" -o CMakeFiles/GSL.dir/main.cpp.s

CMakeFiles/GSL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/GSL.dir/main.cpp.o.requires

CMakeFiles/GSL.dir/main.cpp.o.provides: CMakeFiles/GSL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GSL.dir/build.make CMakeFiles/GSL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GSL.dir/main.cpp.o.provides

CMakeFiles/GSL.dir/main.cpp.o.provides.build: CMakeFiles/GSL.dir/main.cpp.o


# Object files for target GSL
GSL_OBJECTS = \
"CMakeFiles/GSL.dir/main.cpp.o"

# External object files for target GSL
GSL_EXTERNAL_OBJECTS =

GSL.exe: CMakeFiles/GSL.dir/main.cpp.o
GSL.exe: CMakeFiles/GSL.dir/build.make
GSL.exe: /usr/lib/libgsl.dll.a
GSL.exe: /usr/lib/libgslcblas.dll.a
GSL.exe: CMakeFiles/GSL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GSL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GSL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GSL.dir/build: GSL.exe

.PHONY : CMakeFiles/GSL.dir/build

CMakeFiles/GSL.dir/requires: CMakeFiles/GSL.dir/main.cpp.o.requires

.PHONY : CMakeFiles/GSL.dir/requires

CMakeFiles/GSL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GSL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GSL.dir/clean

CMakeFiles/GSL.dir/depend:
	cd "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL" "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL" "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug" "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug" "/cygdrive/c/xampp/htdocs/Metody Numeryczne/Zadanie 12/GSL/cmake-build-debug/CMakeFiles/GSL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GSL.dir/depend
