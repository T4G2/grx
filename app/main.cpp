

#include <string>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "game_application.hpp"

int main(int argc, char** argv) {
    GameApplication apk = GameApplication(1920, 1080, "PV112", true);
    //GameApplication apk = GameApplication(1080, 720, "Hello World", false);
    //GameApplication apk = GameApplication(320, 240, "Hello World", true);
    return apk.run();
    
}
