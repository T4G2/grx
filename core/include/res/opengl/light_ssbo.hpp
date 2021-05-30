/**
 * @file light_struct.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */
#pragma once
#include "glm/glm.hpp"

struct Light_SSBO {
	glm::vec4 position;
	glm::vec4 ambient_color;
	glm::vec4 diffuse_color;
	glm::vec4 specular_color;
};