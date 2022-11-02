#!/bin/bash

set -eo pipefail
set -x

[ -f build ] && rm -fr build
mkdir -p build
cd build

if [ "$(uname)" = "Linux" ]; then

  if grep -E "^ID=|^ID_LIKE=" /etc/os-release | grep -iq debian; then
    sudo apt update
    sudo apt upgrade -y
    sudo apt install -y python3-pip
    sudo pip3 install conan
    sudo apt install -y libudev-dev libgl-dev libx11-xcb-dev libfontenc-dev libxaw7-dev libxcomposite-dev libxcursor-dev libxdamage-dev libxfixes-dev libxi-dev libxinerama-dev libxmu-dev libxmuu-dev libxpm-dev libxrandr-dev libxres-dev libxss-dev libxtst-dev libxv-dev libxvmc-dev libxxf86vm-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-dri3-dev libxcb-util-dev libxcb-util0-dev
    sudo apt install -f
    if [ "$(dpkg --print-architecture)" = "arm64" ]; then
      sudo apt install -y pkg-config libxkbfile-dev xkb-data uuid-dev
    #elif [ "$(dpkg --print-architecture)" = "arm64" ]; then
    fi

  elif grep "^ID=" /etc/os-release | grep -iq fedora; then
    sudo dnf update -y
    sudo dnf install -y cmake
    sudo dnf install -y python3-pip
    sudo pip3 install conan
    sudo dnf install -y libudev-devel libfontenc-devel libXaw-devel libXcomposite-devel libXdmcp-devel libXtst-devel libxkbfile-devel libXres-devel libXScrnSaver-devel libXvMC-devel xorg-x11-xtrans-devel xcb-util-wm-devel xcb-util-keysyms-devel xcb-util-renderutil-devel libXdamage-devel xcb-util-devel xkeyboard-config-devel systemd-devel libuuid-devel
  fi
  conan install -s compiler.libcxx=libstdc++11 \
  .. --build=missing \
  -c tools.system.package_manager:mode=install \
  -c tools.system.package_manager:sudo=True
elif [ "$os_name" = "Darwin" ]; then
  which -s brew
  if [[ $? != 0 ]] ; then
      /bin/zsh -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  fi
  brew install cmake pip conan
  xcode-select --install

  conan install .. --build=missing \
  -c tools.system.package_manager:mode=install \
  -c tools.system.package_manager:sudo=True
else
  pip3 install conan
  conan install .. --build=missing \
  -c tools.system.package_manager:mode=install \
  -c tools.system.package_manager:sudo=True
fi

cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -j 4

echo "__________        ________________.___._____________________"
echo "\______   \       \__    ___/\__  |   |\______   \_   _____/"
echo " |       _/  ______ |    |    /   |   | |     ___/|    __)_ "
echo " |    |   \ /_____/ |    |    \____   | |    |    |        \\"
echo " |____|_  /         |____|    / ______| |____|   /_______  /"
echo "        \/                    \/                         \/ "
