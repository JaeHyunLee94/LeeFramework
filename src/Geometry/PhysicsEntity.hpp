//
// Created by 이재현 on 2021/07/11.
//

#ifndef LEEFRAMEWORK_PHYSICSENTITY_HPP
#define LEEFRAMEWORK_PHYSICSENTITY_HPP


#include <glm/glm.hpp>
#include <vector>

#include "Shape.hpp"
#include "../Renderer/GraphicsEntity.hpp"
class PhysicsEntity {

    //TODO: refactor to Physics directory

public:

    inline Shape* getShape() const {return m_shape;};
    inline glm::vec3 getPos() const {return m_pos;};
    inline glm::quat getRotation() const{return m_rot;};
    inline glm::vec3 getVel() const{return m_vel;};
    inline glm::vec3 getRotVel() const{return m_rot_vel;};

    void setShapeFromFile(const char* t_file_path);
    void setShapeBox(float t_len_x,float t_len_y,float t_len_z);
    void setShapeSphere();
    void setShapePlane();
    inline bool hasShape() const{return m_has_shape;};



private:
    glm::vec3 m_pos; // world coordinate
    glm::quat m_rot;
    glm::vec3 m_vel;
    glm::vec3 m_rot_vel;

    bool m_has_shape{false};

    Shape* m_shape{nullptr};

};


#endif //LEEFRAMEWORK_PHYSICSENTITY_HPP
