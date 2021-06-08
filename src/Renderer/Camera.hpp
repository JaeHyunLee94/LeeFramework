//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_CAMERA_HPP
#define LEEFRAMEWORK_CAMERA_HPP

#include <glm/glm.hpp>

class Camera {

public:
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    void moveUp(float dt);
    void moveFront(float dt);
    void rotateYaw(float dt);
    void rotatePitch(float dt);


private:

    //Camera property
    glm::vec3 camera_pos_;
    glm::vec3 camera_up_;
    glm::vec3 camera_lookat_;
    float z_near_;
    float z_far_;
    float aspect_;
    float fovy_;
    float camera_speed_;

    glm::mat4 projection_transform_;
    glm::mat4 view_transform_;


};


#endif //LEEFRAMEWORK_CAMERA_HPP
