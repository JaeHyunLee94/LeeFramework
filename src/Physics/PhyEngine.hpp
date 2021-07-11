//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_PHYENGINE_HPP
#define LEEFRAMEWORK_PHYENGINE_HPP

#include "../Geometry/PhysicsEntity.hpp"
#include "../Renderer/GraphicsEntity.hpp"

class World {
//TODO: this class only depends on Geometry class and other physics solver


public:
    World();
    void addEntity();

    void getPhysicsEntity() const;
    void getGraphicsEntity() const; // communicate with renderer

    void update(float t_timeStep);
    void collisionSolve();

private:

    std::vector<PhysicsEntity*> m_actor_list; //Physical entity
    std::vector<GraphicsEntity*> m_graphics_entity_list; // Graphics Entity


};


#endif //LEEFRAMEWORK_PHYENGINE_HPP
