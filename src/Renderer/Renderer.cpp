//
// Created by 이재현 on 2021/05/29.
//

#include "Renderer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
Camera *Renderer::getCamera() {
    return nullptr;
}

void Renderer::addEntity() {

}

void Renderer::render() {

    while (!glfwWindowShouldClose(m_window))
    {



        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(m_window);
    }
}




Light *Renderer::getLight() {
    return nullptr;
}



Renderer::Builder &Renderer::Builder::camera(Camera camera) {

    return *this;
}

Renderer::Builder &Renderer::Builder::light(Light light) {
    return *this;
}

Renderer::Builder &Renderer::Builder::gui() {
    return *this;
}

Renderer *Renderer::Builder::build() {

    m_renderer=new Renderer(*this);


    return m_renderer;
}

Renderer::Builder &Renderer::Builder::init() {



    m_is_glfw_init=glfwInit(); //TODO: if statement add or try catch
    if(!m_is_glfw_init)
        std::cout << "glfw init failed\n";


#if defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    m_builder_window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (m_builder_window == NULL){}

    glfwMakeContextCurrent(m_builder_window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader


    bool err = glewInit() != GLEW_OK;

    if (err) {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        m_is_glew_init=false;
    }


    return *this;
}


