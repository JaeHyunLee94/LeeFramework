

### google test ###

#####################


project(google_test)

#add_subdirectory(../external/googletest/)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_renderer CameraTest.cpp)
target_link_libraries(test_renderer gtest gtest_main)