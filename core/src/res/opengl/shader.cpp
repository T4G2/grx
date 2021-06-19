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
    if (shader_type != GL_VERTEX_SHADER && shader_type != GL_FRAGMENT_SHADER) {
        std::cout << "Only implenented VERTEX and FRAGMENT shader \n";
        return;
    }
    _path = std::move(path);
    compile_shader();
}


void Shader::compile_shader() {


    if (_gl_compiled) {
        _gl_compiled = false;
        _gl_id = 0;
        glDeleteShader(_gl_id);
        std::cout << "recompiling shader <" << _path << ">\n";
    }

     auto [source, error] = load_file(_path);


    if (error) {
        std::cout << "Shader::Shader| Error loading file " << _path << "\n";
        return;
    }

    _empty = false;
    _code = std::move(source);
    _gl_id = glCreateShader(_shader_type);

    const char* ptr = _code.data();
    const GLint size = static_cast<GLint>(_code.size());

    // Source to GL
    glShaderSource(_gl_id, 1, &ptr, &size);

    _gl_compiled = true;

    // Compile
    glCompileShader(_gl_id);
    std::cout << "Shader <" << _path << "> ready \n";
    std::cout << "with code :\n\n\n-----------------------------------\n";
    std::cout << _code << "\n\n\n--------------------------------\n";

}