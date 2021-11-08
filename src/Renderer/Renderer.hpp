//
// Created by 이재현 on 2021/05/29.
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
               float z_far = 1000,
               float camera_speed = 0.1); // TODO: need camera explicitly?

        Builder &light(const glm::vec3 &src_pos, const glm::vec3 &light_dir, const glm::vec3 &diff_color,
                       const glm::vec3 &spec_color, const glm::vec3 &amb_color);

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

    GLuint getVAO() const { return m_vao_id; };

    void render();

    void registerGraphicsEntity(GraphicsData t_graphics_data);

    void registerGraphicsEntity(PhysicsEntity *t_physics_entity);


private:

    void renderEach(GraphicsData &t_graphics_data);

    explicit Renderer(const Builder &builder)
            : m_window(builder.m_builder_window), m_camera(builder.m_builder_camera), m_light(builder.m_builder_light),
              m_shader(builder.m_builder_shader), m_vao_id(builder.m_builder_vao_id) {
        //TODO: check essential component
        glfwSetWindowUserPointer(m_window, this);
        //TODO: use input handler
        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mode) {

            auto &self = *static_cast<Renderer *>(glfwGetWindowUserPointer(window));
            static bool pressed[349] = {false};

            if (action == GLFW_PRESS) {
                pressed[key] = true;
            } else if (action == GLFW_RELEASE) {
                pressed[key] = false;
            }

            if (key == GLFW_KEY_W) {

                self.m_camera->moveFront(1);

            }
            if (key == GLFW_KEY_S) {

                self.m_camera->moveBack(1);

            }
            if (key == GLFW_KEY_A) {

                self.m_camera->moveLeft(1);

            }
            if (key == GLFW_KEY_D) {

                self.m_camera->moveRight(1);

            }
            if (key == GLFW_KEY_SPACE) {

                self.m_camera->moveUp(1);

            }
            if (key == GLFW_KEY_X) {

                self.m_camera->moveDown(1);

            }

        });
        glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xpos, double ypos) {

            auto &self = *static_cast<Renderer *>(glfwGetWindowUserPointer(window));

            static bool is_first = true;
            static double prev_xpos, prev_ypos;
            if (is_first) {
                prev_xpos = xpos;
                prev_ypos = ypos;

                is_first = false;
            }
            if (glfwGetMouseButton(self.m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {

                double xoffset = prev_xpos - xpos;
                double yoffset = prev_ypos - ypos;
                self.m_camera->rotateYaw( 0.5*xoffset);
                self.m_camera->rotatePitch(0.5*yoffset);


                prev_xpos = xpos;
                prev_ypos = ypos;

            }else if(glfwGetMouseButton(self.m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE){
                is_first = true;
            }


        });
        glfwSetScrollCallback(m_window,[](GLFWwindow* window,double xoffset,double yoffset){

            auto &self = *static_cast<Renderer *>(glfwGetWindowUserPointer(window));
            float fovy= self.m_camera->getFovy() -yoffset;
            if (fovy < 1.0f)
                fovy = 1.0f;
            if (fovy > 45.0f)
                fovy = 45.0f;
            self.m_camera->setFovy(fovy);

        });

    };


    Camera *m_camera = nullptr; //TODO: multiple camera
    Shader *m_shader = nullptr;
    Light *m_light = nullptr;
    GLFWwindow *m_window = nullptr;
    glm::vec3 m_default_color;

    std::vector<GraphicsData> m_graphics_data;


    //TODO: better if this list can be mapped


    GLuint m_vao_id;


};


#endif //LEEFRAMEWORK_RENDERER_HPP
