//
// Created by Lee on 2021-11-11.
//

#ifndef LEEFRAMEWORK_MESHLOADER_HPP
#define LEEFRAMEWORK_MESHLOADER_HPP

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Shape.hpp"
#include "Material.hpp"



class MeshLoader {


public:
    //TODO: mesh ID
    //TODO: shape 여러개?
    void load(const char* t_file_path);
    void destroy();
    Shape getShape();
    Texture getTexture();
    Material getMaterial();

    Shape m_loaded_shape;
    Texture m_loaded_texture;
    Material m_loaded_material;

    bool m_is_shape_loaded;
    bool m_is_texture_loaded;
    bool m_is_material_loaded;


private:
    void processMesh(aiMesh* mesh,const aiScene *pscene);


};


#endif //LEEFRAMEWORK_MESHLOADER_HPP
