/**
 * @file template_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */


#include "template_node.hpp"

void TemplateNode::init() {
}   

void TemplateNode::update(float delta) {
}
void TemplateNode::draw() {
}

void TemplateNode::input(input_struct event) {

BaseNode::input(event); // propagate to children
}




void TemplateNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) { /** Must be in class **/

    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
};

/** init attributes **/