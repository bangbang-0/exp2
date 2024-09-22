cmake_minimum_required(VERSION 3.29)
project(exp2)

set(CMAKE_CXX_STANDARD 11)


set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(exp2 ${SOURCES})