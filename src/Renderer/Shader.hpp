//
// Created by 가디언 on 2021-06-02.
//

#ifndef LEEFRAMEWORK_SHADER_HPP
#define LEEFRAMEWORK_SHADER_HPP
#include <string>


class Shader {
//TODO: int -> GLuint

public:
    Shader(std::string vtshader_path, std::string fgshader_path); //TODO: member initialization
    ~Shader();
    void use();
    int getProgramID();


private:
    //glsl file path
    std::string vertex_shader_path;
    std::string fragment_shader_path;

    //shader code in string form
    std::string vertex_shader_code;
    std::string fragment_shader_code;

    int program_id;
    int fragment_shader_id;
    int vertex_shader_id;

    int loadSource();
    int compile();



};


#endif //LEEFRAMEWORK_SHADER_HPP
