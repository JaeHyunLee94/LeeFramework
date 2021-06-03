cmake_minimum_required(VERSION 3.11)
project(
        leeFramework
        VERSION 0.0
        DESCRIPTION "physics Engine project"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)

message("Processing top level CMakeLists.txt")

add_executable(leeFramework src/sampleScene.cpp src/Handler/Handler.cpp src/Handler/Handler.hpp src/Mesh/Mesh.cpp src/Mesh/Mesh.hpp src/Renderer/Shader.cpp src/Renderer/Shader.hpp src/Renderer/Light.cpp src/Renderer/Light.hpp utils/mathUtils.cpp utils/debugUtils.cpp)