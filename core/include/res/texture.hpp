/**
 * @file texture.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include "base_resource.hpp"
#include "GLFW/glfw3.h"

class Texture : public BaseResource {
    int _width = 0;
    int _height = 0;
    int _channels = 0;
    GLuint _format;
    int _mip_maps = 0; 

    unsigned char *_memory_ptr;
    bool _gl_loaded = false;
    GLuint _gl_id = 0;

    
    void load_to_gl();


public:

    Texture(std::string path, GLuint format_a = 0, bool mipmaps_enabled = true);

    bool is_memory_loaded() {
        return _memory_ptr == NULL;
    }

    bool is_gl_loaded() {
        if (_gl_loaded && !glIsTexture(_gl_id)) {
            _gl_loaded = false;
        }
        return _gl_loaded;
    }

    GLuint get_gl_id() {
        return _gl_id;
    }

    int get_width() {
        return _width;
    }

    int get_height() {
        return _height;
    }

    int get_channels() {
        return _channels;
    }

    int get_mipmap() {
        return _mip_maps;
    }

    virtual ~Texture() = default;

    // forbid copying
    Texture(Texture&&) = default; 
    Texture(const Texture&) = delete;
};