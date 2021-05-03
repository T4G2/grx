/**
 * @file iapplication.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Basic Application Interface
 * @version 0.1
 * @date 2021-05-01
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <cstdint>
#include <string>

class IApplication {
    int width;
    int height;
    std::string name;
    bool fullscreen;

    GLFWwindow* window = nullptr;


    int initErrorManager();
    int initWindow();

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

    int init() {
        //init Others

        return initWindow();
    }
    int loop();
    int run() {
        if (init()) {
            // ERROR HANDLING
        }
        return loop();
    }
};
