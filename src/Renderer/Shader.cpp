//
// Created by 가디언 on 2021-06-02.
//

#include "Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

void Shader::use() {

}

Shader::Shader(std::string vtshader_path, std::string fgshader_path) {

    vertex_shader_path=vtshader_path;
    fragment_shader_path=fgshader_path;

    vertex_shader_id=glCreateShader(GL_VERTEX_SHADER);
    fragment_shader_id=glCreateShader(GL_FRAGMENT_SHADER);

    this->is_source_loaded= loadSource();
    this->is_source_compiled= compile();
    this->is_program_made = makeProgram();


}

GLuint Shader::getProgramID() {
    return 0;
}


int Shader::compile() {
    GLint Result = GL_FALSE;
    int InfoLogLength;
    // Compile Vertex Shader
    std::cout << "Compiling Vertex shader : " << vertex_shader_path << "\n";

    char const *VertexSourcePointer = vertex_shader_code.c_str();
    glShaderSource(vertex_shader_id, 1, &VertexSourcePointer, NULL);
    glCompileShader(vertex_shader_id);

    // Check Vertex Shader
    glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(vertex_shader_id, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
        return 0;
    }

    // Compile Fragment Shader
    std::cout << "Compiling Fragment shader : " << fragment_shader_path << "\n";
    char const *FragmentSourcePointer = fragment_shader_code.c_str();
    glShaderSource(fragment_shader_id, 1, &FragmentSourcePointer, NULL);
    glCompileShader(fragment_shader_id);

    // Check Fragment Shader
    glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(fragment_shader_id, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
        return 0;
    }
    return 1;
}

Shader::~Shader() {
    glDeleteProgram(program_id);
}

int Shader::loadSource() {

    std::ifstream VertexShaderStream(vertex_shader_path.c_str(), std::ios::in);
    if (VertexShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        this->vertex_shader_code = sstr.str();
        VertexShaderStream.close();
    } else {

        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n",
               vertex_shader_path.c_str());
        getchar();
        return 0;
    }


    // Read the Fragment Shader code from the file

    std::ifstream FragmentShaderStream(fragment_shader_path, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        this->fragment_shader_code = sstr.str();
        FragmentShaderStream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n",
               fragment_shader_path.c_str());
        getchar();
        return 0;
    }
    return 1;

}

int Shader::makeProgram() {
    program_id=glCreateProgram();
    // Link the program
    std::cout << "Linking program...\n";
    GLint Result = GL_FALSE;;
    int InfoLogLength;

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);

    // Check the program
    glGetProgramiv(program_id, GL_LINK_STATUS, &Result);
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(program_id, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
        return 0;
    }


    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    return 1;
}
