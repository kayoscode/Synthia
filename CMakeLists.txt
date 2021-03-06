cmake_minimum_required(VERSION 3.16)

SET(PROJ_NAME PI)

project(${PROJ_NAME})

add_subdirectory(openal-soft)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC 
    "src/*.cpp"
    "include/*.h"
)

add_executable(${PROJ_NAME}
    "${SRC}"
)

target_link_libraries(${PROJ_NAME} PRIVATE OpenAL)

target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/./include)
target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/openal-soft/include/AL)