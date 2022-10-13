#!/bin/bash

os_name=$(uname)

command_found() {
  command -v "$1" >/dev/null 2>&1
}

[ -f build ] && rm -fr build
mkdir -p build
cd build

if [ "$os_name" = "Linux" ]; then
  if [ -z "$DEV_SET" ]; then
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
      if [ "$arch" = "arm64" ]; then
          sudo apt install -y \
          pkg-config \
          libxkbfile-dev \
          xkb-data \
          uuid-dev
      fi
    elif grep ^NAME= /etc/os-release | grep -iq Fedora; then
      sudo dnf update -y
      sudo dnf install -y cmake
      sudo dnf install -y python3-pip
      sudo pip3 install conan
      sudo dnf install -y \
      libudev-devel \
      libfontenc-devel \
      libXaw-devel \
      libXcomposite-devel \
      libXdmcp-devel \
      libXtst-devel \
      libxkbfile-devel \
      libXres-devel \
      libXScrnSaver-devel \
      libXvMC-devel \
      xorg-x11-xtrans-devel \
      xcb-util-wm-devel \
      xcb-util-keysyms-devel \
      xcb-util-renderutil-devel \
      libXdamage-devel \
      xcb-util-devel \
      xkeyboard-config-devel \
      systemd-devel \
      libuuid-devel
    fi
  fi
  conan install .. --build=missing -s compiler.libcxx=libstdc++11
elif [ "$os_name" = "Darwin" ]; then
  pip3 install conan
  conan install .. --build=missing
else
  pip3 install conan
  conan install .. --build=missing
fi
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
