rm -fr build
mkdir build
cd build
conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cmake .. -DCMAKE_BUILD_TYPE=Release -G 'Visual Studio 17 2022'
cd ..
cmake --build build
