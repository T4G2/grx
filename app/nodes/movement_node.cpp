/**
 * @file movement_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */

#include "movement_node.hpp"
#include "GLFW/glfw3.h"


void MovementNode::init() {
}   

void MovementNode::update(float delta) {

    if (_updated_position) {
        BaseNode::update(delta);
    }


}
void MovementNode::draw() {
}


void MovementNode::input(input_struct event) {
//std::cout << event.input_type << "\n";
if (event.input_type == MOUSE_MOVE) {

    float dx = event.dx * sensitivity;
    float dy = event.dy * sensitivity;
    //std::cout << "<" << dx << ", " << dy << ">\n";
    add_rot(glm::vec3(dy, dx, 0));
}

if (event.input_type == KEY_DOWN) {
    
    glm::vec4 movement_relative = glm::vec4(0);
    glm::vec4 movement_global = glm::vec4(0);
    movement_global.w = 1;
    movement_relative.w = 1;
    switch (event.key) {
        case GLFW_KEY_W:
            movement_relative.z++;
            break;
        case GLFW_KEY_S:
            movement_relative.z--;
            break;
        case GLFW_KEY_A:
            movement_relative.x++;
            break;
        case GLFW_KEY_D:
            movement_relative.x--;
            break;
        
        case GLFW_KEY_SPACE:
            movement_global.y--;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            movement_global.y++;
            break;
    }
    auto movement = glm::inverse(rotation_matrix) * movement_relative + movement_global;
    //std::cout << "(" << movement.x << ", " << movement.y << ", " << movement.z << ") \n";

    add_pos(movement * speed);

}
BaseNode::input(event); // propagate to children
}


void MovementNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {
    BaseNode::init_custom_toml(props);
    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
}

void MovementNode::init_sensitivity(toml_value props) {
    if (!props.is_floating()) {
        std::cerr << "WARNING, sensitivitye in <" << name << "> is not a floating value. example: sensitivity = 0.01f\n";
        return;
    }
    sensitivity = props.as_floating();
}

void MovementNode::init_speed(toml_value props){
    if (!props.is_floating()) {
        std::cerr << "WARNING, speed in <" << name << "> is not a floating value. example: speed = 0.01f\n";
        return;
    }

    speed = props.as_floating();

}
