//
// Created by Lee on 2021-06-02.
//

#ifndef LEEFRAMEWORK_SHAPE_HPP
#define LEEFRAMEWORK_SHAPE_HPP

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <iostream>
#include "Texture.hpp"

enum SHAPE_TYPE{
    SHAPE_TYPE_UNDEFINED,
    SHAPE_TYPE_2D,
    SHAPE_TYPE_3D_TRI,
    SHAPE_TYPE_3D_TETRA,
};

class Shape {

//TODO: mesh's renderable interface??
public:



    Shape()= default;
    std::vector<glm::vec3>* getShapeVertices(){return &m_vertices;};
    std::vector<glm::uvec3>* getShapeVertexIndices(){return &m_face_index;};
    std::vector<glm::vec3>* getNormal(){return &m_normal;};
    std::vector<glm::vec3>* getColor(){return &m_color;};
    std::vector<glm::vec2>* getUV(){return &m_uv;};

    void computeNormal();



protected:
    //rendering data
    //object space data
    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec3> m_normal;
    std::vector<glm::uvec3>m_face_index;
    //TODO: uv,color -> move to Texture, material class
    std::vector<glm::vec3> m_color;
    std::vector<glm::vec2> m_uv;


    //meta data
    SHAPE_TYPE m_shape_type{SHAPE_TYPE_UNDEFINED};

    bool m_has_texture{false};
    bool m_has_normal{false};

    unsigned int m_vertices_num{0};
    unsigned int m_face_num{0};



private:


};


//class GeneralShape: public Shape{
//    // Shape from .obj or mtl file
//
//public:
//    explicit GeneralShape(const char* t_file_path){};
//
//protected:
//
//private:
//
//
//
//};


class PlaneShape: public Shape{


public:

    PlaneShape(float t_w,float t_h,unsigned int t_res_w, unsigned int t_res_h){



    };



protected:


private:




};



class BoxShape: public Shape{

public:

    BoxShape(float t_x_len, float t_y_len, float t_z_len):
    m_x_len(t_x_len), m_y_len(t_y_len),m_z_len(t_z_len){

        m_shape_type=SHAPE_TYPE_3D_TRI;

        m_has_normal=false;
        m_has_texture=false;
        m_vertices_num=8;
        m_face_num = 12;

        m_vertices.emplace_back(t_x_len,t_y_len,t_z_len);
        m_vertices.emplace_back(-t_x_len,t_y_len,t_z_len);
        m_vertices.emplace_back(-t_x_len,-t_y_len,t_z_len);
        m_vertices.emplace_back(t_x_len,-t_y_len,t_z_len);

        m_vertices.emplace_back(t_x_len,t_y_len,-t_z_len);
        m_vertices.emplace_back(-t_x_len,t_y_len,-t_z_len);
        m_vertices.emplace_back(-t_x_len,-t_y_len,-t_z_len);
        m_vertices.emplace_back(t_x_len,-t_y_len,-t_z_len);

        m_face_index.emplace_back(0,1,2);
        m_face_index.emplace_back(2,3,0);

        m_face_index.emplace_back(5,1,0);
        m_face_index.emplace_back(0,4,5);

        m_face_index.emplace_back(7,4,0);
        m_face_index.emplace_back(0,3,7);

        m_face_index.emplace_back(3,2,6);
        m_face_index.emplace_back(6,7,3);

        m_face_index.emplace_back(5,4,7);
        m_face_index.emplace_back(7,6,5);

        m_face_index.emplace_back(5,6,2);
        m_face_index.emplace_back(2,1,5);
        computeNormal();

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

class Triangle:public Shape{

public:

    Triangle(float t_x1, float t_y1, float t_z1,
             float t_x2, float t_y2, float t_z2,
             float t_x3, float t_y3, float t_z3
             ):x1(t_x1),y1(t_y1),z1(t_z1),x2(t_x2),y2(t_y2),z2(t_z2),x3(t_x3),y3(t_y3),z3(t_z3)

             {
        m_shape_type=SHAPE_TYPE_2D;

        m_has_normal=false;
        m_has_texture=false;
        m_vertices_num=3;
        m_face_num = 1;

        m_vertices.emplace_back(glm::vec3(x1,y1,z1));
        m_vertices.emplace_back(glm::vec3(x2,y2,z2));
        m_vertices.emplace_back(glm::vec3(x3,y3,z3));

        m_face_index.emplace_back(glm::uvec3(0,1,2));
        computeNormal();

    };


private:
    float x1,y1,z1;
    float x2,y2,z2;
    float x3,y3,z3;


};






#endif //LEEFRAMEWORK_SHAPE_HPP
