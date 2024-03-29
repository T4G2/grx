/**
 * @file camera_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#pragma once

#include "base_node.hpp"
#include "glad.h"



inline const glm::vec3 X_AXIS = {1.0 , 0.0 , 0.0};
inline const glm::vec3 Y_AXIS = {1.0 , 0.0 , 0.0};
inline const glm::vec3 Z_AXIS = {1.0 , 0.0 , 0.0};


enum ProjectionType {
    Perspective = 0,
    Orthogonal
};


class CameraNode : public BaseNode {

    std::map<std::string, init_prop<CameraNode>> prop_func = 
    {
        {"fov", &CameraNode::init_fov},
        {"projection_type", &CameraNode::init_projection_type},
        {"auto_size", &CameraNode::init_auto_size},
        {"size", &CameraNode::init_size},
        {"active_camera", &CameraNode::init_active}
    };

public:

    CameraNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = "Camera";

    bool is_auto_size = true;
    float fov = 90;
    ProjectionType projection_type = ProjectionType::Perspective;
    int width = 1080;
    int height = 720;
    bool is_active = false;

    float z_close = 0.01f;
    float z_far = 3000.0f;


    glm::mat4 camera_matrix = glm::mat4(1);
    glm::mat4 projection_matrix = glm::mat4(1);
    //glm::mat4 view_matrix = glm::mat4 

    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;
    virtual void input(input_struct event) override;

    void init_fov(toml_value);
    void init_projection_type(toml_value);
    void init_auto_size(toml_value);
    void init_size(toml_value);
    void init_active(toml_value);


    void uniform_projection_matrix(GLuint location);
    void uniform_view_matrix(GLuint location);
    void uniform_eye_pos_vec3(GLuint location);


   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~CameraNode()= default;

};