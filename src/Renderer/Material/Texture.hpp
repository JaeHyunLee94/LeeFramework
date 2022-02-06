//
// Created by test on 2021-07-02.
//

#ifndef ASSIMP_TEXTURE_HPP
#define ASSIMP_TEXTURE_HPP

#include <GL/glew.h>
#include <string>
#include <vector>
#include <glm/glm.hpp>
class Texture {
public:

    Texture();
    void gen();
    void bind();
    void setWrapping();
    std::vector<glm::vec2>* getUV();
    int getWidth();
    int getHeight();
    GLuint getTextureID();



//    Texture(const char* fileName,GLenum type);
//    void load(const char* fileName,GLenum type);
private:
    GLuint m_textureID;
    int m_width, m_height, m_channels;
    std::vector<glm::vec2> m_uv;

    std::string m_typeName;
    std::string m_image_path;
};


#endif //ASSIMP_TEXTURE_HPP
