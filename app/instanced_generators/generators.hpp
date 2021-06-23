/**
 * @file generators.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 */
#pragma once

#include "glm/glm.hpp"
#include "instanced_generator_base.hpp"

class LineGenerator : public InstancedGeneratorBase {
    virtual std::vector<Object_SSBO>  generate(int count, MeshInstancedNode* node) override;
};

