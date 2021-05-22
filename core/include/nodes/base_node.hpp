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

    virtual void  init() {
        std::cout << "Not defined Node< <<" << "BaseNode" << ">::init \n";
    }   

    virtual void update(float delta) {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::update \n";
    }
    virtual void draw() {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::draw \n";
    }

    virtual void init_custom_toml(BaseNodeInstance::toml_properties_t& props) {
        std::cout << "BASE TOML\n";

        for (auto& [name, obj] : props) {
            std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
            //pos, rot, scale
        }
    };

   void init_pos( toml_value value) {
       std::cout << "init pos in BASE \n";
   }
   void init_rot( toml_value value) {
       std::cout << "init rot in BASE \n";
   }
   void init_scl( toml_value value) {
       std::cout << "init scl in BASE \n";
   }

    virtual ~BaseNode()= default;
};

class CameraNode : BaseNode {

    std::map<std::string, void (CameraNode::*)(BaseNodeInstance::toml_properties_t)> prop_func;

public:

    inline static const std::string NODE_NAME = "Camera";
    int look_at = 0;

    void init() override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::init \n";
        look_at = 125;
    }   

    void update(float delta) override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::update \n";
    }
    void draw() override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::draw \n";
    }


    virtual ~CameraNode()= default ;

    void init_custom_toml(BaseNodeInstance::toml_properties_t& props) override {
        std::cout << "CAMERA TOML\n";

        BaseNode::init_custom_toml(props);

        for (auto [name, obj] : props) {

        }
    };

};

