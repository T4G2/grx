/**
 * @file shader.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include "GLFW/glfw3.h"

#include "../base_resource.hpp"




class Shader: public BaseResource {
    bool _gl_compiled = false;


    std::string _code;
    GLuint _gl_id = 0;
    GLenum _shader_type;
    

public:
    Shader(GLenum shader_type, std::string path);

    GLuint get_gl_id() {
        return _gl_id;
    }

    Shader(Shader&&) = default; 
    Shader(const Shader&) = delete;

    //virtual ~Shader() = default;
};