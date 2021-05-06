/**
 * @file application.cpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#include <iostream>
#include <filesystem>

#include "game_application.hpp"


void GameApplication::init_custom() {
    // load 
    //texture_manager.load( Texture("res/textures/img.jpg"));

 /* TESTS*/
    std::cout << "Setting path from: \n";
    std::cout << std::filesystem::current_path() << "\n";
    change_curr_dir_debug(res_path);
    std::cout << "to: \n";
    std::cout << std::filesystem::current_path() << "\n";
    shader_manager.load(Shader(GL_VERTEX_SHADER, "res/shaders/main.vert"));
    shader_manager.load(Shader(GL_FRAGMENT_SHADER, "res/shaders/main.frag"));
    program_manager.load(Program(shader_manager.get_by_name("res/shaders/main.vert"),
                                    shader_manager.get_by_name("res/shaders/main.frag")));

    texture_manager.load(Texture("res/textures/Planks_01_ALBEDO.png"));

    glClearColor(1, 0, 0, 1);

}



void GameApplication::update(double delta) {
   // std::cout << "Delta time:" << delta << " \n";
}

void GameApplication::render() {

}

void GameApplication::on_resize(int width, int height) {
    //std::cout << "w: " << width << ", h:" << height << "\n";
};
    
void GameApplication::on_key_press(int key, int scancode, int action, int mods){
    //std::cout << "{" << key << "} \n";

};

void GameApplication::on_mouse_move(double x, double y){
    //std::cout << "x: " << x << ", y:" << y << "\n";

};

void GameApplication::on_mouse_button(int button, int action, int mods){
    std::cout << "{" << button << "} \n";

};