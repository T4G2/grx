/**
 * @file base_node.hpp
 * @author your name (you@domain.com)
 * @brief Base Node
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <map>

#include "node_instance.hpp"
#include "glm/glm.hpp"

using toml_value = toml::basic_value<toml::discard_comments,std::unordered_map,std::vector>; 
template <class T>
using init_prop = void (T::*)(toml_value);

class BaseNode {

    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 scl = glm::vec3(1.0, 1.0, 1.0);

    std::map<std::string, init_prop<BaseNode>> prop_func = 
    {
        {"pos", &BaseNode::init_pos},
        {"rot", &BaseNode::init_rot},
        {"scl", &BaseNode::init_scl},
    };

public:

    const std::string name;
    BaseNodeInstance& instance;

    bool _updated_position = true;
    glm::mat4 local_space_matrix;

    inline static const std::string NODE_NAME = "Base";

    BaseNode(std::string name_a, BaseNodeInstance& _instance) : name(name_a), instance(_instance) { };
    
    virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props);

    virtual void  init();
    virtual void update(float delta);
    virtual void draw();

   void init_pos( toml_value value);
   void init_rot( toml_value value);
   void init_scl( toml_value value);

   void update_matrix_if_needed();

    virtual ~BaseNode()= default;
};



