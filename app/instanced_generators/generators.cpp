/**
 * @file generators.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 */
#include "generators.hpp"
#include "mesh_instanced_node.hpp"


std::vector<Object_SSBO>  LineGenerator::generate(int count, MeshInstancedNode* node) {
    Object_SSBO default_obj;
    default_obj.ambient_color = glm::vec4(node->material_ptr->_ambient_color, 0);
    default_obj.diffuse_color = glm::vec4(node->material_ptr->_diffuse_color, 0);
    default_obj.specular_color = glm::vec4(node->material_ptr->_specular_color, 0);

    std::vector<Object_SSBO> ssbo = std::vector<Object_SSBO>(count, default_obj);
    glm::vec3 pos = glm::vec3(0.0, 0.0 , 0.0);

    for (int i = 0; i < count ; i++) {
        pos.x += 2.0f;
        ssbo[i].model_matrix = glm::translate(default_obj.model_matrix, pos);   
    }

    return ssbo;
}