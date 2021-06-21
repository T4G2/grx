/**
 * @file skybox_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */

#include "skybox_node.hpp"
#include "scene.hpp"
#include "scene_manager.hpp"
#include "iapplication.hpp"
#include "camera_node.hpp"

void SkyboxNode::init() {
    cubemap = CubemapTexture(right, left, top, bottom, front, back);

    if (!program_ptr) {
        std::cerr << " No prograsm loaded for Skybox <" << name <<">\n";
    }

    if (!cubemap.load()) {
        std::cerr << " ERROR while loading cubemap in <" << name << ">";
    }

    if (active) {
        activate();
    }
    
    glCreateBuffers(1, &_vbo);
    glNamedBufferStorage(_vbo, sizeof(glm::vec3) * sizeof(float) * 9, SkyboxNode::skyboxVertices, 0);
    glCreateVertexArrays(1, &_vao);

    glVertexArrayVertexBuffer(_vao, SkyboxNode::SKYBOX_CUBE_POS_BIND, _vbo, 0, sizeof(glm::vec3));
    glEnableVertexArrayAttrib(_vao, SkyboxNode::SKYBOX_CUBE_POS_BIND);
    glVertexArrayAttribFormat(_vao, SkyboxNode::SKYBOX_CUBE_POS_BIND, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(_vao, SkyboxNode::SKYBOX_CUBE_POS_BIND, SkyboxNode::SKYBOX_CUBE_POS_BIND);
}   

void SkyboxNode::update(float delta) {
}

void SkyboxNode::draw() {
}

void SkyboxNode::input(input_struct event) {

BaseNode::input(event); // propagate to children
}



void SkyboxNode::activate() {
    instance.get_scene()->activeSkybox = this;
}

void SkyboxNode::draw_skybox() {
    GLuint binding = program_ptr->get_binding(CUBEMAP_BINDING);

    GLuint location_projection = program_ptr->get_binding(PROJECTION_MATRIX_LOCATION);
    GLuint location_view = program_ptr->get_binding(VIEW_MATRIX_LOCATION);
    GLuint location_eyepos = program_ptr->get_binding(EYE_POS_LOCATION);
    program_ptr->use();
    instance.get_scene()->get_active_camera()->uniform_projection_matrix(location_projection);
    instance.get_scene()->get_active_camera()->uniform_view_matrix(location_view);
    instance.get_scene()->get_active_camera()->uniform_eye_pos_vec3(location_eyepos);

    //bind_cubemap(binding);
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}


void SkyboxNode::bind_cubemap(GLuint binding) {
    cubemap.bind(binding);
}


void SkyboxNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) { /** Must be in class **/

    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
};

/** init attributes **/

void  SkyboxNode::init_active(toml_value data) {
    if (!data.is_boolean()) {
        std::cerr << "WARNING, active in <" << name << "> is not a bool. example: \n";
        return;
    }

    active = data.as_boolean();
}

void SkyboxNode::init_program(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, program type in <" << name << "> is not a string. example: program = \"PATH\"\n";
        return;
    }
    
    program_ptr = nullptr;
    auto& program_manager = instance.get_scene()->get_scene_manager().app.program_manager;
    if (!program_manager.exists(data.as_string())) {
        std::cerr << "RenderNode::init_custom_toml | there is no Program with name <" << data.as_string() << ">\n";
        return;
    }
    else program_ptr = &program_manager.get_by_name(data.as_string());
}


void SkyboxNode::init_left(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, left in <" << name << "> is not a string. example: \n";
        return;
    }

    left = data.as_string();
    
}
void SkyboxNode::init_right(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, right in <" << name << "> is not a string. example: \n";
        return;
    }

    right = data.as_string();

}
void SkyboxNode::init_top(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, top in <" << name << "> is not a string. example: \n";
        return;
    }
     top = data.as_string();

}
void SkyboxNode::init_bottom(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, bottom in <" << name << "> is not a string. example: \n";
        return;
    }

    bottom = data.as_string();

}
void SkyboxNode::init_front(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, front in <" << name << "> is not a string. example: \n";
        return;
    }

    front = data.as_string();

}
void SkyboxNode::init_back(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, back in <" << name << "> is not a string. example: \n";
        return;
    }

    back = data.as_string();

}
   