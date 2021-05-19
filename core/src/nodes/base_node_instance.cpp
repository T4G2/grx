/**
 * @file base_node_instance.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-19
 */


#include "base_node_instance.hpp"
#include "scene.hpp"

void BaseNodeInstance::update(float delta){
        for (int index : _children_i) {
            _scene.get_child(index);
        }
    };


void BaseNodeInstance::setup_by_toml(toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector> data) {
      
    // TODO DO THIS IN ROOT IBJECT AND THEN RECURSIVELY IN CHILDREN OBJECTS!
    if (!data.is_table()) {
        std::cerr << "SceneManager::load_from_file| The Scene <" << _scene.get_path()<< "> root is not an toml table!\n";
        throw std::exception("SceneManager::load_from_file| The Scene root is not an toml table!\n");
    }

    for (auto node: data.as_table()) {
        auto [name, obj ] = node;
        std::cout << name << "\n";
        std::cout << obj << "\n";
    }
}