/**
 * @file base_node_instance.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-19
 */
#pragma once

#include "base_node_instance.hpp"
#include "scene.hpp"
#include "scene_manager.hpp"

void BaseNodeInstance::update(float delta){
        for (BaseNodeInstance* child : _children_i) {
            child->update(delta);
        }
    };


std::pair<bool, std::string> is_node(toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector> data) {
    if (!data.is_array()) {
        return {false, ""};
    }
    auto array = data.as_array();
    if (array.size() != 1) {
        return  {false, ""};
    }

    auto obj = array.at(0);

    if (!obj.is_table()) {
        return  {false, ""};
    }
    auto table = obj.as_table();

    if (!table.contains("type")){
        return  {false, ""};
    }

    if (!table["type"].is_string()) {
        return  {false, ""};
    }

    return {true, table["type"].as_string().str};
}


void BaseNodeInstance::setup_by_toml(toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector> data) {
      
    // TODO DO THIS IN ROOT IBJECT AND THEN RECURSIVELY IN CHILDREN OBJECTS!
    if (!data.is_table()) {
        
        std::cerr << "SceneManager::load_from_file| The scene <" << _scene.get_path() << "> is trying to load non-table toml as NodeInstance!\n";
        throw std::exception("SceneManager::load_from_file| The scene is trying to load non-table toml as NodeInstance!");
    }
    

    toml_properties_t properties;

    for (auto node: data.as_table()) {
        auto [name, obj ] = node;
        auto [is_node_, node_name] = is_node(obj);

        if (obj.is_array() && is_node_) {
            std::cout << "NODE <" << node_name <<"> \n";
            // this is another node inside

            SceneManager& manager = _scene.get_scene_manager();
            auto new_instance = manager.get_node_factory(node_name).get_pointer_to_new_instance(this, _scene, name);

            new_instance.get()->setup_by_toml(obj.as_array().at(0).as_table());
            insert_child(_scene.insert_child(std::move(new_instance)));
        } else {
            // Is attribute
            if (name == "type") {
                continue;
            }
            properties.push_back({name, obj});
        }

        //std::cout << name << "\n";
        //std::cout << obj << "\n";
    }
    init_custom_toml(properties);

}


void BaseNodeInstance::init_custom_toml(toml_properties_t prop) {
    for (auto [name, _] : prop) {
        std::cout << "Additional parameter <" << name << ">\n";
    }
}