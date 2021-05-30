/**
 * @file application.cpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#include <iostream>
#include <filesystem>

#include "base_node_instance.hpp"
#include "node_instance.hpp"
#include "base_node.hpp"
#include "node_factory.hpp"

#include "game_application.hpp"




void GameApplication::init_custom() {


 /* TESTS*/
    std::cout << "Setting path from: \n";
    std::cout << std::filesystem::current_path() << "\n";
    change_curr_dir_debug(res_path);
    std::cout << "to: \n";
    std::cout << std::filesystem::current_path() << "\n";
    shader_manager.load(Shader(GL_VERTEX_SHADER, "res/shaders/main.vert"));
    shader_manager.load(Shader(GL_FRAGMENT_SHADER, "res/shaders/main.frag"));
    //program_manager.load(Program( "debug_program", shader_manager.get_by_name("res/shaders/main.vert"),
    //                                shader_manager.get_by_name("res/shaders/main.frag")));
    program_manager.load(Program("res/shaders/programs.toml", shader_manager));
    texture_manager.load(Texture("res/textures/Planks_01_ALBEDO.png"));

    graphics_manager = GraphicsManager(& scene_manager, &texture_manager,&program_manager, this);


    // mesh_manager.load(Mesh("res/meshs/Koenigsegg.obj"));

    // TRY  TO CREATE NEW NODE OF ANY TYPE

    glClearColor(0, 0, 0, 1);
    glViewport(0, 0, width, height);

    scene_manager.register_node<BaseNode>();
    scene_manager.register_node<CameraNode>();

    // s = scene_manager.load(SceneManager::load_from_file("res/scenes/main.toml"));
    scene_manager.load_from_file("res/scenes/main.toml", true);
    //auto x = scene_manager.get_node_factory("Camera").get_pointer_to_new_instance(nullptr, s );
    // WTF is happening here
    // std::cout << typeid(x).name() <<"\n";
    //x->init();
    scene_manager.get_active_scene()->init();
}


void GameApplication::update(double delta) {
   // std::cout << "Delta time:" << delta << " \n";
   scene_manager.get_active_scene()->update(delta);
   scene_manager.get_active_scene()->draw();
   
}

void GameApplication::render() {
    graphics_manager.draw();
}

void GameApplication::on_resize(int width_a, int height_a) {
    //std::cout << "w: " << width << ", h:" << height << "\n";
    width = width_a;
    height = height_a;
    glViewport(0, 0, width, height);
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