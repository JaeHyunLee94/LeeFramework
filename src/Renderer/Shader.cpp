//
// Created by 가디언 on 2021-06-02.
//

#include "Shader.hpp"

void Shader::use() {

}

Shader::Shader(std::string vtshader_path, std::string fgshader_path) {

    vertex_shader_path=vtshader_path;
    fragment_shader_path=fgshader_path;

//    vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
//    fragment_shader_id=glCreateShader(GL_FRAGMENT_SHADER);



}

int Shader::getProgramID() {
    return 0;
}


int Shader::compile() {
    return 0;
}

Shader::~Shader() {

}

int Shader::loadSource() {
    return 0;
}
