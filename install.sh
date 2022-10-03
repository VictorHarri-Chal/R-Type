#!/bin/sh

mkdir -p build
cd build
sudo conan install .. -c tools.system.package_manager:mode=install --build=missing -s compiler.libcxx=libstdc++11
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
