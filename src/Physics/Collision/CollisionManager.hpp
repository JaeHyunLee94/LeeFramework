//
// Created by 이재현 on 2022/01/30.
//

#ifndef LEEFRAMEWORK_COLLISIONMANAGER_HPP
#define LEEFRAMEWORK_COLLISIONMANAGER_HPP

#include "AABB.h"

namespace Engine{
    class World;
}


class CollisionManager {


public:
    CollisionManager(Engine::World* parent_world) {

        m_parent_world=parent_world;
    };

    void createAABBTree();
    void createColliderAll();
    void solve();



private:
    void detectCollision();
    void resolveCollision();
    Engine::World* m_parent_world=nullptr;


};


#endif //LEEFRAMEWORK_COLLISIONMANAGER_HPP
