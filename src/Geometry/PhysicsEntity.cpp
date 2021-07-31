//
// Created by 이재현 on 2021/07/11.
//

#include "PhysicsEntity.hpp"


void PhysicsEntity::setShapeBox(float t_len_x, float t_len_y, float t_len_z) {

    m_shape=new BoxShape(t_len_x,t_len_y,t_len_z);
    m_has_shape=true;
}

void PhysicsEntity::setShapeSphere() {

}

void PhysicsEntity::setShapePlane() {

}

void PhysicsEntity::setShapeFromFile(const char *t_file_path) {

}
