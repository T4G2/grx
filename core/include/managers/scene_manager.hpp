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

class SceneManager {

    std::vector<Scene> scenes;
    Scene* active_scene;

    std::map<std::string, BaseNodeFactory> _registered_nodes;

public:

    void load(Scene&& scene) {
        scenes.push_back(std::move(scene));
        active_scene = &scenes[scenes.size() - 1];
    }

    void bind_basic_nodes(); // Binding Nodes = 

    static Scene load_from_file(std::string filepath);

    void register_node(BaseNodeFactory&& factory);



};