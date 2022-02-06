//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include "Renderer/GUIwrapper.hpp"
#include "Physics/PhysicsEntity.hpp"
#include <iostream>
#include "utils/UtilHeader.h"
#include "IO/MeshLoader.hpp"
#include "Physics/PhyEngine.hpp"


int main() {

    PhysicsEntity pe1;
    pe1.setShapeTriangle(
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
    );

    PhysicsEntity pe2;
    pe2.setShapeTriangle(
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
    );
    pe2.setPos(glm::vec3(0,0,1));

    PhysicsEntity pe3;
    pe3.setShapeTriangle(
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
    );
    pe3.setPos(glm::vec3(0,0,2));


    PhysicsEntity pe4;
    pe4.setMass(1);

    pe4.setShapeBox(0.2,0.2,0.2);
    pe4.setShapeTriangle(-1.0f, -1.0f, 0.0f,
                         1.0f, -1.0f, 0.0f,
                         0.0f,  1.0f, 0.0f);
    pe4.setShapeBox(0.2,0.2,0.2);


    MeshLoader loader;
    loader.load("../assets/ChessKing.obj");
    Renderer *renderer = Renderer::Builder()
            .init() //TODO: window parameter
            .camera(glm::vec3(0., -2., 0.),glm::vec3(0,0,0))
            .shader("../shader/VertexShader.glsl",  "../shader/FragmentShader.glsl")
            .light(glm::vec3(5.,5.,5.),
                   glm::vec3(1.,1.,-1.),
                   glm::vec3(1.,1.,1.),
                   glm::vec3(0.1,0.1,0.1),
                   glm::vec3(0,0,0))
            .build();

    auto handler = new InputHandler(renderer,renderer->getWindow());
    GUIwrapper guiwrapper;

    guiwrapper
    .init(renderer->getWindow())
        .startGroup("Application Profile")
            .addWidgetText("Application average %.3f ms/frame (%.1f FPS)",1000.0f/guiwrapper.getIO().Framerate,guiwrapper.getIO().Framerate).endGroup()
        .startGroup("Render Setting")
            .addWidgetColorEdit3("BackGround Color",renderer->m_background_color)
            .addWidgetColorEdit3("Default Entity Color",renderer->m_default_color_diffuse)
            .addCheckBox("Draw Wire Frame",&renderer->m_is_draw_wireframe)
        .endGroup()
    .build();

    renderer->getCamera().logCameraProperty();
    renderer->getLight().logLightProperty();

    renderer->registerGraphicsEntity(&pe1);
    renderer->registerGraphicsEntity(&pe2);
    renderer->registerGraphicsEntity(&pe3);
    renderer->registerGraphicsEntity(&pe4);

    Engine::World world;
    world.create();

    world.addEntity(&pe4);
    world.setGravity(glm::vec3(0,0,-0.098));
    world.setTimeStep(1.f/600);

    glBindVertexArray(renderer->getVAO());
    //TODO: no loop in render function
    while (!glfwWindowShouldClose(renderer->getWindow())) {
        renderer->render(guiwrapper); //render with GUI
        handler->handleInput();
        world.stepWorld();
    }
    renderer->terminate();
}




