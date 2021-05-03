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
