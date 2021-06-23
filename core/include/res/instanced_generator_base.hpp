/**
 * @file instanced_generator_base.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once 


#include <vector>
#include "glm/glm.hpp"


#include "object_ssbo.hpp"


class MeshInstancedNode;


class InstancedGeneratorBase {

public:

    InstancedGeneratorBase() = default;

    virtual std::vector<Object_SSBO>  generate(int count, MeshInstancedNode* node) = 0;
};