

#include <string>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "iapplication.hpp"

int main(int argc, char** argv) {

    IApplication apk = IApplication(1080, 720, "Hello World", false);
    return apk.run();
    
}
