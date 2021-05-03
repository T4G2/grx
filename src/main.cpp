

#include <string>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "game_application.hpp"
#include "resource_manager.hpp"

int main(int argc, char** argv) {
    GameApplication apk = GameApplication(1080, 720, "Hello World", false);
    return apk.run();
    
}
