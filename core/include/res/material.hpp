/**
 * @file material.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once


#include "glm/glm.hpp"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"


#include "base_resource.hpp"
#include "program.hpp"
#include "texture.hpp"

class Material : public BaseResource {

    glm::vec3 _ambient_color = glm::vec3(0, 0, 0);
    glm::vec3 _albedo_color = glm::vec3(0, 0, 0);
    glm::vec3 _specular_color = glm::vec3(0, 0, 0);
    float _shininess = -1;

    Texture* _albedo_map_ptr = nullptr;
    Texture* _normal_map_ptr = nullptr;
    Texture* _specular_map_ptr = nullptr;

public:
    void gl_prepare(Program& gl_program);

    bool has_albedo_map() { return _albedo_map_ptr != nullptr; };
    bool has_normal_map() { return _normal_map_ptr != nullptr; };
    bool has_specular_map() { return _specular_map_ptr != nullptr; };
    

};