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

        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_AMBIENT_COLOR_LOCATION), 1, glm::value_ptr(_ambient_color)); // TODO ambient fro whole scene? 
        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_DIFFUSE_COLOR_LOCATION), 1, glm::value_ptr(_diffuse_color));
        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_SPECULAR_COLOR_LOCATION), 1, glm::value_ptr(_specular_color));
        glProgramUniform1fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_SHININESS_LOCATION), 1, &_shininess);

        if (has_albedo_map()) {
            int binding = gl_program.get_binding(DIFFUSE_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "have no Binding for DIFFUSE MAP";
            } else {
                glBindTextureUnit(binding, _albedo_map_ptr->get_gl_id());
            }
        }

        if (has_normal_map()) {
            int binding = gl_program.get_binding(NORMAL_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "have no Binding for NORMAL MAP";
            } else {
                glBindTextureUnit(binding, _normal_map_ptr->get_gl_id());
            }
        }

        if (has_specular_map()) {
            int binding = gl_program.get_binding(SPECULAR_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "have no Binding for SPECULAR MAP";
            } else {
                glBindTextureUnit(binding, _normal_map_ptr->get_gl_id());
            }
        }
}
