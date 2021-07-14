//
// Created by 이재현 on 2021/07/11.
//

#ifndef LEEFRAMEWORK_PHYSICSENTITY_HPP
#define LEEFRAMEWORK_PHYSICSENTITY_HPP


#include <glm/glm.hpp>
#include <vector>

#include "Shape.hpp"
#include "../Renderer/GraphicsEntity.hpp"
class PhysicsEntity {

    //TODO: refactor to Physics directory

public:

    Shape getShape();
    glm::vec3 getPos();
    glm::quat getRotation();



private:

    glm::vec3 m_pos;
    glm::quat m_rot;

    Shape* shape;


};


#endif //LEEFRAMEWORK_PHYSICSENTITY_HPP
