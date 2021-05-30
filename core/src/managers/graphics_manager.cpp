/**
 * @file graphics_manager.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-29
 */

#include <iostream>

#include "glad.h"
#include "GLFW/glfw3.h"

#include "graphics_manager.hpp"
#include "iapplication.hpp"




void GraphicsManager::draw() {

    glBindVertexArray(0);
    glViewport(0, 0, app->width / 2, app->height);
    program_manager->get(0).use();
    CameraNode* active_camera = scene_manager->get_active_scene()->get_active_camera();
    auto proj_uniform = program_manager->get(0).get_binding(PROJECTION_MATRIX_LOCATION);
    auto view_uniform = program_manager->get(0).get_binding(VIEW_MATRIX_LOCATION);

    glDrawArrays(GL_TRIANGLES, NULL, 3);
};