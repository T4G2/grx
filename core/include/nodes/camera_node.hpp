/**
 * @file camera_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#include "base_node.hpp"


enum ProjectionType {
    Perspective = 0,
    Orthogonal
};


class CameraNode : BaseNode {

    std::map<std::string, init_prop<CameraNode>> prop_func = 
    {
        {"fov", &CameraNode::init_fov},
        {"projection_type", &CameraNode::init_projection_type},
        {"auto_size", &CameraNode::init_auto_size},
        {"size", &CameraNode::init_size}
    };

public:

    CameraNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = "Camera";

    bool is_auto_size = true;
    float fov = 90;
    ProjectionType projection_type = ProjectionType::Perspective;
    int width = 1080;
    int height = 720;

    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;

    void init_fov(toml_value);
    void init_projection_type(toml_value);
    void init_auto_size(toml_value);
    void init_size(toml_value);



   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~CameraNode()= default;

};