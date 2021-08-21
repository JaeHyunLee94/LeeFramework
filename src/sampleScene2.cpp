//
// Created by 가디언 on 2021-06-17.
//
#define GLEW_STATIC

#include "Renderer/Renderer.hpp"
#include "Geometry/PhysicsEntity.hpp"
#include <iostream>
#include "utils/UtilHeader.h"

int main() {

    PhysicsEntity pe;

    pe.setShapeTriangle(
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
            );


    auto m =pe.getShape()->getShapeVertices();
    auto e= pe.getShape()->getShapeVertexIndices();
    printf("position: (%f,%f,%f),(%f,%f,%f),(%f,%f,%f)\n",(*m)[0].x,(*m)[0].y,(*m)[0].z,(*m)[1].x,(*m)[1].y,(*m)[1].z,(*m)[2].x,(*m)[2].y,(*m)[2].z);
    printf("index: (%d,%d,%d)\n",(*e)[0].x,(*e)[0].y,(*e)[0].z);



    Renderer *renderer = Renderer::Builder()
            .init() //TODO: window parameter
            .camera(glm::vec3(3., 2., 3.),glm::vec3(0))
            .shader("../shader/VertexShader.glsl",  "../shader/FragmentShader.glsl")
            .light(glm::vec3(5.,5.,5.),
                   glm::vec3(0.,1.,1.),
                   glm::vec3(1.,1.,1.),
                   glm::vec3(1.,1.,1.),
                   glm::vec3(0,0,0))
            .build();

    renderer->getCamera().logCameraProperty();
    renderer->getLight().logLightProperty();

    renderer->registerGraphicsEntity(&pe);


    renderer->getShader().use();
    debug_glCheckError(36);

    printf("position: (%f,%f,%f),(%f,%f,%f),(%f,%f,%f)\n",(*m)[0].x,(*m)[0].y,(*m)[0].z,(*m)[1].x,(*m)[1].y,(*m)[1].z,(*m)[2].x,(*m)[2].y,(*m)[2].z);
    printf("index: (%d,%d,%d)\n",(*e)[0].x,(*e)[0].y,(*e)[0].z);

    renderer->render();



}




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
//
//    static const GLfloat g_vertex_buffer_data[] = {
//            -1.0f, -1.0f, 0.0f,
//            1.0f, -1.0f, 0.0f,
//            0.0f,  1.0f, 0.0f,
//    };
//
//    GLuint vertexbuffer;
//    glGenBuffers(1, &vertexbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//    do{
//
//        // Clear the screen
//        glClear( GL_COLOR_BUFFER_BIT );
//
//        // Use our shader
//        renderer->getShader().use();
//
//        // 1rst attribute buffer : vertices
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//        glVertexAttribPointer(
//                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//                3,                  // size
//                GL_FLOAT,           // type
//                GL_FALSE,           // normalized?
//                0,                  // stride
//                (void*)0            // array buffer offset
//        );
//
//        // Draw the triangle !
//        glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
//
//        glDisableVertexAttribArray(0);
//
//        // Swap buffers
//        glfwSwapBuffers(renderer->getWindow());
//        glfwPollEvents();
//
//    } // Check if the ESC key was pressed or the window was closed
//    while( glfwGetKey(renderer->getWindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//           glfwWindowShouldClose(renderer->getWindow()) == 0 );
//
//    // Cleanup VBO
//    glDeleteBuffers(1, &vertexbuffer);
//
//    // Close OpenGL window and terminate GLFW
//    glfwTerminate();
//
//    return 0;
//}


