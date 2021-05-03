#include "../include/iapplication.hpp"

#include <iostream>




int IApplication::init_window(){

    if (!glfwInit()) {
        std::cout << "Error while glfwInit()";
        return -1;
    }


    GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : NULL;

    window = glfwCreateWindow(width, height, name.c_str(), monitor, NULL);

    if (!window) {
        glfwTerminate();
        std::cout << "ERROR";
        return -1;
    }

    glfwMakeContextCurrent(window);

        /* Link lgfw with GLAD*/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Could not initialize OpenGL context!" << std::endl;
        return -1;
    }

        /* set viewport */
    glViewport(0, 0, width, height);
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    last_time = glfwGetTime();
    return 0;

};

int IApplication::init_input() {
    glfwSetWindowUserPointer(window, this);

    auto on_mouse_button = [](GLFWwindow* w, int button , int action, int mods){
        static_cast<IApplication*>(glfwGetWindowUserPointer(w))->on_mouse_button( button, action, mods );
    };

    auto on_mouse_move = [](GLFWwindow* w, double x , double y) {
        static_cast<IApplication*>(glfwGetWindowUserPointer(w))->on_mouse_move( x, y);
    };

    auto on_key_press = [](GLFWwindow* w, int key, int scancode, int action, int mods) {
        static_cast<IApplication*>(glfwGetWindowUserPointer(w))->on_key_press( key, scancode, action, mods);
    };

    auto on_resize = [](GLFWwindow* w, int x, int y) {
        static_cast<IApplication*>(glfwGetWindowUserPointer(w))->on_resize( x, y);
    };


    glfwSetMouseButtonCallback(window, on_mouse_button);
    glfwSetCursorPosCallback(window, on_mouse_move);
    glfwSetKeyCallback(window, on_key_press);
    glfwSetWindowSizeCallback(window, on_resize);

    return 0;
}



int IApplication::loop() {

        /* LOOP */
    
    while(!glfwWindowShouldClose(window)) {
        double tmp_time = glfwGetTime();
        double delta_time = tmp_time - last_time;
        last_time = tmp_time;
        //glClear(GL_COLOR_BUFFER_BIT);

        // input
        // update
        update(delta_time);
        // draw

        /* OpenGL code */
        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwTerminate();

    return 0;

}
