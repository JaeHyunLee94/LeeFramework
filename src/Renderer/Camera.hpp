//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_CAMERA_HPP
#define LEEFRAMEWORK_CAMERA_HPP

#include <glm/glm.hpp>
#include <iostream>

class Camera {

public:
    Camera(){};
    Camera(glm::vec3 camera_pos, glm::vec3 lookat, glm::vec3 up, float fovy, float aspect, float z_near, float z_far,
           float camera_speed) :
            m_camera_pos(camera_pos), m_camera_up(up), m_fovy(fovy), m_aspect(aspect), m_z_near(z_near), m_z_far(z_far),
            m_camera_speed(camera_speed) {


    }; //TODO: set default value and camera member
    inline glm::mat4 getViewMatrix() { return m_view_matrix; };

    inline glm::mat4 getProjectionMatrix() { return m_projection_matrix; };

    void moveUp(float dt);

    void moveFront(float dt);

    void rotateYaw(float dt);

    void rotatePitch(float dt);

    inline void setCameraSpeed(float speed) { this->m_camera_speed = speed; };

    void logCameraProperty();
    int sum(int a ,int b ){return a+b;}; // for google test

private:

    //Camera property
    glm::vec3 m_camera_pos;
    glm::vec3 m_camera_up;
    glm::vec3 m_camera_front;

    float m_z_near;
    float m_z_far;
    float m_aspect;
    float m_fovy;
    float m_camera_speed;

    glm::mat4 m_projection_matrix;
    glm::mat4 m_view_matrix;


};


#endif //LEEFRAMEWORK_CAMERA_HPP
