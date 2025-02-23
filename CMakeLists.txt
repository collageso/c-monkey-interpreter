cmake_minimum_required(VERSION 3.10)

project(CMonkeyInterpreter VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(c-monkey-interpreter ${SOURCES} ${HEADERS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
