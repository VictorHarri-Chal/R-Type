#!/bin/bash

set -x

os_name=$(uname)

command_found() {
  command -v "$1" >/dev/null 2>&1
}

[ -f build ] && rm -fr build
mkdir -p build
cd build

if [ "$os_name" = "Linux" ]; then
  arch=$(dpkg --print-architecture)
  if command_found apt; then
    sudo apt update
    sudo apt upgrade -y
    sudo apt install python3-pip -y
    sudo pip3 install conan
    sudo apt install -y \
    libudev-dev \
    libgl-dev \
    libx11-xcb-dev \
    libfontenc-dev \
    libxaw7-dev \
    libxcomposite-dev \
    libxcursor-dev \
    libxdamage-dev \
    libxfixes-dev \
    libxi-dev \
    libxinerama-dev \
    libxmu-dev \
    libxmuu-dev \
    libxpm-dev \
    libxrandr-dev \
    libxres-dev \
    libxss-dev \
    libxtst-dev \
    libxv-dev \
    libxvmc-dev \
    libxxf86vm-dev \
    libxcb-render-util0-dev \
    libxcb-xkb-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-randr0-dev \
    libxcb-shape0-dev \
    libxcb-sync-dev \
    libxcb-xfixes0-dev \
    libxcb-xinerama0-dev \
    libxcb-dri3-dev \
    libxcb-util-dev \
    libxcb-util0-dev
    sudo apt install -f
    if [ "$arch" = "amd64" ]; then
        echo ubuntu
    elif [ "$arch" = "arm64" ]; then
        echo rpi
        sudo apt install -y \
        pkg-config \
        libxkbfile-dev \
        xkb-data \
        uuid-dev
    fi
  elif command_found dnf; then
    echo dnf
  fi
  conan install .. --build=missing -s compiler.libcxx=libstdc++11
elif [ "$os_name" = "Darwin" ]; then
  echo darwin
  pip3 install conan
  conan install .. --build=missing
else
  echo windows
  pip3 install conan
  conan install .. --build=missing
fi
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
