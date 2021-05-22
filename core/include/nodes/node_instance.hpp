/**
 * @file base_node_instance.hpp
 * @author your name (you@domain.com)
 * @brief Base Node Instance
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include "base_node.hpp"
#include "base_node_instance.hpp"



template<class R>
class NodeInstance : public BaseNodeInstance {
    R data; // TODO do this a pointer

    // TODO should i use map  (name referencing)??? 

public:

    NodeInstance(Scene& scene, BaseNodeInstance* parent,std::string name): BaseNodeInstance(scene, parent), data(name) { } ;

    R& get_data_ref() {
        return data;
    }
    void init() override {
        data.init();
    }

    void update(float delta) override  {
         data.update( delta);
    }

    void draw() override  {
         data.draw();
    }

    void init_custom_toml(toml_properties_t prop) override {
        data.init_custom_toml(prop);
    }

};