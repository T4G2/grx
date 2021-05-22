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

using toml_value = toml::basic_value<toml::discard_comments,std::unordered_map,std::vector>; 
template <class T>
using init_prop = void (T::*)(toml_value);

class BaseNode {
 std::map<std::string, init_prop<BaseNode>> prop_func = 
 {
     {"pos", &BaseNode::init_pos},
     {"rot", &BaseNode::init_rot},
     {"scl", &BaseNode::init_scl},
 };

public:


    inline static const std::string NODE_NAME = "Base";

    
    virtual void init_custom_toml(BaseNodeInstance::toml_properties_t& props);

    virtual void  init();
    virtual void update(float delta);
    virtual void draw();

   void init_pos( toml_value value);
   void init_rot( toml_value value);
   void init_scl( toml_value value);

    virtual ~BaseNode()= default;
};



