/**
 * @file mesh_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */
#pragma once
#include <vector>

#include "render_node.hpp"

#include "mesh.hpp"
#include "object_ssbo.hpp"
#include "instanced_generator_base.hpp"



class MeshInstancedNode: public RenderNode {
    std::map<std::string, init_prop<MeshInstancedNode>> prop_func = 
    {
       {"mesh", &MeshInstancedNode::init_mesh}, // mesh
       {"material", &MeshInstancedNode::init_material}, // mesh //material
       {"normal", &MeshInstancedNode::init_normal}, // mesh //material
       {"generator", &MeshInstancedNode::init_generator}, // mesh //material
       {"count", &MeshInstancedNode::init_count} // mesh //material
    };

public:
    inline static const std::string NODE_NAME = "MeshInstanced";


    Mesh* mesh_ptr;
    
    bool normal_mapped = false;
    std::vector<Object_SSBO> object_ssbo;
    std::vector<Object_SSBO> object_ssbo_world_space;
    GLuint object_buffer;
    InstancedGeneratorBase* generator = nullptr;
    int count;
 

    MeshInstancedNode(std::string name_a, BaseNodeInstance& instance):RenderNode(name_a, instance) {};

    void init() override {
        RenderNode::init(); // firstly i want to update world matrix -> renderNode -> baseNode

        //glCreateBuffers(1, &_lights_buffer);

        if (!generator ) {
            std::cout << "generator for <" << name << "> is nullptr\n";
        }

        object_ssbo = generator->generate(count, this);
        object_ssbo_world_space = object_ssbo;
        update_ssbo_to_world();
        glCreateBuffers(1, &object_buffer);
        glNamedBufferStorage(object_buffer, sizeof(Object_SSBO) * object_ssbo_world_space.size(), object_ssbo_world_space.data(), GL_DYNAMIC_STORAGE_BIT);
    }


    void update(float delta) override {
        bool updated_position =  _updated_position;
        RenderNode::update(delta);
        update_ssbo_to_world();
    }

    void update_ssbo_to_world() {
        for ( unsigned int i = 0; i < object_ssbo.size(); i++) {
            object_ssbo_world_space[i].model_matrix = local_space_matrix * object_ssbo[i].model_matrix;
        }
    }

    void update_ssbo() {
        glNamedBufferSubData(object_buffer,0 , sizeof (Light_SSBO) * object_ssbo_world_space.size(), object_ssbo_world_space.data());  

    }

    void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

    void init_mesh(toml_value value);
    void init_material(toml_value value);
    void init_normal(toml_value value);
    void init_generator(toml_value value);
    void init_count(toml_value value);

    virtual void draw() override {
        if (mesh_ptr) {
            mesh_ptr->bind();
            if (program_ptr->get_binding(INSTANCED_BINDING) == -1) {
                std::cout << "program in <" << name << "do not support Instancing\n";
                return;
            }

            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, program_ptr->get_binding(INSTANCED_BINDING) ,object_buffer);
            glDrawArraysInstanced(GL_TRIANGLES, 0, mesh_ptr->count, object_ssbo.size());
        }

    }

    virtual ~MeshInstancedNode() = default;
};
