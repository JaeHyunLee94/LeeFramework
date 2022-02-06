//
// Created by 이재현 on 2021/07/14.
//

#ifndef LEEFRAMEWORK_MATERIAL_HPP
#define LEEFRAMEWORK_MATERIAL_HPP
#include <glm/glm.hpp>
class Texture;

class Material {
public:


    std::vector<glm::vec3> m_vertex_color;
    std::vector<glm::vec2> m_diffuse_uv;

    bool m_has_diffuse_texture;
    bool m_has_specular_texture;
    bool m_has_ambient_texutre;

    Texture m_diffuse_map;
    Texture m_specular_map;
    Texture m_ambient_map;

    //base color
    glm::vec3 Kd,Ks,Ka,Ke;

};


#endif //LEEFRAMEWORK_MATERIAL_HPP
