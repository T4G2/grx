/**
 * @file cubemap_texture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */

#include "cubemap_texture.hpp"

#include <iostream>
#include "stb_image.h"

bool CubemapTexture::load() {
    glGenTextures(1, &_gl_id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _gl_id);

    for (unsigned int i = 0 ; i < TEXTURE_COUNT ; i++) {
        int width;
        int height;
        int channels;

        unsigned char *data = stbi_load(_file_names[i].c_str(), &width, &height, &channels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 
                         0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap tex failed to load at path: " << _file_names[i] << std::endl;
            stbi_image_free(data);
            return false;
        }
    }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return true;
}

void CubemapTexture::bind(GLuint binding) {
    glBindTexture(binding, _gl_id);
}

CubemapTexture::~CubemapTexture() {
    glDeleteTextures(1, &_gl_id);
}