//
// Created by 가디언 on 2021-06-02.
//

#include "Mesh.hpp"

Mesh::Mesh(BASICS basic_mesh) {

    switch (basic_mesh) {
        case BASICS::CUBE:
            makeCube();
            break;
        case BASICS::SPHERE:
            makeSphere();
            break;
        case BASICS::GROUND:
            makeGround();
            break;
    }


}

Mesh::Mesh(const char *mesh_path) {
//TODO: assimp
}

void Mesh::makeGround() {

}

void Mesh::makeCube() {

}

void Mesh::makeSphere() {

}

void Mesh::computeNormal() {

}

void Mesh::update() {

}
