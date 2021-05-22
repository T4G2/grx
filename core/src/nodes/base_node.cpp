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

    void BaseNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {
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
        if (!value.is_array()) {
            std::cerr << "WARNING, pos in <" << name << "> is not array. example: pos = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, pos in <" << name << "> is not array of size 3. example: pos = [0.0, 0.0, 0.0]\n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, pos in <" << name << "> is not array of float numbers. example: pos = [0.0, 0.0, 0.0] \n";
                return;
        }

        pos.x = array.at(0).as_floating();
        pos.y = array.at(1).as_floating();
        pos.z = array.at(2).as_floating(); 

   }
   void BaseNode::init_rot( toml_value value) {
        if (!value.is_array()) {
            std::cerr << "WARNING, rot in <" << name << "> is not array. example: rot = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, rot in <" << name << "> is not array of size 3. example: rot = [0.0, 0.0, 0.0]\n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, rot in <" << name << "> is not array of float numbers. example: rot = [0.0, 0.0, 0.0] \n";
                return;
        }

        rot.x = array.at(0).as_floating();
        rot.y = array.at(1).as_floating();
        rot.z = array.at(2).as_floating(); 
   }
   void BaseNode::init_scl( toml_value value) {
       if (!value.is_array()) {
            std::cerr << "WARNING, scl in <" << name << "> is not array.  example: scl = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, scl in <" << name << "> is not array of size 3. example: scl = [0.0, 0.0, 0.0] \n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, scl in <" << name << "> is not array of float numbers. example: scl = [1.0, 1.0, 1.0] \n";
                return;
        }

        scl.x = array.at(0).as_floating();
        scl.y = array.at(1).as_floating();
        scl.z = array.at(2).as_floating(); 
   }
