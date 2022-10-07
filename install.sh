#!/bin/bash

[ -f build ] && rm -fr build
mkdir -p build
cd build

os_name=$(uname)

if [ "$os_name" = "Linux" ]; then
  arch=$(dpkg --print-architecture)
  sudo apt update
  sudo apt uprade -y
  sudo apt install python3-pip -y
  sudo pip3 install conan
  if [ "$arch" = "amd64" ]; then
    echo ubuntu
  elif [ "$arch" = "arm64" ]; then
    echo rpi
  fi
  conan install .. --build=missing -s compiler.libcxx=libstdc++11
elif [ "$os_name" = "Darwin" ]; then
  echo macos
else
  echo windows
  pip3 install conan
  conan install .. --build=missing
fi
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
