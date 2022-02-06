//
// Created by 가디언 on 2021-06-02.
//

#include "Shape.hpp"
#include "../../utils/UtilHeader.h"
void Shape::computeNormal() {

    //TODO: bug fix
    if(m_has_normal) return;
    std::cout << "computing normal...\n";

    m_normal.resize(m_vertices_num);
    for(auto & i : m_face_index){
        glm::vec3 firstPoint = m_vertices[i.x];
        glm::vec3 secondPoint = m_vertices[i.y];
        glm::vec3 thirdPoint = m_vertices[i.z];
        glm::vec3 tri_normal= getTriangleNormal(firstPoint,secondPoint , thirdPoint);
        m_normal[i.x] +=tri_normal;
        m_normal[i.y] +=tri_normal;
        m_normal[i.z] +=tri_normal;

    }
    for(auto & i : m_normal){
        i=glm::normalize(i);
        printf("normal value: %f,%f,%f \n", i.x,i.y,i.z);
    }

    std::cout << "computing normal ended\n";

    m_has_normal=true;

}
