//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_RENDERER_HPP
#define LEEFRAMEWORK_RENDERER_HPP

#include "Camera.hpp"
#include "Light.hpp"
#include "Shader.hpp"
#include "GUIwrapper.hpp"
class Renderer {
//TODO: all the responsible class for rendering. the most big class
//TODO: made by java builder pattern
public:

    Camera* getCamera();
    void init();
    void addEntity();
    void render();



private:
    friend class RendererBuilder;
    Renderer();
    Camera* m_camera_; //TODO: camera can be many?
    Shader* m_shader;

    glm::vec3 m_default_color;






};
class RendererBuilder{

public:
    RendererBuilder();//essential?
    RendererBuilder& camera(Camera camera);
    RendererBuilder& light(Light light);
    RendererBuilder& gui();
    Renderer& build();


    //TODO: essential member
private:
    Camera* m_camera;
    Light* m_light;
    GUIwrapper* m_gui;



};


#endif //LEEFRAMEWORK_RENDERER_HPP
