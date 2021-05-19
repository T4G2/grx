/**
 * @file scene.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Scene Class
 * @version 0.1
 * @date 2021-05-01
 */
#pragma once

#include <memory>
#include <string>
#include <map>

#include "base_resource.hpp"
#include "base_node.hpp"
#include "base_node_instance.hpp"
#include "node_instance.hpp"


class Scene : public BaseResource {

    using priority_t = int;
    using material_t = int;



    //NodeInstance<Camera>* activeCamera = nullptr;
    int _root_i = -1;
    std::vector<BaseNodeInstance> _nodes;

    
    //std::map<priority_t, std::vector<material_t, std::vector<BaseNodeInstance*>>> _render_tree;

public:


    Scene(){ _empty = true; }
    Scene(std::string name){_path = name;};

    void input(); // inputs
    void update(float delta);
    void draw();

    void create_root();

    BaseNodeInstance& get_root();
    BaseNodeInstance& get_child(int index){ return _nodes[index]; }



};