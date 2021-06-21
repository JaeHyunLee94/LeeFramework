//
// Created by 이재현 on 2021/05/29.
//

#include "Camera.hpp"

void Camera::moveUp(float dt) {
    m_camera_pos = m_camera_pos + m_camera_up * dt * m_camera_up;
    updateViewMatrix();
}

void Camera::moveFront(float dt) {
    m_camera_pos = m_camera_pos + m_camera_speed * dt * m_camera_front;
    updateViewMatrix();
}
void Camera::moveRight(float dt) {
    m_camera_pos = m_camera_pos + m_camera_up * dt * m_camera_right;
    updateViewMatrix();
}

void Camera::rotateYaw(float dt) {
    float theta=glm::radians(m_camera_speed*dt);
    m_camera_front=(m_camera_front*glm::cos(theta)) - (m_camera_up*glm::sin(theta));
    m_camera_right=glm::normalize(glm::cross(m_camera_right,m_camera_front));
    updateViewMatrix();
}

void Camera::rotatePitch(float dt) {

    float theta=glm::radians(m_camera_speed*dt);
    m_camera_front=(m_camera_front*glm::cos(theta)) + (m_camera_up*glm::sin(theta));
    m_camera_up=glm::normalize(glm::cross(m_camera_right,m_camera_front));
    updateViewMatrix();

}

void Camera::logCameraProperty() {
    printf("---------------------------------\n");
    printf("camera Position: [%f,%f,%f]\n", m_camera_pos.x, m_camera_pos.y, m_camera_pos.z);
    printf("cameraFront vector: [%f,%f,%f]\n", m_camera_front.x, m_camera_front.y, m_camera_front.z);
    printf("cameraUp vector: [%f,%f,%f]\n", m_camera_up.x, m_camera_up.y, m_camera_up.z);
    printf("cameraRight vector: [%f,%f,%f]\n", m_camera_right.x, m_camera_right.y, m_camera_right.z);
    printf("fovy: %f\n", m_fovy);
    printf("aspect: %f\n", m_aspect);
    printf("z_near: %f\n", m_z_near);
    printf("z_far: %f\n", m_z_far);
    printf("---------------------------------\n");
}

void Camera::updateViewMatrix() {
    m_view_matrix = glm::lookAt(
            m_camera_pos,
            m_camera_front,
            m_camera_right
    );

}

void Camera::updateProjectionMatrix() {
    m_projection_matrix = glm::perspective(
            glm::radians(m_fovy),
            m_aspect,
            m_z_near,
            m_z_far
    );
}




