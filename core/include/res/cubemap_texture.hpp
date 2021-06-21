/**
 * @file cubemap_texture.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */

#include <string>

#include "glad.h"
#include "GLFW/glfw3.h"


const unsigned int TEXTURE_COUNT = 6;

class CubemapTexture
{

    
    std::string _file_names[6];
    GLuint _gl_id;

public:

    CubemapTexture() = default;

    CubemapTexture(
        const std::string& right_file,
        const std::string& left_file,
        const std::string& top_file,
        const std::string& bottom_file,
        const std::string& front_file,
        const std::string& back_file) : _file_names {right_file, left_file, top_file, bottom_file, front_file, back_file} { };

    ~CubemapTexture();

    bool load();

    void bind(GLuint TextureUnit);


};