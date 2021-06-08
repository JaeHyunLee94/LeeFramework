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
    void addEntity();
    void render();

private:

    Camera camera_; //TODO: camera can be many?
    Light light;
    Shader shader;





};


#endif //LEEFRAMEWORK_RENDERER_HPP
