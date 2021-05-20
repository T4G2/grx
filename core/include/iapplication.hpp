/**
 * @file iapplication.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Basic Application Interface
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once


#include <cstdint>
#include <string>

#include <glad\glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "mylib.hpp"
#include "open_gl_error.hpp"

#include "base_resource_manager.hpp"
#include "texture.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "mesh.hpp"
#include "scene.hpp"
#include "scene_manager.hpp"

class IApplication {


    GLFWwindow* window = nullptr;

    int init_error_manager();
    int init_window();
    int init_input();
    int init_gl_callback();

    // REMOVE ON RELEASE
    int init_path_debug();


    //PRIVATE FUNCTIONS
    int init(){
        //init Others
        init_window();
        init_gl_callback();
        init_input();
        init_path_debug();
        init_custom();

        return 0;
    }
    int loop();

protected:

    BaseResourceManager<Texture> texture_manager;
    BaseResourceManager<Program> program_manager;
    BaseResourceManager<Shader> shader_manager;
    BaseResourceManager<Mesh> mesh_manager;
    SceneManager scene_manager;
    int width;
    int height;
    std::string name;
    bool fullscreen;

    double last_time = 0;


    GLFWwindow *get_window() {
        return window;
    }

    std::string res_path = "";

public:
    /**
     * @brief Construct a new IApplication object
     * 
     * @param width_a 
     * @param height_a 
     * @param name_a 
     * @param fullscreen_a 
     */
    
    IApplication(int width_a = 1080, int height_a = 720, std::string name_a = "Window", bool fullscreen_a = false):
        width(width_a),
        height(height_a),
        name(name_a),
        fullscreen(fullscreen_a)
        {};

    int run() {
        if (init()) {
            // ERROR HANDLING
        }


        return loop();
    }

    virtual void update(double delta) = 0;
    virtual void render() = 0;

    virtual void on_resize(int width, int height) = 0;

    virtual void on_key_press(int key, int scancode, int action, int mods) = 0;
    virtual void on_mouse_button(int button, int action, int mods) = 0;
    virtual void on_mouse_move(double x, double y) = 0;
    


    virtual void init_custom() = 0;

};
