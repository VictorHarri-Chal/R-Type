# Cmake version
cmake_minimum_required(VERSION 3.17)
project(r-type)

SET(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)

if (MSVC)
    add_compile_options(/W2)
else ()
    add_compile_options(-Wall -Wshadow -Wno-unused -Wno-deprecated-copy -Wno-deprecated-declarations)
endif ()

set(INCROOT ${PROJECT_SOURCE_DIR}/include/)

set(SRC_INTERFACE

)

set(INTERFACES_NAME interface)

add_library(${INTERFACES_NAME} INTERFACE)

target_include_directories(${INTERFACES_NAME} INTERFACE ${INCROOT})
target_compile_definitions(asio PUBLIC ASIO_STANDALONE)

add_subdirectory(src)
