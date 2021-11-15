//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include "Geometry/PhysicsEntity.hpp"
#include <iostream>
#include "utils/UtilHeader.h"
#include "Geometry/MeshLoader.hpp"


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

    renderer->getCamera().logCameraProperty();
    renderer->getLight().logLightProperty();

    renderer->registerGraphicsEntity(&pe1);
    renderer->registerGraphicsEntity(&pe2);
    renderer->registerGraphicsEntity(&pe3);
    renderer->registerGraphicsEntity(&pe4);

    renderer->render();


}



//
//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//
//// Include GLEW
//#include <GL/glew.h>
//
//// Include GLFW
//#include <GLFW/glfw3.h>
//
//
//// Include GLM
//#include <glm/glm.hpp>
//using namespace glm;
//
//#include "Renderer/Renderer.hpp"
//
//int main( void )
//{
//
//
//    Renderer *renderer = Renderer::Builder()
//            .init() //TODO: window parameter
//            .camera(glm::vec3(3., 2., 3.),glm::vec3(0))
//            .shader("../shader/VertexShader.glsl",  "../shader/FragmentShader.glsl")
//            .light(glm::vec3(5.,5.,5.),
//                   glm::vec3(0.,1.,1.),
//                   glm::vec3(1.,1.,1.),
//                   glm::vec3(1.,1.,1.),
//                   glm::vec3(0,0,0))
//            .build();
//
//    // Create and compile our GLSL program from the shaders
//
//
//    std::vector<glm::vec3> g_vertex_buffer_data;
//    g_vertex_buffer_data.emplace_back(-1.0f, -1.0f, 0.0f);
//    g_vertex_buffer_data.emplace_back(1.0f, -1.0f, 0.0f);
//    g_vertex_buffer_data.emplace_back(0.0f,  1.0f, 0.0f);
//
//
//
////    GLuint vertexbuffer;
////    glGenBuffers(1, &vertexbuffer);
////    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
////    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*g_pointer->size(), g_pointer->data(), GL_STATIC_DRAW);
//    GLuint vertexbuffer;
//    {
//        GLuint _vertexbuffer;
//        std::vector<glm::vec3>* g_pointer= &g_vertex_buffer_data;
//        glGenBuffers(1, &_vertexbuffer);
//        glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*g_pointer->size(), g_pointer->data(), GL_STATIC_DRAW);
//        vertexbuffer=_vertexbuffer;
//    }
//
//    //glBindVertexArray(renderer->getVAO());
//    while (!glfwWindowShouldClose(renderer->getWindow())) {
//
//        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
//        glVertexAttribPointer(
//                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//                3,                  // size
//                GL_FLOAT,           // type
//                GL_FALSE,           // normalized?
//                0,                  // stride
//                (void*)0            // array buffer offset
//        );
//        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,t_graphics_data.m_EBO);
//        //std::cout << &(*t_graphics_data.m_position)[0].x << "\n";
//
//
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        //glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
//
//        glDisableVertexAttribArray(0);
//
//        // Swap buffers
//        glfwSwapBuffers(renderer->getWindow());
//        glfwPollEvents();
//        int display_w, display_h;
//        glfwGetFramebufferSize(renderer->getWindow(), &display_w, &display_h);
//        glViewport(0, 0, display_w, display_h);
//    }
//
//
////    do{
////
////        // Clear the screen
////        glClear( GL_COLOR_BUFFER_BIT );
////
////        // Use our shader
////        renderer->getShader().use();
////
////        // 1rst attribute buffer : vertices
////        glEnableVertexAttribArray(0);
////        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
////        glVertexAttribPointer(
////                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
////                3,                  // size
////                GL_FLOAT,           // type
////                GL_FALSE,           // normalized?
////                0,                  // stride
////                (void*)0            // array buffer offset
////        );
////
////        // Draw the triangle !
////        glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
////
////        glDisableVertexAttribArray(0);
////
////        // Swap buffers
////        glfwSwapBuffers(renderer->getWindow());
////        glfwPollEvents();
////
////    } // Check if the ESC key was pressed or the window was closed
////    while( glfwGetKey(renderer->getWindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
////           glfwWindowShouldClose(renderer->getWindow()) == 0 );
//
//    // Cleanup VBO
//    glDeleteBuffers(1, &vertexbuffer);
//
//    // Close OpenGL window and terminate GLFW
//    glfwTerminate();
//
//    return 0;
//}


