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
    R data; 

public:

    NodeInstance(Scene* scene, BaseNodeInstance* parent,std::string name): BaseNodeInstance(scene, parent), data(name, *this) { } ;

    R& get_data_ref() {
        return data;
    }
    void init() override {
        data.init();
        init_children();
    }

    void update(float delta) override {
        data.update( delta);
        update_children(delta);
    }

    void draw() override  {
         data.draw();
    }

    void init_custom_toml(toml_properties_t prop) override {
        data.init_custom_toml(prop);
    }

    BaseNode* get_data() override { return dynamic_cast<BaseNode*>(&data);};

};