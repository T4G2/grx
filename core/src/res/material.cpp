/**
 * @file material.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 */


#include "material.hpp"
#include "glm/ext.hpp" // value_ptr   ext = external
#include "tiny_obj_loader.h"
#include "mylib.hpp"

Material::Material(std::string path, BaseResourceManager<Texture>* texture_manager) {

    tinyobj::ObjReader reader;
    auto [mtl_file, err] = load_file(path);
    if (err) {
         std::cerr << "Material::Material| file " << path << "do not exist \n";
    }

    if (!reader.ParseFromString("mtllib *", mtl_file )) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error() << "\n";
        }
    }

    if (!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning() << "\n";
    }

    auto& materials = reader.GetMaterials();

    if (materials.empty()) {
         std::cerr << "Material::Material| file " << path << " was loaded with no materials\n";
    }
    auto& material = materials.at(0);

    _ambient_color = glm::vec3( material.ambient[0], material.ambient[1], material.ambient[2]);
    _diffuse_color = glm::vec3( material.diffuse[0], material.diffuse[1], material.diffuse[2]);
    _specular_color = glm::vec3( material.specular[0], material.specular[1], material.specular[2]);
    _shininess = material.shininess;

    // TODO MAP

    if (material.diffuse_texname != ""){
        if (!texture_manager->exists(material.diffuse_texname)) {
            texture_manager->load(Texture(material.diffuse_texname));
        }
        _albedo_map_ptr = &texture_manager->get_by_name(material.diffuse_texname);
    }

    if (material.bump_texname != ""){
        if (!texture_manager->exists(material.bump_texname)) {
            texture_manager->load(Texture(material.bump_texname));
        }
        _normal_map_ptr = &texture_manager->get_by_name(material.bump_texname);
    }


    if (material.specular_texname != ""){
        if (!texture_manager->exists(material.specular_texname)) {
            texture_manager->load(Texture(material.specular_texname));
        }
        _specular_map_ptr = &texture_manager->get_by_name(material.specular_texname);
    }

     if (material.reflection_texname != ""){
        if (!texture_manager->exists(material.reflection_texname)) {
            texture_manager->load(Texture(material.reflection_texname));
        }
        _reflection_map_ptr = &texture_manager->get_by_name(material.reflection_texname);
    }

    

    _path = std::move(path);
}


void Material::gl_prepare(Program& gl_program) {

        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_AMBIENT_COLOR_LOCATION), 1, glm::value_ptr(_ambient_color)); // TODO ambient fro whole scene? 
        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_DIFFUSE_COLOR_LOCATION), 1, glm::value_ptr(_diffuse_color));
        glProgramUniform3fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_SPECULAR_COLOR_LOCATION), 1, glm::value_ptr(_specular_color));
        glProgramUniform1fv(gl_program.get_gl_id(), gl_program.get_binding(MATERIAL_SHININESS_LOCATION), 1, &_shininess);

        if (has_albedo_map()) {
            int binding = gl_program.get_binding(DIFFUSE_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "have no Binding for DIFFUSE MAP\n";
            } else {
                glBindTextureUnit(binding, _albedo_map_ptr->get_gl_id());
            }
        }

        if (has_normal_map()) {
            int binding = gl_program.get_binding(NORMAL_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "> have no Binding for NORMAL MAP\n";
            } else {
                glBindTextureUnit(binding, _normal_map_ptr->get_gl_id());
            }
        }

        if (has_specular_map()) {
            //std::cout << "has specular map!\n";
            int binding = gl_program.get_binding(SPECULAR_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "> have no Binding for SPECULAR MAP\n";
            } else {
                glBindTextureUnit(binding, _specular_map_ptr->get_gl_id());
            }
        }

        if (has_reflection_map()) {
            //std::cout << "has specular map!\n";
            int binding = gl_program.get_binding(METALIC_TEXTURE_BINDING);
            if (binding == -1) {
                std::cerr << "WARNING : Program <" << gl_program.get_path() << "> have no Binding for METALIC/REFLECTION MAP\n";
            } else {
                glBindTextureUnit(binding, _reflection_map_ptr->get_gl_id());
            }
        }
}
