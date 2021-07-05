cmake_minimum_required(VERSION 3.10)
project(
        leeFramework
        VERSION 0.0
        DESCRIPTION "physics Engine project"
        LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 14)

message("Processing top level CMakeLists.txt")


find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH};
        ${CMAKE_SOURCE_DIR}/external/glfw/CMake;
        ${CMAKE_SOURCE_DIR}/external/assimp/cmake-modules;
        )

### GLFW
message("processing GLFW...")
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
include_directories(${PROJECT_SOURCE_DIR}/external/glfw/include)

#### GLEW
message("processing GLEW...")
file(GLOB glew_src  "external/glew/include/GL/glew.h" "external/glew/include/GL/glew.c")
include_directories(${PROJECT_SOURCE_DIR}/external/glew/include)



### glm
message("include glm..")
include_directories(${PROJECT_SOURCE_DIR}/external/glm)

### Eigen library
message("include Eigen...")
include_directories(${PROJECT_SOURCE_DIR}/external/eigen-3.3.9/)


### imgui library
file(GLOB imgui_src  "external/imgui/include/imgui/*.cpp" "external/imgui/include/imgui/*.h")
include_directories(external/imgui/include)


### assimp ###
message("Processing assimp")
#find_package(ASSIMP REQUIRED)
#if(ASSIMP_FOUND)
#    message("assimp found")
#    include_directories(${ASSIMP_INCLUDE_DIR})
#endif()
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "ASSIMP_BUILD_TESTS")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/assimp")
include_directories(${PROJECT_SOURCE_DIR}/external/assimp/include)
###############

### google test ###
add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest)
include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)
#add_subdirectory(${PROJECT_SOURCE_DIR}/test)


file(GLOB all_src  "src/Renderer/*.cpp" "src/Renderer/*.hpp" "src/Mesh/*.cpp" "src/Mesh/*.hpp")

## add target
add_executable(leeFramework src/sampleScene.cpp  ${imgui_src} ${glew_src} ${all_src} test/CameraTest.cpp src/Mesh/ToyMesh.cpp src/Mesh/ToyMesh.hpp)
add_executable(sampleScene2 src/sampleScene2.cpp  ${glew_src} ${all_src})

target_link_libraries(leeFramework ${OPENGL_LIBRARIES})
target_link_libraries(leeFramework glfw ${GLFW_LIBRARIES})
target_link_libraries(leeFramework ${ASSIMP_LIBRARIES})

target_link_libraries(sampleScene2 ${OPENGL_LIBRARIES})
target_link_libraries(sampleScene2 glfw ${GLFW_LIBRARIES})
target_link_libraries(sampleScene2 ${ASSIMP_LIBRARIES})



