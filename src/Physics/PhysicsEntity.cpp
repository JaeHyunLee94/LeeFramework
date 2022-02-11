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



void PhysicsEntity::logPhysicsEntity() const {

    printf("position: (%f,%f,%f)\n",m_pos.x,m_pos.y,m_pos.z);
    printf("hasShape: %d\n",m_has_shape);

}

void PhysicsEntity::setShapeTriangle(float t_x1, float t_y1, float t_z1, float t_x2, float t_y2, float t_z2, float t_x3,
                                     float t_y3, float t_z3) {

    m_shape=new Triangle(t_x1,t_y1,t_z1,
                         t_x2,t_y2,t_z2,
                         t_x3,t_y3,t_z3
                         );
    m_has_shape=true;

}

void PhysicsEntity::setShapePlane(float t_w, float t_h, unsigned int t_res_w, unsigned int t_res_h) {

    m_shape=new PlaneShape(t_w,t_h,t_res_w,t_res_h);

    m_has_shape=true;

}

void PhysicsEntity::setShape(Shape &t_shape) {
    m_shape = new Shape();
    m_has_shape=true;

}

void PhysicsEntity::transport(float dt) {
    m_pos+=dt*m_vel;
//    printf("m_pos: %f,%f,%f\n", m_pos.x,m_pos.y,m_pos.z);
}

void PhysicsEntity::applyForce(float dt,glm::vec3 t_force) {
    glm::vec3 impulse = dt*t_force;
//    printf("m_impulse: %f,%f,%f\n", impulse.x,impulse.y,impulse.z);
//    printf("t_force: %f,%f,%f\n", t_force.x,t_force.y,t_force.z);
//    printf("dt: %f\n",dt);

    m_vel+=impulse/m_mass;
    transport(dt);
}
