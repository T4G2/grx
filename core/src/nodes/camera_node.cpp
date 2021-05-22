/**
 * @file camera_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#include "camera_node.hpp"


void CameraNode::init() {
    std::cout << "Not defined Node< <<" << "CameraNode" << ">::init \n";
    look_at = 125;
}   

void CameraNode::update(float delta) {
    std::cout << "Not defined Node< <<" << "CameraNode" << ">::update \n";
}
void CameraNode::draw() {
    std::cout << "Not defined Node< <<" << "CameraNode" << ">::draw \n";
}




void CameraNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {
    std::cout << "CAMERA TOML\n";

    BaseNode::init_custom_toml(props);

    for (auto [name, obj] : props) {

    }
};