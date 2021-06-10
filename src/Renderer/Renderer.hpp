//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_RENDERER_HPP
#define LEEFRAMEWORK_RENDERER_HPP

#include "Camera.hpp"
#include "Light.hpp"
#include "Shader.hpp"

class Renderer {
//TODO: all the responsible class for rendering. the most big class
public:
    Camera* getCamera();
    Light* getLight();
    void addEntity();
    void render();

private:

    Camera m_camera_; //TODO: camera can be many?
    Light m_light;
    Shader m_shader;

    glm::vec3 m_default_color;






};


#endif //LEEFRAMEWORK_RENDERER_HPP
