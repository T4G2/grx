/**
 * @file base_node.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 */

#include "base_node.hpp"
#include "glm/gtx/transform.hpp"



    void  BaseNode::init() {
        update_matrix_if_needed();
    }   

    void BaseNode::update_matrix_if_needed() {
        if (_updated_position) {
            BaseNodeInstance* parent = instance.get_parent();
            if (parent  == nullptr) {
                // do it by myself
                local_space_matrix = glm::mat4(1.0f); // construct identity matrix

            } else {
                local_space_matrix = parent->get_data()->local_space_matrix;
            }


            //scale
                //rotate
                // move
                
                local_space_matrix = glm::scale(local_space_matrix, scl);

                
                rotation_matrix = glm::rotate(rot.x, glm::vec3(1, 0, 0));
                rotation_matrix *= glm::rotate(rot.y, glm::vec3(0, 1, 0));
                rotation_matrix *= glm::rotate(rot.z, glm::vec3(0, 0, 1));
                local_space_matrix = rotation_matrix * local_space_matrix;

                local_space_matrix = glm::translate(local_space_matrix, pos);

        }

        _updated_position = false;
    }

    void BaseNode::input(input_struct event) {
        for (auto child : instance.get_children()) {
            child->get_data()->input(event);
        }
    }

    void BaseNode::update(float delta) {
        update_matrix_if_needed();
    }
    void BaseNode::draw() {
    }

    void BaseNode::init_custom_toml(BaseNodeInstance::toml_properties_t props) {

        for (auto& [name, obj] : props) {
            //std::cout << "\t" << name << "\n";
            if (prop_func.contains(name)) {
                (this->*prop_func.at(name))(obj);
            }
        }
    };

    void BaseNode::init_pos( toml_value value) {
        if (!value.is_array()) {
            std::cerr << "WARNING, pos in <" << name << "> is not array. example: pos = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, pos in <" << name << "> is not array of size 3. example: pos = [0.0, 0.0, 0.0]\n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, pos in <" << name << "> is not array of float numbers. example: pos = [0.0, 0.0, 0.0] \n";
                return;
        }

        pos.x = static_cast<float>(array.at(0).as_floating());
        pos.y = static_cast<float>(array.at(1).as_floating());
        pos.z = static_cast<float>(array.at(2).as_floating()); 

   }
   void BaseNode::init_rot( toml_value value) {
        if (!value.is_array()) {
            std::cerr << "WARNING, rot in <" << name << "> is not array. example: rot = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, rot in <" << name << "> is not array of size 3. example: rot = [0.0, 0.0, 0.0]\n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, rot in <" << name << "> is not array of float numbers. example: rot = [0.0, 0.0, 0.0] \n";
                return;
        }

        rot.x = static_cast<float>(array.at(0).as_floating());
        rot.y = static_cast<float>(array.at(1).as_floating());
        rot.z = static_cast<float>(array.at(2).as_floating()); 
   }
   void BaseNode::init_scl( toml_value value) {
       if (!value.is_array()) {
            std::cerr << "WARNING, scl in <" << name << "> is not array.  example: scl = [0.0, 0.0, 0.0]\n";
            return;
        }
        auto array = value.as_array();
        if (array.size() != 3) {
            std::cerr << "WARNING, scl in <" << name << "> is not array of size 3. example: scl = [0.0, 0.0, 0.0] \n";
            return;
        }

        if (!array.at(0).is_floating()
            || !array.at(1).is_floating() 
            || !array.at(2).is_floating()) {
                std::cerr << "WARNING, scl in <" << name << "> is not array of float numbers. example: scl = [1.0, 1.0, 1.0] \n";
                return;
        }

        scl.x = static_cast<float>(array.at(0).as_floating());
        scl.y = static_cast<float>(array.at(1).as_floating());
        scl.z = static_cast<float>(array.at(2).as_floating()); 
   }



 void BaseNode::set_pos(glm::vec3 new_pos) {
    pos = new_pos;
    update_matrix();
 }
void BaseNode::set_rot(glm::vec3 new_rot) {
    rot = new_rot;
    update_matrix();
}
void BaseNode::set_scl(glm::vec3 new_scl) {
    scl = new_scl;
    update_matrix();
}

void BaseNode::add_pos(glm::vec3 new_pos) {
    pos += new_pos;
    update_matrix();
}
void BaseNode::add_rot(glm::vec3 new_rot) {
    rot += new_rot;
    update_matrix();
}
void BaseNode::mul_scl(glm::vec3 new_scl) {
    scl *= new_scl;
    update_matrix();
}


void BaseNode::update_matrix() {
    _updated_position = true;
    for (auto child :  this->instance.get_children()) {
        child->get_data()->update_matrix();
    }
}