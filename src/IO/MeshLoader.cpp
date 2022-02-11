//
// Created by Lee on 2021-11-11.
//

#include "MeshLoader.hpp"


void MeshLoader::load(const char *t_file_path) {

    //TODO: add library
    Assimp::Importer importer;
    std::cout << "model loading....\n";
    const aiScene *scene = importer.ReadFile(t_file_path,
                                             aiProcess_Triangulate |
                                             aiProcess_GenSmoothNormals |
                                             aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        return;
    }


    auto rootNode = scene->mRootNode;
    for (int i = 0; i < scene->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[i];

        Shape t_shape;
        Material t_mat;

        if (mesh->HasPositions()) {

            for (int j = 0; j < mesh->mNumVertices; j++) {

                t_shape.getShapeVertices()->push_back(
                        glm::vec3(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z));

            }


        }
        if (mesh->HasFaces()) {
            for (int j = 0; j < mesh->mNumFaces; j++) {
                glm::uvec3 index;
                mesh->mFaces[j].mIndices[0];
                index.x = mesh->mFaces[j].mIndices[0];
                index.y =  mesh->mFaces[j].mIndices[1];
                index.z =  mesh->mFaces[j].mIndices[2];

                t_shape.getShapeVertexIndices()->push_back(index);

            }

        }
        if (mesh->HasNormals()) {
            for (int j = 0; j < mesh->mNumVertices; j++) {
                t_shape.getNormal()->push_back(
                        glm::vec3(mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z));

            }

        }
        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            for (int j = 0; j < mesh->mNumVertices; j++) {

                glm::vec2 vec;
                // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't
                // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
                vec.x = mesh->mTextureCoords[0][j].x;
                vec.y = mesh->mTextureCoords[0][j].y;
                t_mat.m_diffuse_uv.push_back(vec);


            }
            t_mat.m_has_diffuse_texture=true;

        } else {
            t_mat.m_has_diffuse_texture = false;
        }


        m_loaded_shape.push_back(t_shape);
        m_loaded_material.push_back(t_mat);


    }

    std::cout << "model loading ended !\n";


}

void MeshLoader::destroy() {

}



