#include "../include/iapplication.hpp"

#include <iostream>




int IApplication::initWindow(){


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

    return 0;

};



int IApplication::loop() {

        /* LOOP */
    while(!glfwWindowShouldClose(window)) {

        //glClear(GL_COLOR_BUFFER_BIT);

        // input
        // update
        // draw

        /* OpenGL code */
        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwTerminate();

    return 0;

}