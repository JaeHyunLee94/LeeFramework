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


private:
    void init();


};


#endif //LEEFRAMEWORK_TOYMESH_HPP
