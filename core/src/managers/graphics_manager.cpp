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
#include <glm/gtc/type_ptr.hpp>

#include "graphics_manager.hpp"
#include "iapplication.hpp"




void GraphicsManager::draw() {

    glBindVertexArray(0);
    glViewport(0, 0, app->width, app->height);
    program_manager->get(0).use();
    glClear(GL_COLOR_BUFFER_BIT);
    CameraNode* active_camera = scene_manager->get_active_scene()->get_active_camera();
    auto proj_uniform_location = program_manager->get(0).get_binding(PROJECTION_MATRIX_LOCATION);
    auto view_uniform_location = program_manager->get(0).get_binding(VIEW_MATRIX_LOCATION);

    auto time_uniform_location = program_manager->get(0).get_binding(TIME_LOCATION);

    if (time_uniform_location != -1 ) {
        glUniform1f(time_uniform_location, glfwGetTime());
    }

    glUniformMatrix4fv(proj_uniform_location, 1, 0, glm::value_ptr(active_camera->projection_matrix));
    glUniformMatrix4fv(view_uniform_location, 1, 0, glm::value_ptr(active_camera->camera_matrix));

    glDrawArrays(GL_TRIANGLES, NULL, 3);
};