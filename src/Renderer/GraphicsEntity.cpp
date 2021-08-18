//
// Created by 이재현 on 2021/07/11.
//

#include "GraphicsEntity.hpp"
#include "../Geometry/PhysicsEntity.hpp"

void GraphicsEntityManager::registerEntity(PhysicsEntity *t_pe) {

    bind();
    GraphicsData temp;
    glGenBuffers(1,&temp.m_VBO);




}