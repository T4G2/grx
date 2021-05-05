/**
 * @file resource_manager.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#pragma once

#include <vector>
#include <memory>

#include "abstract_manager.hpp"

// This will be removed

class ManagerIdAssigner {
    // managers
    int next_manager_id = 0;

public:

    int register_manager() {
        return next_manager_id++;
    }
};
