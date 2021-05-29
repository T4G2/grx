/**
 * @file scene_manager.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 */

#include <toml.hpp>

#include "scene_manager.hpp"



void SceneManager::load_from_file(std::string filepath,bool set_as_active) {
    try {
        toml::basic_value data = toml::parse(filepath);

        
        Scene final_scene = Scene(*this, filepath);

        final_scene.create_root();
        BaseNodeInstance& root =  final_scene.get_root();

        root.setup_by_toml(data);

        this->load(std::move(final_scene), set_as_active);

    }

     catch (std::exception e) {
         std::cerr << "Scene::load_from_file <" << filepath << "> Error: \n";
         std::cerr << e.what() << "\n";
     }
}

