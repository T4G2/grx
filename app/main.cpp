

#include <string>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "game_application.hpp"

int main(int argc, char** argv) {
    //GameApplication apk = GameApplication(1920, 1080, "Hello World", true);
    GameApplication apk = GameApplication(1080, 720, "Hello World", false);
    return apk.run();
    
}
