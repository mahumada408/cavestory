cmake_minimum_required(VERSION 3.0)
project(cavestory)

# Project Headers
include_directories(headers)

# Added for the SDL2 libraries.
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cc")

add_executable(cavestory ${SOURCES})

# Added for SLD2 libraries.
target_link_libraries(cavestory ${SDL2_LIBRARIES})
