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



#include "GLFW/glfw3.h"

#include "../base_resource.hpp"
#include "shader.hpp"

#include "program_bindings.hpp"



class Program : public BaseResource {
    bool _gl_loaded = false;
    GLuint _gl_id = 0;
    Shader& _fragment_shader;
    Shader& _vertex_shader;

    int _bindings[BIND_SIZE] = { -1 };

public:

    void use() {
        glUseProgram(_gl_id);
    }

    Program(std::string name, Shader& vertex, Shader& fragment ):  _fragment_shader(fragment), _vertex_shader(vertex) {
        _path = name;
        _gl_id = glCreateProgram();
        _gl_loaded = true;
        glAttachShader(_gl_id, _vertex_shader.get_gl_id());
        glAttachShader(_gl_id, _fragment_shader.get_gl_id());

        glLinkProgram(_gl_id);

        std::cout << "Program <" << _gl_id << "> with Shaders <" << _fragment_shader.get_path() << ", " << _vertex_shader.get_path() << "> created succesfully\n";
    }

    Program(Program&&) = default; 
    Program(const Program&) = delete;

    /**
     * @brief Set / Get the binding for this program in _bindings (Camera Position Matrix Uniform), textures etc..
     * 
     * @return int 
     */
    int set_binding(int bind_type, int binding_value) {
        _bindings[bind_type] = binding_value;
    }
    int get_binding(int bind) {
        return _binding[bind];
    }

};