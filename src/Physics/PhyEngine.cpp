//
// Created by 이재현 on 2021/05/29.
//

#include "PhyEngine.hpp"



void Engine::World::create() {

}

void Engine::World::addEntity(PhysicsEntity *t_p_entity) {
    this->m_entity_list.push_back(t_p_entity);
}

void Engine::World::step(float dt) {

}


