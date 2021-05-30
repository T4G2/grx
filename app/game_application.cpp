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

#include "nodes/movement_node.hpp"
#include "triangle_debug_node.hpp"


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
    program_manager.load(Program("res/programs/basic_phong.toml", shader_manager));
    texture_manager.load(Texture("res/textures/Planks_01_ALBEDO.png"));

    graphics_manager = GraphicsManager(& scene_manager, &texture_manager,&program_manager, this);


    // mesh_manager.load(Mesh("res/meshs/Koenigsegg.obj"));

    // TRY  TO CREATE NEW NODE OF ANY TYPE

    glClearColor(0, 0, 0, 1);
    glViewport(0, 0, width, height);

    scene_manager.register_node<BaseNode>();
    scene_manager.register_node<CameraNode>();
    scene_manager.register_node<MovementNode>();
    scene_manager.register_node<TriangleDebugNode>();

    // s = scene_manager.load(SceneManager::load_from_file("res/scenes/main.toml"));
    scene_manager.load_from_file("res/scenes/main.toml", true);
    //auto x = scene_manager.get_node_factory("Camera").get_pointer_to_new_instance(nullptr, s );
    // WTF is happening here
    // std::cout << typeid(x).name() <<"\n";
    //x->init();
    glfwSetInputMode(get_window(),GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    scene_manager.get_active_scene()->init();
}


void GameApplication::update(double delta) {
   // std::cout << "Delta time:" << delta << " \n";
   for (int key_key : keys_pressed) {
       input_struct event;
       event.input_type = KEY_DOWN;
       event.key = key_key;
       scene_manager.input(event);
   }

   for (int mouse_button : mouse_pressed) {
       input_struct event;
       event.input_type = MOUSE_BUTTON_DOWN;
       event.button = mouse_button;
       scene_manager.input(event); 
   }

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
    if (action == GLFW_PRESS) {
        keys_pressed.insert(key);
        input_struct event;
        event.input_type = KEY_PRESS;
        event.key = key;
        event.scancode = scancode;
        event.action = action;
        event.mods = mods;
        scene_manager.input(event);
    } 
    else if (action == GLFW_RELEASE) {
        keys_pressed.erase(key);
        input_struct event;
        event.input_type = KEY_RELEASE;
        event.key = key;
        event.scancode = scancode;
        event.action = action;
        event.mods = mods;
        scene_manager.input(event);
    }


};

void GameApplication::on_mouse_move(double x, double y){
    if (last_x == -1 && last_y == -1) {
        last_x = x;
        last_y = y;
        return;
    }
    //std::cout << "x: " << x << ", y:" << y << "\n";
    input_struct event;
    event.input_type = MOUSE_MOVE;

    event.dx = x - last_x;
    event.dy = y - last_y;
    last_x = x;
    last_y = y;
    scene_manager.input(event);
};

void GameApplication::on_mouse_button(int button, int action, int mods){
    if (action == GLFW_PRESS) {
        mouse_pressed.insert(button);
        input_struct event;
        event.input_type = MOUSE_BUTTON_PRESS;
        event.button = button;
        event.action = action;
        event.mods = mods;
        scene_manager.input(event);
    } 
    else if (action == GLFW_RELEASE) {
        mouse_pressed.erase(button);
        input_struct event;
        event.input_type = MOUSE_BUTTON_RELEASE;
        event.button = button;
        event.action = action;
        event.mods = mods;
        scene_manager.input(event);
    } 
};