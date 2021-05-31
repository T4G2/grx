/**
 * @file light_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 */


#include "base_node.hpp"
#include "glm/glm.hpp"

class LightNode: public BaseNode {

    std::map<std::string, init_prop<LightNode>> prop_func = 
    {
        {"ambient",&LightNode::init_ambient_color},
        {"diffuse",&LightNode::init_diffuse_color},
        {"specular",&LightNode::init_specular_color},
        {"intensity",&LightNode::init_intensity},
        {"angle",&LightNode::init_angle},
        {"directional",&LightNode::init_directional},
        {"active",&LightNode::init_active},
    };

protected:

    glm::vec3 ambient_color = {0, 0, 0};
    glm::vec3 diffuse_color = {1, 1, 1};
    glm::vec3 specular_color = {1, 1, 1};
    float intensity = 1.0f;
    float angle = 0.0f;
    bool directional = false;
    bool active = true;

    int position_in_ssbo = -1;

public:

    inline static const std::string NODE_NAME = "Light";

    LightNode(std::string name_a, BaseNodeInstance& instance):BaseNode(name_a, instance) {};

    void init();
    
void update(float delta) override {
    if ( _updated_position) {
        BaseNode::update(delta);
        update_ssao();

    }
};

    void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

    void init_ambient_color(toml_value data);
    void init_diffuse_color(toml_value data);
    void init_specular_color(toml_value data);
    void init_intensity(toml_value data);
    void init_angle(toml_value data);
    void init_directional(toml_value data);
    void init_active(toml_value data);

    virtual ~LightNode() = default;
    
    void update_ssao();

    void activate();
    void deactivate();
};