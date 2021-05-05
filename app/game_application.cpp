/**
 * @file application.cpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#include <iostream>

#include "game_application.hpp"

void GameApplication::init_custom() {

}



void GameApplication::update(double delta) {
   // std::cout << "Delta time:" << delta << " \n";
}

void GameApplication::render() {

}

void GameApplication::on_resize(int width, int height) {
    std::cout << "w: " << width << ", h:" << height << "\n";
};
    
void GameApplication::on_key_press(int key, int scancode, int action, int mods){
    std::cout << "{" << key << "} \n";

};

void GameApplication::on_mouse_move(double x, double y){
    std::cout << "x: " << x << ", y:" << y << "\n";

};

void GameApplication::on_mouse_button(int button, int action, int mods){
    std::cout << "{" << button << "} \n";

};