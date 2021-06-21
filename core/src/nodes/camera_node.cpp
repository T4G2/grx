/**
 * @file camera_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#include "camera_node.hpp"
#include "glm/gtx/transform.hpp"
#include "scene.hpp"
#include "GLFW/glfw3.h"
#include <glm/gtc/type_ptr.hpp>


void CameraNode::init() {
    if (is_active) {
       instance.get_scene()->activeCamera = this;
       if (projection_type == ProjectionType::Perspective) {
            projection_matrix = glm::perspective(fov, static_cast<float>(width) / height, z_close, z_far);
        }
    }
}   

void CameraNode::update(float delta) {
    //add_pos(glm::vec3(0, 0, -1) * delta);

    if (_updated_position) {
        BaseNode::update(delta);
        camera_matrix = local_space_matrix;
    }


}
void CameraNode::draw() {
}

void CameraNode::input(input_struct event) {
BaseNode::input(event); // propagate to children
}


void CameraNode::uniform_projection_matrix(GLuint location) {
    glUniformMatrix4fv(location, 1, 0, glm::value_ptr(projection_matrix));

}
void CameraNode::uniform_view_matrix(GLuint location) {
    glUniformMatrix4fv(location, 1, 0, glm::value_ptr(camera_matrix));
}

void CameraNode::uniform_eye_pos_vec3(GLuint location) {

    auto pos = this->get_global_pos();
    glUniform3f(location, pos.x, pos.y , pos.z );
}



void CameraNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {

    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
};

void CameraNode::init_fov(toml_value data) {
    if (data.is_floating()) {
        fov = static_cast<float>(data.as_floating());
        return;
    }

    if (data.is_integer()) {
        fov = static_cast<float>(data.as_integer());
        return;
    }

    std::cerr << "WARNING, fov in <" << name << "> is not a float or int. example: fov = 90.5\n";
    return;

 }
void CameraNode::init_projection_type(toml_value data) {
    if (!data.is_string()) {
        std::cerr << "WARNING, projection type in <" << name << "> is not a string. example: projection_type = \"perspective\"\n";
        return;
    }

    std::string name = data.as_string();

    if (name == "perspective") {
        projection_type = ProjectionType::Perspective;
        return;
    }

    if (name == "orthogonal") {
        projection_type = ProjectionType::Orthogonal;
        return;
    }
    
    std::cerr << "WARNING, projection type in <" << name << "> is not a valid string. valid strings = {\"perspective\", \"orthogonal\"}\n";
}


void CameraNode::init_auto_size(toml_value data){
    if (!data.is_boolean()) {
        std::cerr << "WARNING, init_auto_size in <" << name << "> is not a boolean. example: init_auto_size = true/false\n";
        return;
    }
    bool is_auto_size = data.as_boolean();
}

void CameraNode::init_active(toml_value data) {
    if (!data.is_boolean()) {
        std::cerr << "WARNING, init_active in <" << name << "> is not a boolean. example: init_auto_size = true/false\n";
        return;
    }
    is_active = true;
}

void CameraNode::init_size(toml_value data) {
    if (! data.is_array()) {
        std::cerr << "WARNING, size in <" << name << "> is not a array. example: size = [1455, 124]\n";
        return;
    }
    auto array = data.as_array();

    if (array.size() != 2) {
        std::cerr << "WARNING, size in <" << name << "> is array but has no size of 2. example: size = [1455, 124]\n";
        return;
    }

    if (!array.at(0).is_integer() || !array.at(0).is_integer()) {
        std::cerr << "WARNING, size in <" << name << "> is array of size 2 , but has no int,int inside. example: size = [1455, 124]\n";
        return;
    }

    width = static_cast<int>(array.at(0).as_integer());
    height = static_cast<int>(array.at(1).as_integer());

}
