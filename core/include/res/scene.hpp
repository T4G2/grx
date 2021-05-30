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
#include <array>

#include "base_resource.hpp"
#include "base_node_instance.hpp"
#include "node_instance.hpp"



#include "camera_node.hpp"
//#include "program.hpp"
//#include "material.hpp"

class SceneManager;
class RenderNode;
class Material;
class Program;


class Scene : public BaseResource {

    using priority_t = int;

    SceneManager& _scene_manager;

    CameraNode* activeCamera = nullptr;
    //std::vector<LightNode*> lights = {};
    // material_program_sorter, // with function, which c  

    long int _root_i = -1;
    std::vector<std::unique_ptr<BaseNodeInstance>> _nodes;

public:
    /**  PRIORITY OF NODE,   PTR_TO_SHADER, PTR_TO_MATERIAL, NODE **/
    //std::map<priority_t,std::map<Program*, std::map<Material*, RenderNode*>>> _render_struct;
    //std::map<int, int> _render_struct;

        /** 10 LEVELS FOR RENDERING **/
    std::vector<std::map<Program*, std::map<Material*, std::vector<RenderNode*>>>> _render_struct;
    Scene(SceneManager& scene_manager): _scene_manager(scene_manager) { _empty = true; _render_struct.resize(10); }
    Scene(SceneManager& scene_manager, std::string name): _scene_manager(scene_manager) {_path = name; _render_struct.resize(10); };

    friend void CameraNode::init();

    void init();
    void input(); // inputs
    void update(float delta);
    void draw();

    void create_root();

    BaseNodeInstance& get_root();
    BaseNodeInstance& get_child(int index){ return *_nodes[index]; }
    CameraNode* get_active_camera() {return activeCamera; };                

    SceneManager& get_scene_manager() {return _scene_manager;};

    BaseNodeInstance* insert_child(std::unique_ptr<BaseNodeInstance>&& node) {
        int index = static_cast<int>(_nodes.size());
        _nodes.push_back(std::move(node));
        return _nodes[index].get();
    }

    void update_scene_pointers() {
        for (auto& node: _nodes) {
            node->update_scene_pointer(this);
        }
    }


    //virtual ~Scene() = default;
};