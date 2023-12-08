cmake_minimum_required(VERSION 3.1...3.27)

project(
    AdventOfCode
    VERSION 1.0
    LANGUAGES C CXX ASM
)

add_subdirectory(Days)

add_executable(AdventOfCode main.cpp)

target_link_libraries(AdventOfCode PRIVATE AdventOfCodeLibrary)