# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /media/briket/data/Git/univer/jetb_iics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/briket/data/Git/univer/jetb_iics

# Include any dependencies generated for this target.
include CMakeFiles/iics_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/iics_4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/iics_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iics_4.dir/flags.make

CMakeFiles/iics_4.dir/src/Native/impl.c.o: CMakeFiles/iics_4.dir/flags.make
CMakeFiles/iics_4.dir/src/Native/impl.c.o: src/Native/impl.c
CMakeFiles/iics_4.dir/src/Native/impl.c.o: CMakeFiles/iics_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/briket/data/Git/univer/jetb_iics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/iics_4.dir/src/Native/impl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/iics_4.dir/src/Native/impl.c.o -MF CMakeFiles/iics_4.dir/src/Native/impl.c.o.d -o CMakeFiles/iics_4.dir/src/Native/impl.c.o -c /media/briket/data/Git/univer/jetb_iics/src/Native/impl.c

CMakeFiles/iics_4.dir/src/Native/impl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/iics_4.dir/src/Native/impl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/briket/data/Git/univer/jetb_iics/src/Native/impl.c > CMakeFiles/iics_4.dir/src/Native/impl.c.i

CMakeFiles/iics_4.dir/src/Native/impl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/iics_4.dir/src/Native/impl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/briket/data/Git/univer/jetb_iics/src/Native/impl.c -o CMakeFiles/iics_4.dir/src/Native/impl.c.s

# Object files for target iics_4
iics_4_OBJECTS = \
"CMakeFiles/iics_4.dir/src/Native/impl.c.o"

# External object files for target iics_4
iics_4_EXTERNAL_OBJECTS =

libiics_4.so: CMakeFiles/iics_4.dir/src/Native/impl.c.o
libiics_4.so: CMakeFiles/iics_4.dir/build.make
libiics_4.so: CMakeFiles/iics_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/briket/data/Git/univer/jetb_iics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libiics_4.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iics_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iics_4.dir/build: libiics_4.so
.PHONY : CMakeFiles/iics_4.dir/build

CMakeFiles/iics_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iics_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iics_4.dir/clean

CMakeFiles/iics_4.dir/depend:
	cd /media/briket/data/Git/univer/jetb_iics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/briket/data/Git/univer/jetb_iics /media/briket/data/Git/univer/jetb_iics /media/briket/data/Git/univer/jetb_iics /media/briket/data/Git/univer/jetb_iics /media/briket/data/Git/univer/jetb_iics/CMakeFiles/iics_4.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/iics_4.dir/depend
