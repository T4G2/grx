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

class SceneManager {

    std::vector<Scene> scenes;
    Scene* active_scene;

    std::map<std::string, BaseNode> _registered_nodes;

public:
    void bind_basic_nodes(); // Binding Nodes = 

    static Scene load_from_file(std::string filepath);



};