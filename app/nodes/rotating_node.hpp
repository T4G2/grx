/**
 * @file rotating_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include "base_node.hpp"

class RotatingNode : public BaseNode {

    std::map<std::string, init_prop<RotatingNode>> prop_func = 
    {
        {"frequency", &RotatingNode::init_frequency}
    };

public:

     RotatingNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = "Rotating";

    float frequency = 1.0f;


    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;
    virtual void input(input_struct event) override;

   void init_frequency(toml_value data);

   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~RotatingNode()= default;

};