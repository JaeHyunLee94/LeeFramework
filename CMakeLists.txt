cmake_minimum_required(VERSION 3.11)
project(
        leeFramework
        VERSION 0.0
        DESCRIPTION "physics Engine project"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)

message("Processing top level CMakeLists.txt")


find_package(OpenGL REQUIRED)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH};
        ${CMAKE_SOURCE_DIR}/external/glfw/CMake;

        )

### GLFW
message("processing GLFW...")
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
include_directories(${PROJECT_SOURCE_DIR}/external/glfw/include)

#### GLEW
#message("processing GLEW...")
#include_directories(${PROJECT_SOURCE_DIR}/external/glew/include)
#link_directories(${PROJECT_SOURCE_DIR}/external/glew/lib)

include_directories(${PROJECT_SOURCE_DIR}/external/GLAD/include)
link_directories(${PROJECT_SOURCE_DIR}/external/GLAD/lib)

### glm
message("include glm..")
include_directories(${PROJECT_SOURCE_DIR}/external/glm)

### Eigen library
message("include Eigen...")
include_directories(${PROJECT_SOURCE_DIR}/external/eigen-3.3.9/)


### imgui library

#find_package(imgui REQUIRED)
file(GLOB imgui_src  "src/Renderer/imgui/*.cpp" "src/Renderer/imgui/*.h")


## add target
add_executable(leeFramework src/sampleScene.cpp src/Handler/Handler.cpp src/Handler/Handler.hpp src/Mesh/Mesh.cpp src/Mesh/Mesh.hpp src/Renderer/Shader.cpp src/Renderer/Shader.hpp src/Renderer/Light.cpp src/Renderer/Light.hpp src/utils/mathUtils.cpp src/utils/debugUtils.cpp ${imgui_src})
#add_executable(leeFramework ${helloworld_SRC})
target_link_libraries(leeFramework ${OPENGL_LIBRARIES})
target_link_libraries(leeFramework glfw ${GLFW_LIBRARIES})
target_link_libraries(leeFramework libglad_lib.dylib)
