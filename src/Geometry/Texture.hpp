//
// Created by test on 2021-07-02.
//

#ifndef ASSIMP_TEXTURE_HPP
#define ASSIMP_TEXTURE_HPP

#include <GL/glew.h>
#include <string>

class Texture {
public:

    Texture();
//    Texture(const char* fileName,GLenum type);
//    void load(const char* fileName,GLenum type);
private:
    GLuint m_textureID;
    int m_width, m_height, m_channels;

    std::string typeName;
    std::string fileName;
};


#endif //ASSIMP_TEXTURE_HPP
