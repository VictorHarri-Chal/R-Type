# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/simonlefourn/code/simlf/R-Type

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/simonlefourn/code/simlf/R-Type

# Include any dependencies generated for this target.
include CMakeFiles/r-type_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/r-type_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/r-type_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r-type_server.dir/flags.make

CMakeFiles/r-type_server.dir/src/server/main.cpp.o: CMakeFiles/r-type_server.dir/flags.make
CMakeFiles/r-type_server.dir/src/server/main.cpp.o: src/server/main.cpp
CMakeFiles/r-type_server.dir/src/server/main.cpp.o: CMakeFiles/r-type_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonlefourn/code/simlf/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r-type_server.dir/src/server/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/r-type_server.dir/src/server/main.cpp.o -MF CMakeFiles/r-type_server.dir/src/server/main.cpp.o.d -o CMakeFiles/r-type_server.dir/src/server/main.cpp.o -c /Users/simonlefourn/code/simlf/R-Type/src/server/main.cpp

CMakeFiles/r-type_server.dir/src/server/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/src/server/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonlefourn/code/simlf/R-Type/src/server/main.cpp > CMakeFiles/r-type_server.dir/src/server/main.cpp.i

CMakeFiles/r-type_server.dir/src/server/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/src/server/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonlefourn/code/simlf/R-Type/src/server/main.cpp -o CMakeFiles/r-type_server.dir/src/server/main.cpp.s

CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o: CMakeFiles/r-type_server.dir/flags.make
CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o: src/server/network/server.cpp
CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o: CMakeFiles/r-type_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonlefourn/code/simlf/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o -MF CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o.d -o CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o -c /Users/simonlefourn/code/simlf/R-Type/src/server/network/server.cpp

CMakeFiles/r-type_server.dir/src/server/network/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/src/server/network/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonlefourn/code/simlf/R-Type/src/server/network/server.cpp > CMakeFiles/r-type_server.dir/src/server/network/server.cpp.i

CMakeFiles/r-type_server.dir/src/server/network/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/src/server/network/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonlefourn/code/simlf/R-Type/src/server/network/server.cpp -o CMakeFiles/r-type_server.dir/src/server/network/server.cpp.s

CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o: CMakeFiles/r-type_server.dir/flags.make
CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o: src/server/network/game_data.cpp
CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o: CMakeFiles/r-type_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonlefourn/code/simlf/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o -MF CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o.d -o CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o -c /Users/simonlefourn/code/simlf/R-Type/src/server/network/game_data.cpp

CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonlefourn/code/simlf/R-Type/src/server/network/game_data.cpp > CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.i

CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonlefourn/code/simlf/R-Type/src/server/network/game_data.cpp -o CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.s

# Object files for target r-type_server
r__type_server_OBJECTS = \
"CMakeFiles/r-type_server.dir/src/server/main.cpp.o" \
"CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o" \
"CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o"

# External object files for target r-type_server
r__type_server_EXTERNAL_OBJECTS =

r-type_server: CMakeFiles/r-type_server.dir/src/server/main.cpp.o
r-type_server: CMakeFiles/r-type_server.dir/src/server/network/server.cpp.o
r-type_server: CMakeFiles/r-type_server.dir/src/server/network/game_data.cpp.o
r-type_server: CMakeFiles/r-type_server.dir/build.make
r-type_server: /opt/homebrew/lib/libsfml-graphics.2.5.1.dylib
r-type_server: /opt/homebrew/lib/libsfml-audio.2.5.1.dylib
r-type_server: /opt/homebrew/lib/libsfml-network.2.5.1.dylib
r-type_server: /opt/homebrew/lib/libboost_serialization-mt.dylib
r-type_server: /opt/homebrew/lib/libsfml-window.2.5.1.dylib
r-type_server: /opt/homebrew/lib/libsfml-system.2.5.1.dylib
r-type_server: CMakeFiles/r-type_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simonlefourn/code/simlf/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable r-type_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r-type_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r-type_server.dir/build: r-type_server
.PHONY : CMakeFiles/r-type_server.dir/build

CMakeFiles/r-type_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/r-type_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/r-type_server.dir/clean

CMakeFiles/r-type_server.dir/depend:
	cd /Users/simonlefourn/code/simlf/R-Type && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simonlefourn/code/simlf/R-Type /Users/simonlefourn/code/simlf/R-Type /Users/simonlefourn/code/simlf/R-Type /Users/simonlefourn/code/simlf/R-Type /Users/simonlefourn/code/simlf/R-Type/CMakeFiles/r-type_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/r-type_server.dir/depend

