# R-TYPE

[![Build](https://img.shields.io/github/workflow/status/JohanCDev/Bomberman/Build)](https://github.com/JohanCDev/Bomberman/actions/workflows/build_and_mirror.yml)

# Screenshots


# Building

## Command Line (via CMake)

Required tools:
- CMake 3.17 (minimum)

on Linux:
```sh
# Create the build directory
mkdir build && cd build 

# Configure the project
cmake .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build .

# Return to previous directory
cd -
```

on Windows:

Required tools:
- Visual Studio 17 2022 (minimum)
```sh
# Create the build directory
mkdir build && cd build 

# Configure the project
cmake .. -G 'Visual Studio 17 2022' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build .

# Return to previous directory
cd -
```

# Documentation
