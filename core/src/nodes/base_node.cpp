/**
 * @file base_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */

#include "base_node.hpp"



    void  BaseNode::init() {
        std::cout << "Not defined Node< <<" << "BaseNode" << ">::init \n";
    }   

    void BaseNode::update(float delta) {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::update \n";
    }
    void BaseNode::draw() {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::draw \n";
    }

    void BaseNode::init_custom_toml(BaseNodeInstance::toml_properties_t& props) {
        std::cout << "BASE TOML\n";

        for (auto& [name, obj] : props) {
            std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
            //pos, rot, scale
        }
    };

   void BaseNode::init_pos( toml_value value) {
       std::cout << "init pos in BASE \n";
   }
   void BaseNode::init_rot( toml_value value) {
       std::cout << "init rot in BASE \n";
   }
   void BaseNode::init_scl( toml_value value) {
       std::cout << "init scl in BASE \n";
   }
