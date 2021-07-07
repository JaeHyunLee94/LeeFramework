//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include <iostream>

int main() {

    Renderer *renderer = Renderer::Builder()
            .init() //TODO: window parameter
            .camera(glm::vec3(10., 8., 10.),glm::vec3(0))
            .shader("../shader/VertexShader.glsl",  "../shader/FragmentShader.glsl")
            .light(glm::vec3(5.,5.,5.),
                   glm::vec3(0.,1.,1.),
                   glm::vec3(1.,1.,1.),
                   glm::vec3(1.,1.,1.),
                   glm::vec3(0,0,0))
            .build();

    renderer->getCamera().logCameraProperty();
    renderer->getLight().logLightProperty();
    renderer->render();

}




