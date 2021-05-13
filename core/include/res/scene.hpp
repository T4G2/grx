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

#include "base_resource.hpp"
#include "base_node.hpp"
#include "node_instance.hpp"


class Scene : BaseResource {

    NodeInstance<Camera>* activeCamera = nullptr;
    std::unique_ptr<BaseNodeInstance> _root = nullptr;


public:
    Scene load_from_file(std::string filepath);

};