set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(ECSROOT ${SRCROOT}/ecs/)
set(EVENTSROOT ${SRCROOT}/events/)
set(GAMEROOT ${SRCROOT}/game/)
set(SCREENSROOT ${SRCROOT}/screens/)

set(SRC_ECS
    ${ECSROOT}Entity/Entity.cpp
    ${ECSROOT}Entity/Entity.hpp
    ${ECSROOT}world.cpp
    ${ECSROOT}world.hpp
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
    ${ECSROOT}System/ISystem.hpp
)

set(SRC_EVENTS
    ${EVENTSROOT}Events.cpp
    ${EVENTSROOT}Events.hpp
)

set(SRC_GAME
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(SRC_SCREENS
    ${SCREENSROOT}IScreen.hpp
    ${SCREENSROOT}menu/MenuScreen.cpp
    ${SCREENSROOT}menu/MenuScreen.hpp
)

set(SRC
    ${SRCROOT}main.cpp
    ${SRC_ECS}
    ${SRC_EVENTS}
    ${SRC_GAME}
    ${SRC_SCREENS}
)
    
set(INCDIRS
)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCDIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${INTERFACES_NAME})

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})