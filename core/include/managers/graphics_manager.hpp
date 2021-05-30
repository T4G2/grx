/**
 * @file graphics_manager.hpp
 * @author your name (you@domain.com)
 * @brief Graphics manager is used for creating rendering pipeline
 * @version 0.1
 * @date 2021-05-29
 */
#pragma once

#include "scene_manager.hpp"
#include "base_resource_manager.hpp"
#include "texture.hpp"
#include "program.hpp"


class IApplication;

class GraphicsManager {

    IApplication* app = nullptr;
    SceneManager* scene_manager = nullptr;
    BaseResourceManager<Texture>* texture_manager = nullptr;
    BaseResourceManager<Program>* program_manager = nullptr;

public:
    GraphicsManager () = default;
    GraphicsManager (SceneManager* scene_manager_a,
            BaseResourceManager<Texture>* texture_manager_a,
            BaseResourceManager<Program>* program_manager_a,
            IApplication* app_a) :
        scene_manager(scene_manager_a),
        texture_manager(texture_manager_a),
        program_manager(program_manager_a),
        app(app_a) { };



    
    void draw();
};
