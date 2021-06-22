/**
 * @file rotationg_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "rotating_node.hpp"
#include "glm/gtx/common.hpp"

void RotatingNode::init() {

    BaseNode::init();
}   

void RotatingNode::update(float delta) {
    add_rot(glm::vec3(delta * glm::pi<float>() * frequency, 0, 0));
    BaseNode::update(delta);
}
void RotatingNode::draw() {
}

void RotatingNode::input(input_struct event) {

BaseNode::input(event); // propagate to children
}


void RotatingNode::init_frequency(toml_value data){
    if (!data.is_floating()) {
        std::cout<< "frequency in Node <" << name << "is not floating number\n";
        return;
    }

    frequency = data.as_floating();
}



void RotatingNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) { /** Must be in class **/

    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
};

/** init attributes **/