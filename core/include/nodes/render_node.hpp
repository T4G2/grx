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
#include "GLFW/glfw3.h"
#include <glm/gtc/type_ptr.hpp>

class RenderNode: public BaseNode {
    Program* program_ptr = nullptr;
    Material* material_ptr = nullptr;
    int priority = 0; // WONT CHANGE

    std::map<std::string, init_prop<RenderNode>> prop_func = 
    {
        {"program", &RenderNode::init_program},
    };

public:



    RenderNode(std::string name_a, BaseNodeInstance& instance):BaseNode(name_a, instance) {};

    void init() override {
        //instance.get_scene()->*_render_struct[priority][program_ptr]
        instance.get_scene()->_render_struct[priority][program_ptr][material_ptr].push_back(this);
        BaseNode::init();
    }

    virtual void upload_to_program(Program& program) {
        int model_location = program.get_binding(MODEL_MATRIX_LOCATION);
        glUniformMatrix4fv(model_location, 1, 0, glm::value_ptr(local_space_matrix));
    }

    void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

    void init_program(toml_value value);

    virtual ~RenderNode() = default;
    
};