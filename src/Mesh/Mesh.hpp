//
// Created by 가디언 on 2021-06-02.
//

#ifndef LEEFRAMEWORK_MESH_HPP
#define LEEFRAMEWORK_MESH_HPP
#include <glm/glm.hpp>


//TODO: enum mesh type


class Mesh {
//TODO: Component pattern? no inheritance!!
// TODO: basic primitive build (boundary), mesh io obj file
//TODO: mesh's renderable interface??
enum MESH_TYPE{
    TRIANGULAR,
    TETRA
};
enum BASICS{
    CUBE,
    SPHERE,
    GROUND
};

public:

    //Physics
    vector<glm::vec3> m_position;
    vector<glm::vec3> m_velocity;
    vector<glm::vec3> m_force;
    vector<unsigned int>m_face_index;
    //meta data

    unsigned int m_vectice_num;
    unsigned int m_face_num;
    virtual void update();




private:



};




#endif //LEEFRAMEWORK_MESH_HPP
