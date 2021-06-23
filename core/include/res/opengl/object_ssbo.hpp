/**
 * @file object_ssbo.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-23 
 */
#pragma once
#include "glm/glm.hpp"

struct Object_SSBO {
	glm::mat4 model_matrix = glm::mat4(1.0f);
    glm::vec4 ambient_color = glm::vec4(0.0f);
    glm::vec4 diffuse_color = glm::vec4(0.0f);
    glm::vec4 specular_color = glm::vec4(0.0f);

};
