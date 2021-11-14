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
#include <vector>



class MeshLoader {


public:
    //TODO: mesh ID
    //TODO: shape 여러개?
    void load(const char* t_file_path);
    void destroy();
    Shape getShape();
    Material getMaterial();

    std::vector<Shape> m_loaded_shape;
    std::vector<Material> m_loaded_material;

    bool m_is_shape_loaded=false;
    bool m_is_material_loaded=false;


private:
//    void processMesh(aiMesh* mesh,const aiScene *pscene);


};


#endif //LEEFRAMEWORK_MESHLOADER_HPP
