/**
 * @file shader.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-06
 */

#include <iostream>

#include "glad.h"

#include "mylib.hpp"

#include "shader.hpp"



Shader::Shader(GLenum shader_type, std::string path): _shader_type(shader_type) {
    if (shader_type != GL_VERTEX_SHADER || GL_FRAGMENT_SHADER) {
        std::cout << "Only implenented VERTEX and FRAGMENT shader \n";
    }

    auto [source, error] = load_file(path);

    if (error) {
        std::cout << "Shader::Shader| Error loading file " << path << "\n";
        return;
    }

    std::cout << source;

    _empty = false;
    _path = std::move(path);
    _gl_id = glCreateShader(_shader_type);






}