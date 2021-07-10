//
// Created by 가디언 on 2021-07-05.
//

#ifndef LEEFRAMEWORK_TOYMESH_HPP
#define LEEFRAMEWORK_TOYMESH_HPP

#include "Mesh.hpp"

enum TOY_MESH_TYPE{
    CUBE,
    SPHERE,
    GROUND
};

class Ground : public Mesh{

public:
    Ground();

    TOY_MESH_TYPE m_toy_mesh_type;

    int m_length=100;
    float sh=200.f;
    glm::vec3 Ka{0.0f,0.0f,0.0f};
    glm::vec3 Ks{0.8f,0.8f,0.8f};
    glm::vec3 Ke{0.1f,0.1f,0.1f};

    glm::vec3 m_black_color;
    glm::vec3 m_white_color;


private:



};




class Cube: public Mesh{

    Cube() = default;

    TOY_MESH_TYPE m_toy_mesh_type;



};


#endif //LEEFRAMEWORK_TOYMESH_HPP
