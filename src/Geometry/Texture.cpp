////
//// Created by test on 2021-07-02.
////
//
//#include "Texture.hpp"
//#include <iostream>
////#include <SOIL2.h>
//
//Texture::Texture(std::string fileName, GLenum type) {
//    this->fileName=fileName;
//    glGenTextures(1, &textureID);
//    glBindTexture(type, textureID);
//// 텍스처 wrapping/filtering 옵션 설정(현재 바인딩된 텍스처 객체에 대해)
//    glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//// 텍스처 로드 및 생성
//
//    unsigned char *data = SOIL_load_image(fileName.c_str(), &width, &height,&channels ,SOIL_LOAD_RGB);
//    if (data)
//    {
//        glTexImage2D(type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(type);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    SOIL_free_image_data(data);
//
//
//}
//
//Texture::Texture() {
//
//}
//
//void Texture::load(std::string fileName,GLenum type) {
//    this->fileName=fileName;
//    glGenTextures(1, &textureID);
//    glBindTexture(type, textureID);
//// 텍스처 wrapping/filtering 옵션 설정(현재 바인딩된 텍스처 객체에 대해)
//    glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//// 텍스처 로드 및 생성
//
//    unsigned char *data = SOIL_load_image(fileName.c_str(), &width, &height,&channels ,SOIL_LOAD_RGB);
//    if (data)
//    {
//        glTexImage2D(type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(type);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    SOIL_free_image_data(data);
//}

#include "Texture.hpp"


Texture::Texture() {

}

void Texture::bind() {

}

void Texture::setWrapping() {

}

std::vector<glm::vec2> *Texture::getUV() {
    return nullptr;
}

int Texture::getWidth() {
    return 0;
}

int Texture::getHeight() {
    return 0;
}

GLuint Texture::getTextureID() {
    return 0;
}

void Texture::gen() {

}

