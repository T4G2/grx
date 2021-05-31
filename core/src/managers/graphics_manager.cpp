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
#include "material.hpp"
#include "render_node.hpp"



void GraphicsManager::draw() {

    glBindVertexArray(0);
    glViewport(0, 0, app->width, app->height);
    //program_manager->get(0).use();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    CameraNode* active_camera = scene_manager->get_active_scene()->get_active_camera();
    auto proj_uniform_location = program_manager->get(0).get_binding(PROJECTION_MATRIX_LOCATION);
    auto view_uniform_location = program_manager->get(0).get_binding(VIEW_MATRIX_LOCATION);

    auto time_uniform_location = program_manager->get(0).get_binding(TIME_LOCATION);

    glEnable(GL_DEPTH_TEST);  

    for (auto& [ program, material_map] : scene_manager->get_active_scene()->_render_struct[0]) {
        // bind program
        if (program == nullptr) {
            std::cerr << "GraphicsManager::draw()| ERROR Some object do not have Program Defined!\n";
        }

        program->use();

        if (time_uniform_location != -1 ) {
        glUniform1f(time_uniform_location, glfwGetTime());
        }

        glUniformMatrix4fv(proj_uniform_location, 1, 0, glm::value_ptr(active_camera->projection_matrix));
        glUniformMatrix4fv(view_uniform_location, 1, 0, glm::value_ptr(active_camera->camera_matrix));

        for (auto& [ material, nodes]: material_map) {
            if (!material) {
                //std::cerr << "GraphicsManager::draw()| WARNING Some object do not have material!\n";
            } else {
                material->gl_prepare(*program);
            }
            
            for (auto& node : nodes) {
                node->upload_to_program(*program);
                node->draw();
            }
        }
    }
};