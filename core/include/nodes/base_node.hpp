/**
 * @file base_node.hpp
 * @author your name (you@domain.com)
 * @brief Base Node
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>

#include "node_instance.hpp"


class BaseNode {
public:

    inline static const std::string NODE_NAME = "Base";

    virtual void  init() {
        std::cout << "Not defined Node< <<" << "BaseNode" << ">::init \n";
    }   

    virtual void update(float delta) {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::update \n";
    }
    virtual void draw() {
        std::cout << "Not defined Node< <<" << "BaseNode"  << ">::draw \n";
    }
};

class CameraNode : BaseNode {

public:

    inline static const std::string NODE_NAME = "Camera";
    int look_at = 0;

    void init() override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::init \n";
        look_at = 125;
    }   

    void update(float delta) override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::update \n";
    }
    void draw() override {
        std::cout << "Not defined Node< <<" << "CameraNode" << ">::draw \n";
    }

};

