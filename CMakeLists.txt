cmake_minimum_required(VERSION 3.17)

project(r-type_client)
project(r-type_server)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    add_compile_options(/W2)
else()
    add_compile_options("-Wall" "-Wextra" "-Wshadow" "-pedantic" "-Wpointer-arith")
endif()

set(INCROOT ${PROJECT_SOURCE_DIR}/include/)

set(SRC_INTERFACE
    ${INCROOT}events.hpp
)

set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(SRCCLIENT ${PROJECT_SOURCE_DIR}/src/client/)
set(SRCSERVER ${PROJECT_SOURCE_DIR}/src/server/)
set(ECSROOT ${SRCROOT}/ecs/)
set(EVENTSROOT ${SRCCLIENT}/events/)
set(GAMEROOT ${SRCCLIENT}/game/)
set(SCREENSROOT ${SRCCLIENT}/screens/)
set(TOOLSROOT ${SRCCLIENT}/tools/)

set(SRC_ECS
    ${ECSROOT}entity/Entity.cpp
    ${ECSROOT}entity/Entity.hpp
    ${ECSROOT}world.cpp
    ${ECSROOT}world.hpp
    ${ECSROOT}system/ISystem.hpp
    ${ECSROOT}component/alive/Alive.cpp
    ${ECSROOT}component/alive/Alive.hpp
    ${ECSROOT}component/collide/Collide.cpp
    ${ECSROOT}component/collide/Collide.hpp
    ${ECSROOT}component/destroyable/Destroyable.cpp
    ${ECSROOT}component/destroyable/Destroyable.hpp
    ${ECSROOT}component/drawable2d/Drawable2D.cpp
    ${ECSROOT}component/drawable2d/Drawable2D.hpp
    ${ECSROOT}component/explodable/Explodable.cpp
    ${ECSROOT}component/explodable/Explodable.hpp
    ${ECSROOT}component/inventory/Inventory.cpp
    ${ECSROOT}component/inventory/Inventory.hpp
    ${ECSROOT}component/sound/Sound.cpp
    ${ECSROOT}component/sound/Sound.hpp
    ${ECSROOT}component/transform/Transform.cpp
    ${ECSROOT}component/transform/Transform.hpp
    ${ECSROOT}component/IComponent.hpp
    ${ECSROOT}system/draw2d/Draw2D.cpp
    ${ECSROOT}system/draw2d/Draw2D.hpp
)

set(SRC_SCREENS
    ${SCREENSROOT}IScreen.hpp
    ${SCREENSROOT}intro/IntroScreen.cpp
    ${SCREENSROOT}intro/IntroScreen.hpp
    ${SCREENSROOT}menu/MenuScreen.cpp
    ${SCREENSROOT}menu/MenuScreen.hpp
    ${SCREENSROOT}options/OptionsScreen.cpp
    ${SCREENSROOT}options/OptionsScreen.hpp
    ${SCREENSROOT}multiplayer/MultiplayerScreen.cpp
    ${SCREENSROOT}multiplayer/MultiplayerScreen.hpp
)

set(SRC_GAME
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(SRC_EVENTS
    ${EVENTSROOT}Events.cpp
    ${EVENTSROOT}Events.hpp
)

set(SRC_TOOLS
    ${TOOLSROOT}Tools.cpp
    ${TOOLSROOT}Tools.hpp
)

set(SRC_CLIENT
    ${SRCCLIENT}main.cpp
    ${SRCCLIENT}network/client.cpp
    ${SRCCLIENT}network/client.hpp
    ${SRC_ECS}
    ${SRC_EVENTS}
    ${SRC_GAME}
    ${SRC_SCREENS}
    ${SRC_TOOLS}
)

add_executable(r-type_client ${SRC_CLIENT})

target_link_libraries(r-type_client
    CONAN_PKG::boost
    CONAN_PKG::sfml
)

target_include_directories(r-type_client PUBLIC
    ${CONAN_INCLUDE_DIRS_BOOST}
    ${CONAN_INCLUDE_DIRS_SFML}
)

set(SRC_SERVER
    ${SRCSERVER}main.cpp
    ${SRCSERVER}network/server.cpp
    ${SRCSERVER}network/server.hpp
    ${SRCSERVER}network/SafeQueue.cpp
    ${SRCSERVER}network/SafeQueue.hpp
    ${SRC_ECS}
)

add_executable(r-type_server ${SRC_SERVER})

target_include_directories(r-type_server PUBLIC
    ${CONAN_INCLUDE_DIRS_BOOST}
)

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

target_link_libraries(r-type_server
    CONAN_PKG::boost
    CONAN_PKG::sfml
)

#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)
#set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

#target_link_libraries(r-type_client sfml-system sfml-window sfml-graphics sfml-audio sfml-network -pthread)
#target_link_libraries(r-type_server sfml-system sfml-window sfml-graphics sfml-audio sfml-network -pthread -lboost_serialization)

set_property(TARGET r-type_client PROPERTY MSVC_RUNTIME_LIBRARY "")
set_property(TARGET r-type_server PROPERTY MSVC_RUNTIME_LIBRARY "")

set_target_properties(r-type_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
