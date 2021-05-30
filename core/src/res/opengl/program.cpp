/**
 * @file program.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */

#include "program.hpp"

#include "toml.hpp"

Program::Program(std::string filepath, BaseResourceManager<Shader>& shader_manager) {
    try {
        toml::basic_value data = toml::parse(filepath);

        if (!data.is_table()) {
            throw std::exception(" data is not a TABLE");
        }

        auto table = data.as_table();
        if (table.size() != 1) {
            throw std::exception(" data is an EMPTY OR CONTAINS MULTIPLE PROGRAMS");
        }

        auto program = *table.begin();
        _path = program.first;

        if (!program.second.is_array()) {
            throw std::exception(" data.second NOT  AN ARRAY");
        }

        auto array = program.second.as_array();

        if (!array.at(0).is_table()) {
            throw std::exception(" array.at(0) NOT  A TABLE");
        }
        auto table_2 = array.at(0).as_table();

        for (auto i = table_2.begin(); i != table_2.end(); i++) {

            const std::string& name = i->first;

            if (name == "vert" || name == "frag") {
                if (!i->second.is_string()) {
                    throw std::exception(" frag OR vert is not an string");
                }

                std::string path = i->second.as_string();
                if (name == "vert") {
                
                    if (!shader_manager.exists(path)) {
                        shader_manager.load(Shader(GL_VERTEX_SHADER, path));
                    }

                    _vertex_shader = &shader_manager.get_by_name(path);
                } else if (name == "frag") {
                     if (!shader_manager.exists(path)) {
                        shader_manager.load(Shader(GL_FRAGMENT_SHADER, path));
                    }

                    _fragment_shader = &shader_manager.get_by_name(path);
                    
                }

                continue;

            }
            
            if (!i->second.is_integer()) {
                    throw std::exception(" Somme of values is not an integer");
                }

            int n = i->second.as_integer();

            if (name == "VIEW_MATRIX_LOCATION") {
                this->set_binding(VIEW_MATRIX_LOCATION, n);
                
            } else if (name == "MODEL_MATRIX_LOCATION") {
                this->set_binding(MODEL_MATRIX_LOCATION, n);
            } else if (name == "PROJECTION_MATRIX_LOCATION") {
                this->set_binding(PROJECTION_MATRIX_LOCATION, n);
            } else if (name == "MATERIAL_AMBIENT_COLOR_LOCATION") {
                this->set_binding(MATERIAL_AMBIENT_COLOR_LOCATION, n);
            } else if (name == "MATERIAL_DIFFUSE_COLOR_LOCATION") {
                this->set_binding(MATERIAL_DIFFUSE_COLOR_LOCATION, n);
            } else if (name == "MATERIAL_SPECULAR_COLOR_LOCATION") {
                this->set_binding(MATERIAL_SPECULAR_COLOR_LOCATION, n);
            } else if (name == "MATERIAL_SHININESS_LOCATION") {
                this->set_binding(MATERIAL_SHININESS_LOCATION, n);
            } else if (name == "LIGHTS_BINDING") {
                this->set_binding(LIGHTS_BINDING, n);
            } else if (name == "INSTANCED_BINDING") {
                this->set_binding(INSTANCED_BINDING, n);
            } else if (name == "DIFFUSE_TEXTURE_BINDING") {
                this->set_binding(DIFFUSE_TEXTURE_BINDING, n);
            } else if (name == "NORMAL_TEXTURE_BINDING") {
                this->set_binding(NORMAL_TEXTURE_BINDING, n);
            } else if (name == "SPECULAR_TEXTURE_BINDING") {
                this->set_binding(SPECULAR_TEXTURE_BINDING, n);
            } else if (name == "TIME_LOCATION") {
                this->set_binding(TIME_LOCATION, n);
            }
        }

        _gl_id = glCreateProgram();
        _gl_loaded = true;
        glAttachShader(_gl_id, _vertex_shader->get_gl_id());
        glAttachShader(_gl_id, _fragment_shader->get_gl_id());

        glLinkProgram(_gl_id);
    }

     catch (std::exception e) {
         std::cerr << "Program::Program <" << filepath << "> Error: \n";
         std::cerr << e.what() << "\n";
     }
}