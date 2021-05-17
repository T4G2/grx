/**
 * @file scene.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 */
#include "scene.hpp"
#include "toml.hpp"




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
        get_root().draw(); 
        };

BaseNodeInstance& Scene::get_root() {
    if (_root_i == -1) {
        std::cerr << "Scene::get_root()|  there is not root in this Scene <" << get_path() << "> \n";
    }
    return _nodes[_root_i];
}