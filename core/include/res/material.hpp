/**
 * @file material.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once

#include "GLFW/glfw3.h"

#include "base_resource.hpp"
#include "program.hpp"
#include "texture.hpp"

class Material : public BaseResource {

    Program* program_ptr;

    bool _has_albedo_map;
    bool _has_normal_map;
    bool _has_specular_map;

    GLuint _albedo_binding = 0;
    GLuint _normal_binding = 0;
    GLuint _specular_binding = 0;

    Texture* _albedo_ptr = nullptr;
    Texture* _normal_ptr = nullptr;
    Texture* _specular_ptr = nullptr;
};