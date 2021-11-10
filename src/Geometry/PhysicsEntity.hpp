//
// Created by 이재현 on 2021/07/11.
//

#ifndef LEEFRAMEWORK_PHYSICSENTITY_HPP
#define LEEFRAMEWORK_PHYSICSENTITY_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <vector>

#include "Shape.hpp"
class PhysicsEntity {

    //TODO: refactor to Physics directory

public:
    ~PhysicsEntity(){
      delete m_shape;
    };

    inline Shape* getShape() const {return m_shape;};
    inline glm::vec3 getPos() const {return m_pos;};
    inline glm::quat getRotation() const{return m_rot;};
    inline glm::vec3 getVel() const{return m_vel;};
    inline glm::vec3 getRotVel() const{return m_rot_vel;};

    inline void setPos(glm::vec3 t_pos){this->m_pos=t_pos;};
    inline void setRot(glm::quat t_rot){this->m_rot=t_rot;};
    inline void setVel(glm::vec3 t_vel){this->m_vel=t_vel;};
    inline void setRotVel(glm::vec3 t_rot_vel){this->m_rot_vel=t_rot_vel;};

    void setShapeFromFile(const char* t_file_path);
    void setShapeBox(float t_len_x,float t_len_y,float t_len_z);
    void setShapeTriangle(float t_x1, float t_y1,float t_z1,
                          float t_x2, float t_y2,float t_z2,
                          float t_x3, float t_y3,float t_z3);
    void setShapeSphere();
    void setShapePlane(float t_w,float t_h,unsigned int resolution_w,unsigned int resolution_h);
    inline bool hasShape() const{return m_has_shape;};

    void logPhysicsEntity() const;


private:
    glm::vec3 m_pos{0,0,0}; // world coordinate
    glm::quat m_rot{0,0,1,0};
    glm::vec3 m_vel{0,0,0};
    glm::vec3 m_rot_vel{0,0,0};

    bool m_has_shape{false};

    Shape* m_shape{nullptr};

};




#endif //LEEFRAMEWORK_PHYSICSENTITY_HPP
