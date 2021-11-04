//
// Created by Lee on 2021-11-04.
//

#ifndef LEEFRAMEWORK_INPUTHANDLER_H
#define LEEFRAMEWORK_INPUTHANDLER_H


#include <vector>

class InputHandler {


public:
    InputHandler():m_pressed(349,false){

    };

    //TODO: all the input processed here
    void handleInput();//run every frame + mouse moved
    inline void setIsKeyPressed(int index,bool is_pressed){m_pressed[index]=is_pressed;};
    inline void setCursorPos(double x, double y){ this->m_cursor_x_pos= x; this->m_cursor_y_pos=y; };
    inline void setIsClickedFirst(bool is_first){this->is_click_first=is_first;};
    inline void setScrollOffset(double x , double y){this->m_scroll_x_offset=x;this->m_scroll_y_offset=y;};







private:


    double m_scroll_x_offset,m_scroll_y_offset;
    double m_cursor_x_pos,m_cursor_y_pos;
    double m_cursor_previous_x_pos,m_cursor_previous_y_pos;
    bool is_click_first=false;
    bool is_left_mouse_pressed=false;
    bool is_left_mouse_released=false;
    std::vector<bool> m_pressed;

};


#endif //LEEFRAMEWORK_INPUTHANDLER_H
