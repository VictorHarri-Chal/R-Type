#!/bin/bash

[ -f build ] && rm -fr build
mkdir -p build
cd build

if [ "$(uname)" = "Linux" ]; then
  arch=$(dpkg --print-architecture)
  if [ "$arch" = "amd64" ]; then
    echo ubuntu
  elif [ "$arch" = "arm64" ]; then
    echo rpi
  fi
  conan install .. --build=missing -s compiler.libcxx=libstdc++11
else
  conan install .. --build=missing
fi
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  cmake --build .
