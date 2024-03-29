/**
 * @file base_node_instance.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-13
 */
#pragma once
#include <vector>
#include <string>
#include <memory>


#include "toml.hpp"

//#include "scene.hpp"

class Scene;
class BaseNode;

class BaseNodeInstance {

    std::vector<BaseNodeInstance*> _children_i;
    BaseNodeInstance* _parent = nullptr;
    Scene* _scene;

public:

    using toml_properties_t = std::vector<std::pair<std::string, toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector>>>;  

    BaseNodeInstance(Scene* scene, BaseNodeInstance* parent): _scene(scene),  _parent(parent) { };

    virtual void setup_by_toml(toml::basic_value<struct toml::discard_comments, std::unordered_map, std::vector>);

    virtual void init(){};
    virtual void update(float delta); //defined in .cpp
    virtual void draw(){};
    virtual void init_custom_toml(toml_properties_t);
    

    void update_scene_pointer(Scene* scene) {
        _scene = scene;
    }

    virtual BaseNode* get_data() {return nullptr;};
    void insert_child(BaseNodeInstance* instance) {_children_i.push_back(instance);};
    BaseNodeInstance* get_parent() {return _parent; };
    std::vector<BaseNodeInstance*>& get_children() {return _children_i;};
    Scene* get_scene() {return _scene;}

    void update_children(float delta) {
        for (auto child :_children_i) {
            child->update(delta);
        }
    }

    void init_children() {
        for (auto child :_children_i) {
            child->init();
        }
    }

    virtual ~BaseNodeInstance() = default;
};
