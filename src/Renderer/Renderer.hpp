//
// Created by Lee on 2021/05/29.
//

#ifndef LEEFRAMEWORK_RENDERER_HPP
#define LEEFRAMEWORK_RENDERER_HPP

#include <vector>
#include "GraphicsEntity.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Shader.hpp"
#include "GUIwrapper.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../utils/UtilHeader.h"
#include "InputHandler.hpp"

class PhysicsEntity;


class Renderer {
//TODO: all the responsible class for rendering. the most big class
// TODO: add renderable entity interface class
public:


    class Builder {

    public:
        friend class Renderer;

        Builder() = default;// TODO: essential parameter
        Builder &
        camera(glm::vec3 camera_pos, glm::vec3 lookat, glm::vec3 up = {0., 0., 1.}, float fovy = 45, float aspect = 1,
               float z_near = 0.1,
               float z_far = 1000); // TODO: need camera explicitly?

        Builder &light(const glm::vec3 &src_pos, const glm::vec3 &light_dir, const glm::vec3 &diff_color,
                       const glm::vec3 &spec_color, const glm::vec3 &amb_color);

        Builder &shader(const char *vt_shader_path, const char *fg_shader_path);

        Builder &init();

        Renderer *build();


        //TODO: essential member
    private:
        Renderer *m_renderer = nullptr;
        Shader *m_builder_shader = nullptr;
        Camera *m_builder_camera = nullptr;
        Light *m_builder_light = nullptr;
        GLFWwindow *m_builder_window = nullptr;
        GLuint m_builder_vao_id = 0;


    };


    ~Renderer() {
        glfwDestroyWindow(m_window);
        delete m_camera; //TODO: 각 클래스는 클래스가 가진 pointer 형 변수에 대해 delete 의 책임을 가질것!!
        delete m_shader;
        delete m_light;
        glfwTerminate();
    }

    GLFWwindow *getWindow();

    Camera &getCamera();

    Shader &getShader();

    Light &getLight();

    float m_background_color[4]{0.45f, 0.55f, 0.60f, 1.00f};

    GLuint getVAO() const { return m_vao_id;};

    void render();
    void render(GUIwrapper& gui);


//    void bindVAO(GLuint vao);
//    void bindVBO();
    void registerGraphicsEntity(GraphicsData t_graphics_data);

    void registerGraphicsEntity(PhysicsEntity *t_physics_entity);


private:

    void renderEach(GraphicsData &t_graphics_data);

    explicit Renderer(const Builder &builder)
            : m_window(builder.m_builder_window), m_camera(builder.m_builder_camera), m_light(builder.m_builder_light),
              m_shader(builder.m_builder_shader), m_vao_id(builder.m_builder_vao_id){
    };


    /*
     *  made with Builder class
     */
    Camera *m_camera = nullptr; //TODO: multiple camera
    Shader *m_shader = nullptr;
    Light *m_light = nullptr;
    GLFWwindow *m_window = nullptr;


    std::vector<GraphicsData> m_graphics_data;

    //TODO: better if this list can be mapped


    GLuint m_vao_id;


};


#endif //LEEFRAMEWORK_RENDERER_HPP
