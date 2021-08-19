//
// Created by 이재현 on 2021/05/29.
//

#include "Renderer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GraphicsEntity.hpp"
#include "../Geometry/PhysicsEntity.hpp"


Camera &Renderer::getCamera() {
    return *m_camera;
}


void Renderer::render() {
    debug_glCheckError(18);
    glBindVertexArray(m_vao_id);

    while (!glfwWindowShouldClose(m_window)) {

        for(auto& g_data : m_graphics_data){
            renderEach(g_data);
        }

        glfwPollEvents();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


Light &Renderer::getLight() {
    return *m_light;
}

Shader &Renderer::getShader() {
    return *m_shader;
}

GLFWwindow *Renderer::getWindow() {
    return m_window;
}

void Renderer::registerGraphicsEntity(GraphicsData t_graphics_data) {
    m_graphics_data.push_back(t_graphics_data);
}

void Renderer::registerGraphicsEntity(PhysicsEntity* t_physics_entity) {
    debug_glCheckError(59);
    glBindVertexArray(m_vao_id);
    t_physics_entity->getShape()->getShapeVertices();

    debug_glCheckError(63);
    GraphicsData tmp_graphics_data;
    GLuint vbo;
    GLuint ebo;
    glGenBuffers(1,&vbo);
    glGenBuffers(1,&ebo);

    //TODO: Graphics data add more eg) m_has_normal
    tmp_graphics_data.m_VBO=vbo;
    tmp_graphics_data.m_EBO=ebo;


    tmp_graphics_data.m_position=t_physics_entity->getShape()->getShapeVertices();
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(glm::vec3)*tmp_graphics_data.m_position->size(),tmp_graphics_data.m_position,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(glm::vec3),nullptr);
    glEnableVertexAttribArray(0);




    tmp_graphics_data.m_indices=t_physics_entity->getShape()->getShapeVertexIndices();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(glm::uvec3)*tmp_graphics_data.m_indices->size(),tmp_graphics_data.m_indices,GL_STATIC_DRAW);
    //TODO: indice : 1

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(glm::vec3), nullptr);
    glEnableVertexAttribArray(1);

    tmp_graphics_data.m_uv=t_physics_entity->getShape()->getUV();
    tmp_graphics_data.m_normal=t_physics_entity->getShape()->getNormal();
    tmp_graphics_data.m_mirror_pe=t_physics_entity;

    auto t_translateMatrix= glm::translate(t_physics_entity->getPos());
    auto t_rotateMatrix = glm::mat4 (1);//TODO
    tmp_graphics_data.m_model_matrix =t_translateMatrix*t_rotateMatrix;


    m_graphics_data.push_back(tmp_graphics_data);


}

void Renderer::renderEach(GraphicsData &t_graphics_data) {
    debug_glCheckError(108);
    //TODO: glbufferdata 로 넣어주기
    glBindBuffer(GL_ARRAY_BUFFER,t_graphics_data.m_VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,t_graphics_data.m_EBO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES,t_graphics_data.m_indices->size()*3,GL_UNSIGNED_INT, nullptr);
    debug_glCheckError(116);
}


Renderer::Builder &Renderer::Builder::camera(glm::vec3 camera_pos,
                                             glm::vec3 lookat,
                                             glm::vec3 up,
                                             float fovy,
                                             float aspect,
                                             float z_near,
                                             float z_far,
                                             float camera_speed) {

    m_builder_camera = new Camera(camera_pos, lookat, up, fovy, aspect, z_near, z_far, camera_speed);
    return *this;
}

Renderer::Builder &Renderer::Builder::light(const glm::vec3& src_pos,const glm::vec3& light_dir,const glm::vec3& diff_color,const glm::vec3& spec_color,const glm::vec3& amb_color) {
    m_builder_light = new Light(src_pos,light_dir,diff_color,spec_color,amb_color);
    return *this;
}

Renderer::Builder &Renderer::Builder::gui() {
    return *this;
}

Renderer *Renderer::Builder::build() {

    //TODO: check essential component
    m_renderer = new Renderer(*this);


    return m_renderer;
}

Renderer::Builder &Renderer::Builder::init() {

#define GLEW_STATIC

    int m_is_glfw_init = glfwInit(); //TODO: if statement add or try catch ??
    if (!m_is_glfw_init)
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
    if (m_builder_window == nullptr) {
        std::cout << "window creation failed\n";
    }

    glfwMakeContextCurrent(m_builder_window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader


    bool err = glewInit() != GLEW_OK;

    if (err) {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
    }

    glGenVertexArrays(1,&m_builder_vao_id);
    glBindVertexArray(m_builder_vao_id);

    return *this;
}

Renderer::Builder &Renderer::Builder::shader(const char *vt_shader_path, const char *fg_shader_path) {
    m_builder_shader = new Shader(vt_shader_path, fg_shader_path);
    m_builder_shader->use();
    return *this;
}


