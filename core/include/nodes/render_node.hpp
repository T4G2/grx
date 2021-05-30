/**
 * @file render_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#pragma once

#include "base_node.hpp"
#include "program.hpp"
#include "material.hpp"
#include "scene.hpp"

class RenderNode: public BaseNode {
    Program* program_ptr = nullptr;
    Material* material_ptr = nullptr;
    int priority = 0;


    void init() override {
        instance.get_scene()->_render_struct[priority][program_ptr][material_ptr].append(this);
        BaseNode::init();
    }
    
};