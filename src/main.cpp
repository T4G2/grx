

#include <string>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

int main(int argc, char** argv) {
    int initial_width = 1280;
    int initial_height = 720;

    if (!glfwInit()) {
        std::cout << "Error while glfwInit()";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(initial_width, initial_height, "EXPERIMENT_01",NULL, NULL);

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
    glViewport(0, 0, initial_width, initial_height);
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;


    GLfloat buff_data[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };


    GLuint bufferID;
    glCreateBuffers(1,&bufferID);

    glNamedBufferStorage(bufferID, sizeof(float) * 6, &buff_data, GL_DYNAMIC_STORAGE_BIT);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


        /* LOOP */
    while(!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        /* OpenGL code */

        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}
