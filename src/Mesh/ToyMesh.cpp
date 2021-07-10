//
// Created by 가디언 on 2021-07-05.
//

#include "ToyMesh.hpp"

Ground::Ground() {

m_mesh_type=MESH_TYPE::TRIANGULAR;
m_toy_mesh_type= TOY_MESH_TYPE::GROUND;
m_has_Texture=false;
m_black_color=glm::vec3 {0.,0.,0.};
m_white_color=glm::vec3 {1.,1.,1.};


    int num_black=0;
    int num_white=0;


    for(int x=-m_length/2;x<m_length/2-1;x++) {
        for (int z = m_length / 2; z > -m_length / 2 + 1; z--) {
            if ((x + z) % 2 == 0) {
                m_world_pos.push_back(glm::vec3(x, 0, z));
                m_world_pos.push_back(glm::vec3(x - 1, 0, z));
                m_world_pos.push_back(glm::vec3(x - 1, 0, z + 1));
                m_world_pos.push_back(glm::vec3(x, 0, z + 1));

                m_color.push_back(m_black_color);
                m_color.push_back(m_black_color);
                m_color.push_back(m_black_color);
                m_color.push_back(m_black_color);

                m_face_index.push_back(glm::uvec3{num_black, num_black + 1, num_black + 2});
                m_face_index.push_back(glm::uvec3{num_black, num_black + 2, num_black + 3});

                num_black += 4;
            } else {
                m_world_pos.push_back(glm::vec3(x, 0, z));
                m_world_pos.push_back(glm::vec3(x - 1, 0, z));
                m_world_pos.push_back(glm::vec3(x - 1, 0, z + 1));
                m_world_pos.push_back(glm::vec3(x, 0, z + 1));

                m_color.push_back(m_white_color);
                m_color.push_back(m_white_color);
                m_color.push_back(m_white_color);
                m_color.push_back(m_white_color);

                m_face_index.push_back(glm::uvec3{num_white, num_white + 1, num_white + 2});
                m_face_index.push_back(glm::uvec3{num_white, num_white + 2, num_white + 3});

                num_white += 4;
            }


        }
    }
    std::fill(m_normal.begin(),m_normal.end(),glm::vec3{0.,1.f,0.f});

}


