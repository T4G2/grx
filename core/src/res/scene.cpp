/**
 * @file scene.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 */
#include "scene.hpp"
#include "toml.hpp"



void Scene::init() {
if (_root_i == -1) {
            std::cerr << "Scene::init| No root for scene: <" << get_path() << ">\n"; 
            return;
        }
        get_root().init(); 
    };


void Scene::update(float delta) {
        if (_root_i == -1) {
            std::cerr << "Scene::update| No root for scene: <" << get_path() << ">\n"; 
            return;
        }
        get_root().update(delta); 
    };

void Scene::draw() {
        if (_root_i == -1) {
            std::cerr << "Scene::draw| No root for scene: <" << get_path() << ">\n"; 
            return;
        }

        if (activeCamera == nullptr) {
            std::cerr << "Scene::draw| No active camera for scene: <" << get_path() << ">\n"; 
            return;
        }
        CameraNode* camera_data  = activeCamera;
        get_root().draw(); 
        };

BaseNodeInstance& Scene::get_root() {
    if (_root_i == -1) {
        std::cerr << "Scene::get_root()|  there is not root in this Scene <" << get_path() << "> \n";
    }
    return *(_nodes[_root_i]);
}

void Scene::create_root() {
    if (_root_i != -1) {
        std::cerr << "Scene::create_root()|  there is already a root in this Scene <" << get_path() << "> \n";
        throw std::exception("Scene::create_root()|  there is already a root in this Scene");
    }

    _root_i = _nodes.size();
    _nodes.push_back(std::make_unique<NodeInstance<BaseNode>>(this, nullptr, "__root"));
}