//
// Created by 이재현 on 2021/05/29.
//

#include "PhyEngine.hpp"

void World::create() {

}

void World::addEntity(PhysicsEntity *t_p_entity) {
    this->m_entity_list.push_back(t_p_entity);
}


