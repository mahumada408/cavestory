cmake_minimum_required(VERSION 3.0)
project(cavestory)

# Headers
include_directories(source/headers)

file(SOURCES "source/src/*.cc")

add_executable(cavestory ${SOURCES})