#!/bin/bash

mkdir -p build
cd build
if [ "$(uname)" = "Linux" ]; then
  echo "building on linux"
  conan install .. --build=missing -s compiler.libcxx=libstdc++11
else
  echo "building on macos or msys"
  conan install .. --build=missing
fi
 cmake -DCMAKE_BUILD_TYPE=Debug ..
 cmake --build .
 
