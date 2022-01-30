//
// Created by 이재현 on 2021/05/29.
//

#include "PhyEngine.hpp"



void Engine::World::create() {

    m_time_step=1./60;
    m_gravity=glm::vec3(0);

    is_created=true;
}

void Engine::World::addEntity(PhysicsEntity *t_p_entity) {
    this->m_entity_list.push_back(t_p_entity);
}

void Engine::World::stepWorld() {

    for(auto pe:m_entity_list){
        pe->applyForce(m_time_step,pe->getMass()*m_gravity);
        detectCollision();
        resolveCollision();




    }


}



void Engine::World::detectCollision() {

}

void Engine::World::resolveCollision() {

}

CollisionManager *Engine::World::createCollisionManager() {
    m_collision_manager=new CollisionManager(this);
    return m_collision_manager;
}



