/**
 * @file render_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */

#include "render_node.hpp"
#include "scene_manager.hpp"
#include "iapplication.hpp"


void RenderNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {

    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
};

void RenderNode::init_program(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, program type in <" << name << "> is not a string. example: program = \"PATH\"\n";
        return;
    }
    
    program_ptr = nullptr;
    auto& program_manager = instance.get_scene()->get_scene_manager().app.program_manager;
    if (!program_manager.exists(data.as_string())) {
        std::cerr << "RenderNode::init_custom_toml | there is no Program with name <" << data.as_string() << ">\n";
        return;
    }
    else program_ptr = &program_manager.get_by_name(data.as_string());
    

}