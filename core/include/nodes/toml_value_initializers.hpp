/**
 * @file toml_value_initializers.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 */
#pragma once
#include "glm/glm.hpp"
#include "base_node.hpp"

glm::vec3 init_vec3( toml_value& data, const std::string& attr_name, const std::string& name) {
    if (!data.is_array()) {
            std::cerr << "WARNING, " << attr_name <<"  in <" << name << "> is not array. example: "<< attr_name <<" = [0.0, 0.0, 0.0]\n";
            return glm::vec3(0);
        }
        auto array = data.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, " << attr_name <<"  in <" << name << "> is not array of size 3. example: "<< attr_name <<" = [0.0, 0.0, 0.0]\n";
            return glm::vec3(0);
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, " << attr_name <<"  in <" << name << "> is not array of float numbers. example: "<< attr_name <<" = [0.0, 0.0, 0.0] \n";
                return glm::vec3(0);
        }
        glm::vec3 val = {};

        val.x = static_cast<float>(array.at(0).as_floating());
        val.y = static_cast<float>(array.at(1).as_floating());
        val.z = static_cast<float>(array.at(2).as_floating()); 

        return val;
}

float init_float( toml_value& data, const std::string& attr_name, const std::string& name) {
    if (data.is_floating()) {
        return static_cast<float>(data.as_floating());
        
    }

    if (data.is_integer()) {
        return static_cast<float>(data.as_integer());

    }

    std::cerr << "WARNING, "<< attr_name <<" in <" << name << "> is not a float or int. example: " << attr_name <<" = 90.5\n";
    return 0.0f;
}


bool init_bool( toml_value& data, const std::string& attr_name, const std::string& name) {
    if (!data.is_boolean()) {
        std::cerr << "WARNING, "<< attr_name <<" in <" << name << "> is not a boolean. example: " << attr_name <<" = true\n";
        return false;
    }
    return static_cast<bool>(data.as_boolean());
}