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
include_directories(${PROJECT_SOURCE_DIR}/external/glew/include)
link_directories(${PROJECT_SOURCE_DIR}/external/glew/lib)


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
add_executable(leeFramework src/sampleScene.cpp  ${imgui_src} "external/glew/include/GL/glew.c" "external/glew/include/GL/glew.h")
#add_executable(leeFramework ${helloworld_SRC})
target_link_libraries(leeFramework ${OPENGL_LIBRARIES})
#target_link_libraries(leeFramework${GLUT_LIBRARIES})
target_link_libraries(leeFramework glfw ${GLFW_LIBRARIES})


