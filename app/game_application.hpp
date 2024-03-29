/**
 * @file game_application.hpp
 * @author Patirk Baso(492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */
#pragma once
#include <set>

#include "iapplication.hpp"
#include "base_resource_manager.hpp"
#include "scene_manager.hpp"
#include "texture.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "mesh.hpp"
#include "scene.hpp"


class GameApplication : public IApplication {

public:

    int last_x = -1;
    int last_y = -1;

    bool cursor_showing = false;
 
    std::set<int> keys_pressed = {};
    std::set<int> mouse_pressed = {};


    int TIMING_INTERVAL = 50;
    int timing_counter = 0;
    float average_render_time = 0;

    float time_factor = 1.0f;


    GameApplication(int width_a = 1080, int height_a = 720, std::string name_a = "Window", bool fullscreen_a = false):
          IApplication(width_a, height_a, name_a, fullscreen_a){}

    void update(double delta) override;
    void render() override;
    void init_custom() override;

    void on_resize(int width, int height) override;
    
    void on_key_press(int key, int scancode, int action, int mods) override;
    void on_mouse_move(double x, double y) override;
    void on_mouse_button(int button, int action, int mods) override;


};
