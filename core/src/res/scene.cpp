/**
 * @file scene.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 */
#include "scene.hpp"
#include "toml.hpp"


Scene Scene::load_from_file(std::string filepath){
    try {
        auto data = toml::parse(filepath);
        auto x = data.type();
    }

     catch (std::exception e) {
         std::cerr << "Scene::load_from_file <" << filepath << "> Error: \n";
         std::cerr << e.what() << "\n";
     }


    return Scene();
}

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
    
    return _nodes[_root_i];
}