//
// Created by Lee on 2021-11-11.
//

#ifndef LEEFRAMEWORK_MESHLOADER_HPP
#define LEEFRAMEWORK_MESHLOADER_HPP

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../Renderer/Material/Shape.hpp"
#include "../Renderer/Material/Material.hpp"
#include <vector>



class MeshLoader {


public:
    //TODO: mesh ID
    //TODO: shape 여러개?
    void load(const char* t_file_path);
    void destroy();

    std::vector<Shape> m_loaded_shape;
    std::vector<Material> m_loaded_material;


private:


};


#endif //LEEFRAMEWORK_MESHLOADER_HPP
