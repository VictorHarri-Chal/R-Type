cmake_minimum_required(VERSION 3.17)

project(r-type_client)
project(r-type_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

set(SRC_CLIENT
    src/client/main.cpp
    src/client/network/ClientBuffer.hpp
    src/client/network/ClientBuffer.cpp
    src/client/network/Client.hpp
    src/client/network/Client.cpp
)

add_executable(r-type_client ${SRC_CLIENT})

set(SRC_SERVER
    src/server/main.cpp
    src/server/network/Server.cpp
    src/server/network/Server.hpp
)

add_executable(r-type_server ${SRC_SERVER})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

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

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.70 COMPONENTS thread system REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")

# This is needed if your Boost version is newer than your CMake version
# or if you have an old version of CMake (<3.5)
if(NOT TARGET Boost::filesystem)
    add_library(Boost::filesystem IMPORTED INTERFACE)
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
endif()

target_link_libraries(r-type_client sfml-system sfml-window sfml-graphics sfml-audio sfml-network -pthread)
target_link_libraries(r-type_server sfml-system sfml-window sfml-graphics sfml-audio sfml-network -pthread)

set_target_properties(r-type_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
