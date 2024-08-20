cmake_minimum_required(VERSION 3.22)
include(FetchContent)

project(coding-interview-university
    VERSION 0.1
    DESCRIPTION "Coding Interview University"
    LANGUAGES CXX
)

# Debugging for CMake
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
