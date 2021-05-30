/**
 * @file scene_manager.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <vector>

#include "scene.hpp"
#include "base_node.hpp"
#include "node_factory.hpp"
#include "input_struct.hpp"

class SceneManager {

    std::vector<Scene> scenes;
    Scene* active_scene;

    std::map<std::string, std::unique_ptr<BaseNodeFactory>> _registered_nodes;

public:

    void load(Scene&& scene, bool set_as_active) {
        scenes.push_back(std::move(scene));
        scenes[scenes.size() - 1].update_scene_pointers();
        if (set_as_active){
            active_scene = &scenes[scenes.size() - 1];
        }
    }

    void bind_basic_nodes(); // Binding Nodes = 

    void load_from_file(std::string filepath, bool set_as_active);

    Scene* get_active_scene() { return active_scene; };

    template <class T>
    void register_node() {
        std::string name = T::NODE_NAME;
        if (_registered_nodes.count(name)) {
            std::cerr << "SceneManager::register_node| Node<" << name << "> already registered! \n";
            throw std::exception("SceneManager::register_node| No already registered!");
        }
    _registered_nodes.insert({name, std::make_unique<NodeFactory<T>>()});
}


    BaseNodeFactory& get_node_factory(std::string name) {
        if (!_registered_nodes.contains(name)) {
            std::cerr<< "SceneManager::get_node_factory| No factory with name <" << name <<">\n ";
            throw std::exception("SceneManager::get_node_factory| No factory with given name");
        }
        return *_registered_nodes[name];
    }


    std::unique_ptr<BaseNodeInstance> get_root_unique_ptr(toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector> data);


    void input(input_struct event) {
        active_scene->get_root().get_data()->input(event);
    }
};