/**
 * @file iapplication.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Basic Application Interface
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <cstdint>
#include <string>

#include "resource_manager.hpp"

class IApplication {
    int width;
    int height;
    std::string name;
    bool fullscreen;
    ResourceManager resource_manager;

    GLFWwindow* window = nullptr;

    double last_time = 0;


    int init_error_manager();
    int init_window();


    //PRIVATE FUNCTIONS
    int init() {
        //init Others
        init_custom();
        return init_window();
    }
    int loop();

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


    virtual void input() = 0;
    virtual void update(double delta) = 0;
    virtual void render() = 0;

    virtual void init_custom() = 0;
};
