cmake_minimum_required(VERSION 3.18)

SET(PROJ_NAME PI)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC 
    "src/*.cpp"
    "include/*.h"
)
add_executable(${PROJ_NAME}
    "${SRC}"
)

target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/./include)
target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/Assembler/include)