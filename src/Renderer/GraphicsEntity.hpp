//
// Created by 이재현 on 2021/07/11.
//

#ifndef LEEFRAMEWORK_GRAPHICSENTITY_HPP
#define LEEFRAMEWORK_GRAPHICSENTITY_HPP
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>


class PhysicalEntity;

struct GraphicsData{
    GLuint m_VBO;
    GLuint m_EBO;
    std::vector<glm::vec3>* m_position;
    std::vector<glm::uvec3>* m_indices;
    std::vector<glm::vec2>* m_uv;
    std::vector<glm::vec3>* m_normal;
    PhysicalEntity* m_mirror_pe;
    bool m_has_nomal{false};
    bool m_has_texture{false};
    GLuint m_attrib_num;
};



class GraphicsEntityManager {
//Only knows graphics data

public:

    friend class Renderer;

    GraphicsEntityManager(){
        glGenVertexArrays(1,&m_VAO);
        glBindVertexArray(m_VAO);
    }

    ~GraphicsEntityManager(){
        glDeleteVertexArrays(1,&m_VAO);
        //m_list delete
    }
    void registerEntity(PhysicalEntity* t_pe);

    inline GLuint getVAO() const{return m_VAO;};
    inline void bind() const{glBindVertexArray(m_VAO);};
    static inline void unbind(){glBindVertexArray(0);};


private:

    GLuint m_VAO;
    std::vector<GraphicsData> m_entity_list;



};


#endif //LEEFRAMEWORK_GRAPHICSENTITY_HPP
