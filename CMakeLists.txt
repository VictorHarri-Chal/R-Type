cmake_minimum_required(VERSION 3.17)

project(r-type_client)
project(r-type_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(SRC_CLIENT
    src/client/main.cpp
    src/client/network/client.cpp
    src/client/network/client.hpp
)

add_executable(r-type_client ${SRC_CLIENT})

set(SRC_SERVER
    src/server/main.cpp
    src/server/network/server.cpp
    src/server/network/server.hpp
)

add_executable(r-type_server ${SRC_SERVER})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

target_link_libraries(r-type_client sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(r-type_server sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

if(NOT DEFINED ASIO_SRC)
    set(ASIO_SRC ${CMAKE_CURRENT_LIST_DIR})
endif()

set(ASIO_SRC_DEP "${ASIO_SRC}/asio")

include(FetchContent)

FetchContent_Declare(asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_SHALLOW TRUE
    SOURCE_DIR ${ASIO_SRC_DEP}
)

FetchContent_GetProperties(asio)

if(NOT asio_POPULATED)
    if(EXISTS "${ASIO_SRC_DEP}/asio")
        set(FETCHCONTENT_SOURCE_DIR_ASIO ${ASIO_SRC_DEP})
    endif()
    FetchContent_Populate(asio)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

add_library(asio INTERFACE)

target_include_directories(asio
    INTERFACE ${asio_SOURCE_DIR}/asio/include
)

target_compile_definitions(asio
    INTERFACE
    ASIO_STANDALONE
    ASIO_NO_DEPRECATED
)
