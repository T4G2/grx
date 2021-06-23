/**
 * @file generators.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 */
#include "generators.hpp"
#include "mesh_instanced_node.hpp"

    /**
     * @brief random float range from 0 to 1
     * @return float 
     */
float random() {

    int i = std::rand();
    float res = static_cast<float>(i) / static_cast<float>(RAND_MAX);
    return res;
}

/**
     * @brief random float range from - to 1
     * @return float 
     */
float random_gl_range() {

    float res = random();
    return res * 2 - 1.0f;
}



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

std::vector<Object_SSBO>  RingGenerator::generate(int count, MeshInstancedNode* node) {
    Object_SSBO default_obj;
    default_obj.ambient_color = glm::vec4(node->material_ptr->_ambient_color, 0);
    default_obj.diffuse_color = glm::vec4(node->material_ptr->_diffuse_color, 0);
    default_obj.specular_color = glm::vec4(node->material_ptr->_specular_color, 0);

    std::vector<Object_SSBO> ssbo = std::vector<Object_SSBO>(count, default_obj);
    glm::vec3 pos = glm::vec3(0.0, 0.0 , 0.0);
    float size = 125.0f;
    float freq = 5.0f;

    float rand_z = 7.5f;
    float rand_xy = 23.0f;

    float rand_size_var = 0.5f;
    float rand_size_var_axis = 0.2f;


    for (int i = 0; i < count ; i++) {

        float scale = 1.0f +  rand_size_var * random_gl_range();

        float scale_x = scale * (1.0f + rand_size_var_axis * random_gl_range());
        float scale_y = scale * (1.0f + rand_size_var_axis * random_gl_range());
        float scale_z = scale * (1.0f + rand_size_var_axis * random_gl_range());

        ssbo[i].model_matrix = glm::scale(default_obj.model_matrix, glm::vec3(scale_x, scale_y, scale_z));


        auto rand_rot = glm::vec3(random_gl_range() * glm::pi<float>(), random_gl_range() * glm::pi<float>(), random_gl_range() * glm::pi<float>());

        ssbo[i].model_matrix *= glm::rotate(default_obj.model_matrix, rand_rot.x, glm::vec3(1, 0, 0 ));
        ssbo[i].model_matrix *= glm::rotate(default_obj.model_matrix, rand_rot.y, glm::vec3(0, 1, 0 ));
        ssbo[i].model_matrix *= glm::rotate(default_obj.model_matrix, rand_rot.z, glm::vec3(0, 0, 1 ));

        pos.x = size * sin(i / freq) + random_gl_range() * rand_xy;
        pos.y = size * cos(i / freq) + random_gl_range() * rand_xy;
        pos.z = random_gl_range() * rand_z;
        ssbo[i].model_matrix = glm::translate(default_obj.model_matrix, pos) * ssbo[i].model_matrix;   
    }

    return ssbo;
}