//
// Created by 이재현 on 2021/07/11.
//

#ifndef LEEFRAMEWORK_GRAPHICSENTITY_HPP
#define LEEFRAMEWORK_GRAPHICSENTITY_HPP
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>


class GraphicsEntity {
//Only knows graphics data

public:
//    GraphicsEntity();
//    void fromMesh();


private:



    GLuint m_VBO;
    GLuint m_EBO;
    std::vector<glm::vec3>* m_position;
    std::vector<glm::uvec3>* m_indices;
    std::vector<glm::vec2>* m_uv;
    std::vector<glm::vec3>* m_normal;


};


#endif //LEEFRAMEWORK_GRAPHICSENTITY_HPP
