//
// Created by 이재현 on 2021/05/29.
//

#ifndef LEEFRAMEWORK_PHYENGINE_HPP
#define LEEFRAMEWORK_PHYENGINE_HPP

#include "../Geometry/PhysicsEntity.hpp"
#include "../Renderer/GraphicsEntity.hpp"
#include "Collision/CollisionManager.hpp"

namespace Engine {

    class World {
//TODO: this class only depends on Geometry class and other physics solver


    public:
        World()=default;

        void create();

        void addEntity(PhysicsEntity *t_p_entity);
        void setGravity(glm::vec3&& t_gravity){this->m_gravity=t_gravity;};
        void setTimeStep(float t_time_step){this->m_time_step = t_time_step;};
        CollisionManager* createCollisionManager();
        bool isCollisionManagerCreated(){return m_collision_manager != nullptr;};
        //void addBoundary();





        void stepWorld();


        bool is_created{false};


        //void getPhysicsEntity() const;
//





    private:

    void detectCollision();
    void resolveCollision();
        //meta data


        //Physics data
        std::vector<PhysicsEntity *> m_entity_list; //Physical entity
        CollisionManager* m_collision_manager= nullptr;
        glm::vec3 m_gravity;
        float m_time_step{};




    };


}


#endif //LEEFRAMEWORK_PHYENGINE_HPP
