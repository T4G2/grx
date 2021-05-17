/**
 * @file material.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 */


#include "material.hpp"
#include "glm/ext.hpp" // value_ptr   ext = external

void Material::gl_prepare(Program& gl_program) {
    if (has_ambient_color()) {
        // bind color to uniform
        int binding = gl_program.get_binding(AMBIENT_COLOR_BIND);
        glProgramUniform3fv(gl_program.get_gl_id(), binding, 1, glm::value_ptr(_ambient_color));
    }

    if (has_albedo_color()) {
        // bind color to uniform
        int binding = gl_program.get_binding(DIFFUSE_COLOR_BIND);
        glProgramUniform3fv(gl_program.get_gl_id(), binding, 1, glm::value_ptr(_albedo_color));
    }

    if (has_specular_color()) {
        // bind color to uniform
        int binding = gl_program.get_binding(SPECULAR_COLOR_BIND);
        glProgramUniform3fv(gl_program.get_gl_id(), binding, 1, glm::value_ptr(_specular_color));
        glProgramUniform1fv(gl_program.get_gl_id(), binding, 1, &_shininess);
    }

    // TODO BIND  TEXTURES AS WELL
}
