/**
 * @file template_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */
#pragma once

#include "base_node.hpp"

class TemplateNode : public BaseNode {

    std::map<std::string, init_prop<TemplateNode>> prop_func = 
    {

    };

public:

     TemplateNodeNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = " Template";


    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;
    virtual void input(input_struct event) override;

    /** init_attributes
    
    void init_attribute(toml_value);
    **/

   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~TemplateNode()= default;

};