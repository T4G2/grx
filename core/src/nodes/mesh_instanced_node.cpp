/**
 * @file mesh_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 */

#include "mesh_instanced_node.hpp"
#include "scene_manager.hpp"
#include "iapplication.hpp"

#include "toml_value_initializers.hpp"

void MeshInstancedNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {


    RenderNode::init_custom_toml(props);

    for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }


}

void MeshInstancedNode::init_mesh(toml_value value) {
    if (!value.is_string()) {
        std::cerr << "WARNING, mesh in <" << name << "> is not a string. example: mesh = \"PATH\"\n";
        return;
    }

    std::string path = value.as_string();

    auto& material_manager = instance.get_scene()->get_scene_manager().app.material_manager;
    auto& mesh_manager = instance.get_scene()->get_scene_manager().app.mesh_manager;
    
    if (!mesh_manager.exists(path)) {
        mesh_manager.load(Mesh(path, material_manager, normal_mapped));
    }
    mesh_ptr = &mesh_manager.get_by_name(path);

}
void MeshInstancedNode::init_material(toml_value value) {
     if (!value.is_string()) {
        std::cerr << "WARNING, material in <" << name << "> is not a string. example: material = \"PATH\"\n";
        return;
    }
    std::string path = value.as_string();

    auto& material_manager = instance.get_scene()->get_scene_manager().app.material_manager;
    
    if (!material_manager.exists(path)) {
        material_manager.load(Material(path, &instance.get_scene()->get_scene_manager().app.texture_manager));
    }
    material_ptr = &material_manager.get_by_name(path);

}


void MeshInstancedNode::init_normal(toml_value value) {
     if (!value.is_boolean()) {
        std::cerr << "WARNING, normal in <" << name << "> is not a bool. example: normal = true\n";
        return;
    }
   normal_mapped = value.as_boolean();
}


void MeshInstancedNode::init_generator(toml_value value) {
    auto generator_name = init_string(value, "generator", name);
    this->generator = instance.get_scene()->get_scene_manager().app.generator_map[generator_name].get();
}

void MeshInstancedNode::init_count(toml_value value) {
    count = init_int(value, "count", name);
}