//
// Created by 가디언 on 2021-06-02.
//

#ifndef LEEFRAMEWORK_MESH_HPP
#define LEEFRAMEWORK_MESH_HPP

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Texture.hpp"

//TODO: enum mesh type

enum MESH_TYPE{
    TRIANGULAR,
    TETRA
};

class Mesh {
//TODO: Component pattern? no inheritance!!
// TODO: basic primitive build (boundary), mesh io obj file
//TODO: mesh's renderable interface??


public:


    explicit Mesh(const char * mesh_path);

    //Physics
    std::vector<glm::vec3> m_velocity;
    std::vector<glm::vec3> m_force;
    glm::vec3 m_world_pos; //center of mass pos
    glm::quat m_rot;


    //rendering data
    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec3> m_normal;
    std::vector<glm::vec2> m_uv;
    std::vector<unsigned int>m_face_index;

    bool m_has_Texture;
    bool m_has_normal;

    //meta data

    unsigned int m_vectice_num;
    unsigned int m_face_num;
    virtual void update();


private:
    Texture* m_texture= nullptr;
    void computeNormal();

};




#endif //LEEFRAMEWORK_MESH_HPP
