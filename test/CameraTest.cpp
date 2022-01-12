//
// Created by 가디언 on 2021-06-10.


#include "../src/Renderer/Camera.hpp"
#include <gtest/gtest.h>

TEST(CAMERA_TEST,CAMERA_TEST_UP){
    Camera c(glm::vec3 (1,1,1), glm::vec3(0,0,0), glm::vec3(1,1,1), 0.1,  5,
             2,  4);

    EXPECT_EQ(2,c.sum(1,1));
}


int main(int argc,char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}