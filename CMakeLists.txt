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

set(SRC_ECS
    ${ECSROOT}Entity/Entity.cpp
    ${ECSROOT}Entity/Entity.hpp
    ${ECSROOT}world.cpp
    ${ECSROOT}world.hpp
    ${ECSROOT}System/ISystem.hpp
    ${ECSROOT}Component/Alive/Alive.cpp
    ${ECSROOT}Component/Alive/Alive.hpp
    ${ECSROOT}Component/Collide/Collide.cpp
    ${ECSROOT}Component/Collide/Collide.hpp
    ${ECSROOT}Component/Destroyable/Destroyable.cpp
    ${ECSROOT}Component/Destroyable/Destroyable.hpp
    ${ECSROOT}Component/Drawable2D/Drawable2D.cpp
    ${ECSROOT}Component/Drawable2D/Drawable2D.hpp
    ${ECSROOT}Component/Explodable/Explodable.cpp
    ${ECSROOT}Component/Explodable/Explodable.hpp
    ${ECSROOT}Component/Inventory/Inventory.cpp
    ${ECSROOT}Component/Inventory/Inventory.hpp
    ${ECSROOT}Component/Sound/Sound.cpp
    ${ECSROOT}Component/Sound/Sound.hpp
    ${ECSROOT}Component/Transform/Transform.cpp
    ${ECSROOT}Component/Transform/Transform.hpp
    ${ECSROOT}Component/IComponent.hpp
    ${ECSROOT}System/Draw2D/Draw2D.cpp
    ${ECSROOT}System/Draw2D/Draw2D.hpp
)

set(SRC_SCREENS
    ${SCREENSROOT}IScreen.hpp
    ${SCREENSROOT}menu/MenuScreen.cpp
    ${SCREENSROOT}menu/MenuScreen.hpp
)

set(SRC_GAME
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(SRC_EVENTS
    ${EVENTSROOT}Events.cpp
    ${EVENTSROOT}Events.hpp
)

set(SRC_CLIENT
    ${SRCCLIENT}main.cpp
    ${SRCCLIENT}network/client.cpp
    ${SRCCLIENT}network/client.hpp
    ${SRC_ECS}
    ${SRC_EVENTS}
    ${SRC_GAME}
    ${SRC_SCREENS}
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
    ${SRC_ECS}

)

add_executable(r-type_server ${SRC_SERVER})

target_link_libraries(r-type_server
			CONAN_PKG::boost
			CONAN_PKG::sfml
			)

target_include_directories(r-type_server PUBLIC
			${CONAN_INCLUDE_DIRS_BOOST}
			)

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set_target_properties(r-type_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
