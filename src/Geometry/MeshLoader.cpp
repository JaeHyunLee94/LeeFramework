//
// Created by Lee on 2021-11-11.
//

#include "MeshLoader.hpp"


void MeshLoader::load(const char *t_file_path) {

    //TODO: add library
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("../../assets/ChessKing.obj",aiProcess_Triangulate| aiProcess_GenSmoothNormals | aiProcess_FlipUVs);


}

void MeshLoader::destroy() {

}

Shape MeshLoader::getShape() {
    return Shape();
}

Texture MeshLoader::getTexture() {
    return Texture();
}

Material MeshLoader::getMaterial() {
    return Material();
}

void MeshLoader::processMesh(aiMesh *mesh, const aiScene *pscene) {

}
