/**
 * @file texture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-05
 */

#include <iostream>

#include "glad.h"
#include "GLFW/glfw3.h"

#include "texture.hpp"

// TODo check if in here
        // i dont understand why it is need to be here in first place...
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"




Texture::Texture(std::string path_a, GLuint format_a, bool mipmaps_enabled) { // TODO Send to BaseResource as initializer (faster ?)
    _empty = false;
    _path = std::move(path_a);
    _format = format_a;

    // TODO based on format, send last parameter 
    _memory_ptr = stbi_load(_path.c_str(), &_width, &_height, &_channels, 0); 

    if (format_a == 0) {
        switch (_channels) {
            case 1: 
                _format = GL_R8;
                break;
            case 3: 
                _format = GL_RGB8;
                break;
            case 4:
                _format = GL_RGBA8;
                break;
        }
    }


    if (_memory_ptr == nullptr) {
        std::cout << "Texture::Texture|  Couldn't load texture: " << _path << "\n"; 
        return;
    }   


    if (mipmaps_enabled) {
        _mip_maps = std::log2(std::max(_width, _height));
    }

    load_to_gl();

}

void Texture::load_to_gl(){
    if (_memory_ptr == nullptr) {

        // TODO THROW ERROR IN FUTURE
        std::cout << "Texture::load_to_gl|  Texture not loaded in memory: " << _path << "/n"; 
        return;
    }

    // TODO find type

    glCreateTextures(GL_TEXTURE_2D, 1, &_gl_id);

    glTextureStorage2D(_gl_id, 
                    _mip_maps, // NUMBER OF MIMPMAP LEVELS
                    _format,         // SIZED INTERNAL FORMAT
                    _width, _height);

    glTextureSubImage2D(_gl_id, 0, 0, 0, _width, _height, GL_RGBA, GL_UNSIGNED_BYTE, _memory_ptr);
    glGenerateTextureMipmap(_gl_id);

    std::cout << "Texture <" << _path << "> loaded succesfully\n";
}


Texture::~Texture() {
    // TODO Destructor
}

