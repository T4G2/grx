/**
 * @file mesh_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */
#pragma once
#include "render_node.hpp"

#include "mesh.hpp"


class MeshNode: public RenderNode {
    std::map<std::string, init_prop<MeshNode>> prop_func = 
    {
       {"mesh", &MeshNode::init_mesh}, // mesh
       {"material", &MeshNode::init_material}, // mesh //material
       {"normal", &MeshNode::init_normal} // mesh //material
    };

public:
    inline static const std::string NODE_NAME = "Mesh";


    Mesh* mesh_ptr;
    bool normal_mapped = false;
 

    MeshNode(std::string name_a, BaseNodeInstance& instance):RenderNode(name_a, instance) {};

    void init() override {
        //instance.get_scene()->*_render_struct[priority][program_ptr]
        RenderNode::init();
    }

    void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

    void init_mesh(toml_value value);
    void init_material(toml_value value);
    void init_normal(toml_value value);

    virtual void draw() override {
        if (mesh_ptr) {
            mesh_ptr->bind();
            glDrawArrays(GL_TRIANGLES, 0, mesh_ptr->count);
        }

    }
};
