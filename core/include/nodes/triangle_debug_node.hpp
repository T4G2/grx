/**
 * @file triangle_debug_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */
#pragma once

#include "render_node.hpp"


class TriangleDebugNode : public RenderNode {


public:

    inline static const std::string NODE_NAME = "__TriangleDebug";

    TriangleDebugNode(std::string name_a, BaseNodeInstance& instance): RenderNode(name_a, instance) {};


    void init() override {
        //instance.get_scene()->*_render_struct[priority][program_ptr]
        RenderNode::init();
    }

    virtual void upload_to_program(Program& program) override {
        RenderNode::upload_to_program(program);
    }

    virtual void draw() override {
        glDrawArrays(GL_TRIANGLES, NULL, 3);
    }
};