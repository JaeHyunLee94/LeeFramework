//
// Created by 이재현 on 2021/07/14.
//

#ifndef LEEFRAMEWORK_MATERIAL_HPP
#define LEEFRAMEWORK_MATERIAL_HPP
#include <glm/glm.hpp>
class Texture;

class Material {
public:
    Texture m_diffuse_map;
    Texture m_specular_map;
    Texture m_ambient_map;

    glm::vec3 Kd,Ks,Ka,Ke;

};


#endif //LEEFRAMEWORK_MATERIAL_HPP
