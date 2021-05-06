/**
 * @file program.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once



#include "../base_resource.hpp"
#include "shader.hpp"

#include "GLFW/glfw3.h"


class Program {
    bool _gl_loaded = false;
    GLuint _gl_id = 0;
    Shader& _fragment_shader;
    Shader& _vertex_shader;

public:
    Program(Shader& fragment, Shader& vertex ):  _fragment_shader(fragment), _vertex_shader(vertex) {
        std::cout << "Program <" << _gl_id << "> with Shaders <" << _fragment_shader.get_path() << ", " << _vertex_shader.get_path() << "> created succesfully\n";
    }


};