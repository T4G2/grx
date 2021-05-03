/**
 * @file resource_manager.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#pragma once

#include <vector>
#include "base_manager.hpp"

class ResourceManager {
    // managers
    std::vector<BaseManager> managers;

    

public:

    ResourceManager() {
    }

    void init() {
        
    }

    void register_manager(BaseManager&& man) {
        managers.push_back(man);
    }

template <typename T, size_t i>
    T get() {
        return dynamic_cast<T>(managers[i]);
    }
};
