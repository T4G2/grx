/**
 * @file camera_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */
#include "base_node.hpp"


class CameraNode : BaseNode {

    std::map<std::string, void (CameraNode::*)(BaseNodeInstance::toml_properties_t)> prop_func;

public:

    CameraNode(std::string name_a): BaseNode(name_a) {};

    inline static const std::string NODE_NAME = "Camera";
    int look_at = 0;

    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;




   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~CameraNode()= default;

};