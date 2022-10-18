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
    fi
  fi
  conan install .. --build=missing  -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
elif [ "$os_name" = "Darwin" ]; then
  pip3 install conan
  conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
else
  pip3 install conan
  conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
fi
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

echo "__________        ________________.___._____________________"
echo "\______   \       \__    ___/\__  |   |\______   \_   _____/"
echo " |       _/  ______ |    |    /   |   | |     ___/|    __)_ "
echo " |    |   \ /_____/ |    |    \____   | |    |    |        \\"
echo " |____|_  /         |____|    / ______| |____|   /_______  /"
echo "        \/                    \/                         \/ "