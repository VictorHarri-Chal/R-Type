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
  if grep ^NAME= /etc/os-release | grep -iq Ubuntu; then
    arch=$(dpkg --print-architecture)
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
  elif grep ^NAME= /etc/os-release | grep -iq Fedora; then
    echo dnf
    sudo dnf update -y
    sudo dnf install -y cmake
    sudo dnf install -y python3-pip
    sudo pip3 install conan
    sudo dnf install -y \
    libudev-devel \
    libgl-devel \
    libx11-xcb-devel \
    libfontenc-devel \
    libxaw7-devel \
    libxcomposite-devel \
    libxcursor-devel \
    libxdamage-devel \
    libxfixes-devel \
    libxi-devel \
    libxinerama-devel \
    libxmu-devel \
    libxmuu-devel \
    libxpm-devel \
    libxrandr-devel \
    libxres-devel \
    libxss-devel \
    libxtst-devel \
    libxv-devel \
    libxvmc-devel \
    libxxf86vm-devel \
    libxcb-render-util0-devel \
    libxcb-xkb-devel \
    libxcb-icccm4-devel \
    libxcb-image0-devel \
    libxcb-keysyms1-devel \
    libxcb-randr0-devel \
    libxcb-shape0-devel \
    libxcb-sync-devel \
    libxcb-xfixes0-devel \
    libxcb-xinerama0-devel \
    libxcb-dri3-devel \
    libxcb-util-devel \
    libxcb-util0-devel \
    systemd-devel
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
