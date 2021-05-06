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

#include "GLFW/glfw3.h"

#include "../base_resource.hpp"




class Shader: public BaseResource {
    bool _gl_compiled = false;
    
    GLuint _gl_id = 0;
    GLenum _shader_type;
    

public:
    Shader(GLenum shader_type, std::string path);




    Shader(const Shader&) = delete;
};