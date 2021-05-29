/**
 * @file scene.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Scene Class
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once

#include <memory>
#include <string>
#include <map>

#include "base_resource.hpp"
#include "base_node_instance.hpp"
#include "node_instance.hpp"


#include "camera_node.hpp"

class SceneManager;


class Scene : public BaseResource {

    using priority_t = int;
    using material_t = int;

    SceneManager& _scene_manager;

    CameraNode* activeCamera = nullptr;
    long int _root_i = -1;
    std::vector<std::unique_ptr<BaseNodeInstance>> _nodes;


    
    //std::map<priority_t, std::vector<material_t, std::vector<BaseNodeInstance*>>> _render_tree;

public:

    Scene(SceneManager& scene_manager): _scene_manager(scene_manager) { _empty = true; }
    Scene(SceneManager& scene_manager, std::string name): _scene_manager(scene_manager) {_path = name;};

    friend void CameraNode::init();

    void init();
    void input(); // inputs
    void update(float delta);
    void draw();

    void create_root();

    BaseNodeInstance& get_root();
    BaseNodeInstance& get_child(int index){ return *_nodes[index]; }

    SceneManager& get_scene_manager() {return _scene_manager;};

    BaseNodeInstance* insert_child(std::unique_ptr<BaseNodeInstance>&& node) {
        int index = static_cast<int>(_nodes.size());
        _nodes.push_back(std::move(node));
        return _nodes[index].get();
    }

    void update_scene_pointers() {
        for (auto& node: _nodes) {
            node->update_scene_pointer(this);
        }
    }

};