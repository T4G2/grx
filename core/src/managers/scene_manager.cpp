/**
 * @file scene_manager.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 */

#include <toml.hpp>

#include "scene_manager.hpp"



Scene SceneManager::load_from_file(std::string filepath){
    try {
        auto data = toml::parse(filepath);


        // TODO DO THIS IN ROOT IBJECT AND THEN RECURSIVELY IN CHILDREN OBJECTS!
        if (!data.is_table()) {
            std::cerr << "SceneManager::load_from_file| The Scene <" << filepath << "> root is not an toml table!\n";
            throw std::exception("SceneManager::load_from_file| The Scene root is not an toml table!\n");
        }

        for (auto node: data.as_table()) {
            
            std::cout << node.first << "\n";
        }
    }

     catch (std::exception e) {
         std::cerr << "Scene::load_from_file <" << filepath << "> Error: \n";
         std::cerr << e.what() << "\n";
     }


    return Scene();
}
