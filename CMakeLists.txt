cmake_minimum_required(VERSION 3.17)

project(r-type_server)
project(r-type_client)

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
set(UTILSROOT ${SRCROOT}/utils/)
set(EVENTSROOT ${SRCCLIENT}/events/)
set(GAMEROOT ${SRCCLIENT}/game/)
set(SCREENSROOT ${SRCCLIENT}/screens/)
set(TOOLSROOT ${SRCCLIENT}/tools/)

set(SRC_ECS
    ${ECSROOT}Entity/entity.cpp
    ${ECSROOT}Entity/entity.hpp
    ${ECSROOT}world.cpp
    ${ECSROOT}world.hpp
    ${ECSROOT}Component/Alive/alive.cpp
    ${ECSROOT}Component/Alive/alive.hpp
    ${ECSROOT}Component/Collide/collide.cpp
    ${ECSROOT}Component/Collide/collide.hpp
    ${ECSROOT}Component/Drawable2D/drawable2d.cpp
    ${ECSROOT}Component/Drawable2D/drawable2d.hpp
    ${ECSROOT}Component/Projectile/projectile.cpp
    ${ECSROOT}Component/Projectile/projectile.hpp
    ${ECSROOT}Component/Inventory/inventory.cpp
    ${ECSROOT}Component/Inventory/inventory.hpp
    ${ECSROOT}Component/Sound/sound.cpp
    ${ECSROOT}Component/Sound/sound.hpp
    ${ECSROOT}Component/Transform/transform.cpp
    ${ECSROOT}Component/Transform/transform.hpp
    ${ECSROOT}Component/IComponent.hpp
    ${ECSROOT}Component/Ship/recruit.cpp
    ${ECSROOT}Component/Ship/recruit.hpp
    ${ECSROOT}Component/Ship/zigzag.cpp
    ${ECSROOT}Component/Ship/zigzag.hpp
    ${ECSROOT}Component/Ship/AShip.cpp
    ${ECSROOT}Component/Ship/AShip.hpp
    ${ECSROOT}Component/Ship/IShip.hpp
    ${ECSROOT}System/Draw2D/draw2d.cpp
    ${ECSROOT}System/Draw2D/draw2d.hpp
    ${ECSROOT}System/Movement/movement.cpp
    ${ECSROOT}System/Movement/movement.hpp
    ${ECSROOT}System/Collide/collide.cpp
    ${ECSROOT}System/Collide/collide.hpp
    ${ECSROOT}System/Particles/particles.cpp
    ${ECSROOT}System/Particles/particles.hpp
    ${ECSROOT}System/Enemypath/enemypath.cpp
    ${ECSROOT}System/Enemypath/enemypath.hpp
    ${ECSROOT}System/ISystem.hpp
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
    ${SCREENSROOT}room/RoomScreen.cpp
    ${SCREENSROOT}room/RoomScreen.hpp
    ${SCREENSROOT}core/CoreScreen.cpp
    ${SCREENSROOT}core/CoreScreen.hpp
)

set(SRC_GAME
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(SRC_UTILS
    ${UTILSROOT}Message.hpp
    ${UTILSROOT}Rooms.hpp
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
    ${SRCCLIENT}Globals.hpp
    ${SRCCLIENT}network/Client.cpp
    ${SRCCLIENT}network/Client.hpp
    ${SRC_ECS}
    ${SRC_EVENTS}
    ${SRC_GAME}
    ${SRC_SCREENS}
    ${SRC_TOOLS}
    ${SRC_UTILS}
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
    ${SRCSERVER}network/Server.cpp
    ${SRCSERVER}network/Server.hpp
    ${SRCSERVER}network/SafeQueue.hpp
    ${SRCSERVER}network/Client.hpp
    ${SRC_ECS}
    ${SRC_UTILS}
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

set_property(TARGET r-type_client PROPERTY MSVC_RUNTIME_LIBRARY "")
set_property(TARGET r-type_server PROPERTY MSVC_RUNTIME_LIBRARY "")

set_target_properties(r-type_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
