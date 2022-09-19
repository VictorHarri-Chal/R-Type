set(INCROOT ${PROJECT_SOURCE_DIR}/src)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC)

set(INCDIRS ${INCROOT})

source_group("" FILES ${SRC})

set(TARGET_NAME R-Type)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)

add_custom_command(
  TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}>
          ${PROJECT_SOURCE_DIR})