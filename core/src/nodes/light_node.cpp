/**
 * @file light_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 */
#include "light_node.hpp"
#include "toml_value_initializers.hpp"
#include "scene.hpp"


void LightNode::init() {
        BaseNode::init();
        //instance.get_scene()->_lights.push_back(this);
        Scene* scene = instance.get_scene();

    
        Light_SSBO ssbo;

        if (directional) {
            ssbo.position = glm::vec4(get_pos(), 0.0f );
        } else {
            ssbo.position = glm::vec4(get_global_pos(), 1.0f) ;
        
        }
        ssbo.ambient_color = glm::vec4(ambient_color, 1.0f);
        ssbo.diffuse_color = glm::vec4(diffuse_color, 1.0f);
        ssbo.specular_color = glm::vec4(specular_color, 1.0f);
        ssbo.intensity = intensity;
        ssbo.angle = angle;
        
        if (!active) {
            ssbo.intensity = 0.0f;
        }
    

        instance.get_scene()->add_light(ssbo);
        position_in_ssbo = instance.get_scene()->lights_ssbo.size() - 1;
    }


void LightNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {
    BaseNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }

}

void LightNode::init_ambient_color(toml_value data) {
    ambient_color = init_vec3(data, "ambient", name);

}
void LightNode::init_diffuse_color(toml_value data) {
    diffuse_color = init_vec3(data, "ambient", name);
}
void LightNode::init_specular_color(toml_value data) {
    specular_color = init_vec3(data, "ambient", name);
}
void LightNode::init_intensity(toml_value data) {
    intensity = init_float(data, "intensity", name);

}
void LightNode::init_angle(toml_value data) {
    intensity = init_float(data, "angle", name);
}
void LightNode::init_directional(toml_value data) {
    directional = init_bool(data, "directional", name);
}
void LightNode::init_active(toml_value data) {
    active = init_bool(data, "active", name);
}


void LightNode::update_ssao() {
    if (!active) {
        return;
    }
    
    if (position_in_ssbo == -1) {
        std::cerr << "Light position is not in SSBO!\n";
        return; 
    }

    Scene* scene = instance.get_scene();

    Light_SSBO* ssbo = &scene->lights_ssbo[position_in_ssbo];

    

    ssbo->position = directional ? glm::vec4(get_pos(), 0 ): glm::vec4(get_global_pos(), 1) ;
    ssbo->ambient_color = glm::vec4(ambient_color, 1.0f);
    ssbo->diffuse_color = glm::vec4(diffuse_color, 1.0f);
    ssbo->specular_color = glm::vec4(specular_color, 1.0f);
    ssbo->intensity = intensity;
    ssbo->angle = angle;
    
    if (!active) {
        ssbo->intensity = 0.0f;
    }

    glNamedBufferSubData(scene->_lights_buffer, position_in_ssbo * sizeof(Light_SSBO), sizeof (Light_SSBO), ssbo);  
}

void LightNode::activate() {
    active = true;
    update_ssao();
}

void LightNode::deactivate() {
    active = false;
    update_ssao();
}