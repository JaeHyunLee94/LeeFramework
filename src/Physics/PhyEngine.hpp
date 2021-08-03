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
    World(){};
    void create();
    void addEntity(PhysicsEntity* t_p_entity);


//    void getPhysicsEntity() const;
//
//    void update(float t_timeStep);




private:

//    void detectCollision();
//    void collisionSolve();
    bool is_created{false};
    std::vector<PhysicsEntity*> m_entity_list; //Physical entity


};


#endif //LEEFRAMEWORK_PHYENGINE_HPP
