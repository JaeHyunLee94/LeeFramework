cmake_minimum_required(VERSION 3.11)
project(
        leeFramework
        VERSION 0.0
        DESCRIPTION "physics Engine project"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)

message("Processing top level CMakeLists.txt")

add_executable(leeFramework src/main.cpp)