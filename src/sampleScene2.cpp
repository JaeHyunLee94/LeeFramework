//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include <iostream>

int main() {

    Renderer *renderer = Renderer::Builder()
            .init()
            .build();

    renderer->render();

}




