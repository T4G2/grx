/**
 * @file abstract_base_manager.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */
#pragma once

#include <map>
#include <vector>
#include <string>

class AbstractManager{
int manager_type;


public:

    ~AbstractManager() = default;


    int getManagerType() {
            return manager_type; 
        }
};