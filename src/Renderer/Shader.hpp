//
// Created by 가디언 on 2021-06-02.
//

#ifndef LEEFRAMEWORK_SHADER_HPP
#define LEEFRAMEWORK_SHADER_HPP
#include <string>
#include <GL/glew.h>


class Shader {

public:
    Shader(std::string vtshader_path, std::string fgshader_path)
        : is_source_loaded(false), is_source_compiled(false), is_program_made(false);

    ~Shader();

    void use();
    GLuint getProgramID();


private:
    //glsl file path
    std::string vertex_shader_path;
    std::string fragment_shader_path;

    //shader code in string form
    std::string vertex_shader_code;
    std::string fragment_shader_code;

    GLuint program_id;
    GLuint fragment_shader_id;
    GLuint vertex_shader_id;

    bool is_source_loaded;
    bool is_source_compiled;
    bool is_program_made;

    //for initilaze shader
    int loadSource();
    int compile();
    int makeProgram();

    //TODO: set Uniform and texture
};


#endif //LEEFRAMEWORK_SHADER_HPP
