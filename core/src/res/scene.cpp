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
    auto data = toml::parse(filepath);

    return Scene();
}
