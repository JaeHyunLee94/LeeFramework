//
// Created by 가디언 on 2021-06-02.
//

#ifndef LEEFRAMEWORK_SHAPE_HPP
#define LEEFRAMEWORK_SHAPE_HPP

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Texture.hpp"


class Shape {
//TODO: Component pattern? no inheritance!!
// TODO: basic primitive build (boundary), mesh io obj file
//TODO: mesh's renderable interface??




public:

    enum SHAPE_DIM{
        SHAPE_DIM_2D,
        SHAPE_DIM_3D_TRI,
        SHAPE_DIM_3D_TETRA,
    };

    Shape()= default;

    //rendering data
    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec3> m_normal;
    std::vector<glm::vec3> m_color;
    std::vector<glm::vec2> m_uv;
    std::vector<glm::uvec3>m_face_index;

    //meta data
    bool m_has_texture{false};
    bool m_has_normal{false};
    bool m_has_shape{false};

    unsigned int m_vertices_num{0};
    unsigned int m_face_num{0};


    SHAPE_DIM m_shape_dim;

private:
    Texture* m_texture= nullptr;
    void computeNormal();

};


class GeneralShape: public Shape{
    // Shape from .obj or mtl file






};


class PlaneShape: public Shape{




};



class BoxShape: public Shape{


};


class SphereShape: public Shape{





};






#endif //LEEFRAMEWORK_SHAPE_HPP
