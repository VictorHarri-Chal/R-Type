# Cmake version
cmake_minimum_required(VERSION 3.17)
project(r-type)

SET(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -std=c++20 -Wextra -Wshadow -lsfml-system -lsfml-window -lsfml-graphics")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/)

set(SRC_INTERFACE
    ${INCROOT}events.hpp
)

set(INTERFACES_NAME interface)

add_library(${INTERFACES_NAME} INTERFACE)

target_include_directories(${INTERFACES_NAME} INTERFACE ${INCROOT})

add_subdirectory(src)