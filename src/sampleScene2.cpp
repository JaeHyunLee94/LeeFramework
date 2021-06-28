//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include <iostream>

int main() {

    Renderer *renderer = Renderer::Builder()
            .init()
            .camera(glm::vec3(1., 1., 1.),glm::vec3(0))
            .shader("../shader/VertexShader.glsl",  "../shader/FragmentShader.glsl")
            .build();

    renderer->getCamera().logCameraProperty();
    renderer->render();

}




