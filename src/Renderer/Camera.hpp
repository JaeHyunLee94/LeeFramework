//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_CAMERA_HPP
#define LEEFRAMEWORK_CAMERA_HPP

#include <glm/glm.hpp>

class Camera {

public:
    Camera(glm::vec3 camera_pos,glm::vec3 lookat,glm::vec3 up ,float fovy, float aspect, float z_near,float z_far);
    inline glm::mat4 getViewMatrix(){return view_matrix_;};
    inline  glm::mat4 getProjectionMatrix(){return projection_matrix_;};

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

    glm::mat4 projection_matrix_;
    glm::mat4 view_matrix_;


};


#endif //LEEFRAMEWORK_CAMERA_HPP
