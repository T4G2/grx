/**
 * @file movement_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */

#pragma once

#include "base_node.hpp"


class MovementNode : public BaseNode {

    std::map<std::string, init_prop<MovementNode>> prop_func = 
    {
        {"sensitivity", &MovementNode::init_sensitivity},
        {"speed", &MovementNode::init_speed}
    };

public:

    MovementNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = "Movement";
    float sensitivity = 0.01f;
    float speed = 0.01f;

    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;
    virtual void input(input_struct event) override;

    virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

    void init_sensitivity(toml_value props);
    void init_speed(toml_value props);

   virtual ~MovementNode()= default;

};