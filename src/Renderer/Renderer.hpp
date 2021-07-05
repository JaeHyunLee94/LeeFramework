//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_RENDERER_HPP
#define LEEFRAMEWORK_RENDERER_HPP

#include "Camera.hpp"
#include "Light.hpp"
#include "Shader.hpp"
#include "GUIwrapper.hpp"
#include "../Mesh/Mesh.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
//TODO: all the responsible class for rendering. the most big class
//TODO: made by java builder pattern
public:


    class Builder {

    public:
        friend class Renderer;

        Builder() = default;// TODO: essential parameter
        Builder &camera(glm::vec3 camera_pos, glm::vec3 lookat, glm::vec3 up={0.,1.,0.}, float fovy=45, float aspect=1, float z_near=0.1,
                        float z_far=1000,
                        float camera_speed=0.1); // TODO: need camera explicitly?

        Builder &light(const glm::vec3& src_pos,const glm::vec3& light_dir,const glm::vec3& diff_color,const glm::vec3& spec_color,const glm::vec3& amb_color);

        Builder &shader(const char *vt_shader_path, const char *fg_shader_path);

        Builder &gui();

        Builder &init();

        Renderer *build();


        //TODO: essential member
    private:
        Renderer *m_renderer = nullptr;
        Shader *m_builder_shader = nullptr;
        Camera *m_builder_camera = nullptr;
        Light *m_builder_light = nullptr;
        GUIwrapper *m_builder_gui = nullptr;
        GLFWwindow *m_builder_window = nullptr;


    };


    ~Renderer() {
        glfwDestroyWindow(m_window);
        delete m_camera; //TODO: 각 클래스는 클래스가 가진 pointer 형 변수에 대해 delete 의 책임을 가질것!!
        delete m_shader;
        delete m_light;
        glfwTerminate();
    }
    GLFWwindow* getWindow();
    Camera& getCamera();
    Shader& getShader();
    Light& getLight();

    void addEntity(Mesh* mesh);

    void render();


private:

    explicit Renderer(const Builder &builder)
            : m_window(builder.m_builder_window), m_camera(builder.m_builder_camera),m_light(builder.m_builder_light),
              m_shader(builder.m_builder_shader) {
        //TODO: check essential component

    };
    Camera *m_camera = nullptr; //TODO: camera can be many?
    Shader *m_shader = nullptr;
    Light *m_light= nullptr;
    GLFWwindow *m_window = nullptr;
    glm::vec3 m_default_color;

    //TODO: better if this list can be map
    std::vector<Mesh*> m_entity_list;

};


#endif //LEEFRAMEWORK_RENDERER_HPP
