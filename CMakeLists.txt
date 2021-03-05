cmake_minimum_required(VERSION 3.16)

SET(PROJ_NAME PI)

project(${PROJ_NAME})

find_path (
    OPENAL_INCLUDE_DIR
    al.h
    REQUIRED
    HINTS
        "C:/Program Files (x86)/OpenAL 1.1 SDK/include"
    PATHS
        "C:/Program Files (x86)/OpenAL 1.1 SDK/include"
)

find_library (
    OPENAL_LIB_DIR
    OpenAl32.lib
    REQUIRED
        "C:/Program Files (x86)/OpenAL 1.1 SDK/libs/Win64"
    PATHS
        "C:/Program Files (x86)/OpenAL 1.1 SDK/libs/Win64"
)

message(STATUS "OpenAL include dir: ${OPENALDIR}")
message(STATUS "OpenAL library dir: ${OPENAL_LIB_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC 
    "src/*.cpp"
    "include/*.h"
)

add_executable(${PROJ_NAME}
    "${SRC}"
)

target_link_libraries(${PROJ_NAME} PRIVATE "${OPENAL_LIB_DIR}/OpenAL32.lib")

target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/./include)
target_include_directories("${PROJ_NAME}" PRIVATE ${OPENAL_INCLUDE_DIR})