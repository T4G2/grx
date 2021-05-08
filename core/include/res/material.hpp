/**
 * @file material.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once

#include "GLFW/glfw3.hpp"

#include "base_resource.hpp"



class Material : public BaseResource {

    bool _has_albedo_map;
    bool _has_normal_map;
    bool _has_specular_map;

    GLuint _albedo_binding;
    GLuint _normal_binding;
    GLuint _specular_binding;

    

};