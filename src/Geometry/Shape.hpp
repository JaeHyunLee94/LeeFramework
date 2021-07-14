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

//TODO: mesh's renderable interface??
public:

    enum SHAPE_DIM{
        SHAPE_DIM_2D,
        SHAPE_DIM_3D_TRI,
        SHAPE_DIM_3D_TETRA,
    };

    Shape()= default;
    std::vector<glm::vec3>* getShapeVertices(){return &m_vertices;};
    std::vector<glm::uvec3>* getShapeVertexIndices(){return &m_face_index;};
    std::vector<glm::vec3>* getNormal(){return &m_normal;};
    std::vector<glm::vec3>* getColor(){return &m_color;};
    std::vector<glm::vec2>* getUV(){return &m_uv;};



protected:
    //rendering data
    //object space data
    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec3> m_normal;
    std::vector<glm::vec3> m_color;
    std::vector<glm::vec2> m_uv;
    std::vector<glm::uvec3>m_face_index;

    //meta data
    SHAPE_DIM m_shape_dim{SHAPE_DIM_3D_TRI};

    bool m_has_texture{false};
    bool m_has_normal{false};

    unsigned int m_vertices_num{0};
    unsigned int m_face_num{0};



private:


};


class GeneralShape: public Shape{
    // Shape from .obj or mtl file

public:
    explicit GeneralShape(const char* t_file_path){};

protected:

private:



};


class PlaneShape: public Shape{


public:

    PlaneShape()= default;


protected:


private:




};



class BoxShape: public Shape{

public:

    BoxShape(float t_x_len, float t_y_len, float t_z_len):
    m_x_len(t_x_len), m_y_len(t_y_len),m_z_len(t_z_len){
        m_has_normal=false;
        m_has_texture=false;
        m_vertices_num=8;

    };
protected:

private:

    float m_x_len, m_y_len, m_z_len;


};


class SphereShape: public Shape{

public:
protected:
private:

};






#endif //LEEFRAMEWORK_SHAPE_HPP
