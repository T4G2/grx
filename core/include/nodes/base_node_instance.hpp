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




class BaseNodeInstance{
    // pos
    // X

    // INTO HEAP
    std::vector<std::unique_ptr<BaseNodeInstance>> _children;
    BaseNodeInstance* _parent = nullptr;


public:
    virtual void init() = 0;
    virtual void update(float delta) = 0;
    virtual void draw() = 0;

};