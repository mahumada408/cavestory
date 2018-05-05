cmake_minimum_required(VERSION 3.0.0)
project(cavestory)

include(CTest)
enable_testing()

# add_executable(cavestory main.cpp)

# Project Headers
include_directories(headers)

# Added for the SDL2 libraries.
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Adding all .cc files in the src directory
file(GLOB SOURCES "src/*.cc")

add_executable(cavestory ${SOURCES})

# Added for SLD2 libraries.
target_link_libraries(cavestory ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
