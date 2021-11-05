//
// Created by Lee on 2021-11-04.
//

#include "InputHandler.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.hpp"

void InputHandler::handleInput() {

    Camera &camera = m_parent_renderer->getCamera();


    //Key process
    for (int i = 0; i < KEYS; i++) {
        if (!m_pressed[i]) continue;

        switch (i) {
            case GLFW_KEY_W:
                camera.moveFront();
                break;
            case GLFW_KEY_A:
                camera.moveLeft();
                break;
            case GLFW_KEY_S:
                camera.moveBack();
                break;
            case GLFW_KEY_D:
                camera.moveRight();
                break;
            case GLFW_KEY_X:
                camera.moveDown();
                break;
            case GLFW_KEY_SPACE:
                camera.moveUp();
                break;

        }

    }

    //mouse process

    if (is_left_mouse_pressed) {
        if(is_click_first) {
            m_cursor_previous_x_pos=m_cursor_x_pos;
            m_cursor_previous_y_pos=m_cursor_y_pos;
            is_click_first=false;
        }

        double xoffset = m_cursor_previous_x_pos - m_cursor_x_pos;
        double yoffset = m_cursor_previous_y_pos - m_cursor_y_pos;
        camera.rotateYaw(xoffset);
        camera.rotatePitch(yoffset);

        m_cursor_previous_x_pos=m_cursor_x_pos;
        m_cursor_previous_y_pos=m_cursor_y_pos;


    }else{
        is_click_first=true;
    }


    //scroll process

    float fovy = camera.getFovy() - m_scroll_y_offset;
    if (fovy < 1.0f)
        fovy = 1.0f;
    if (fovy > 45.0f)
        fovy = 45.0f;
    camera.setFovy(fovy);


}


