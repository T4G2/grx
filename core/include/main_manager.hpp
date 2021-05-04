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

class MainManager {
    // managers
    std::vector<std::unique_ptr<AbstractManager>> managers;

public:

    void register_manager(std::unique_ptr<AbstractManager>&& man) {
        managers.push_back(man);
    }

template <typename T>
    T& get(int i ) {
        return dynamic_cast<T*>(managers[i]);
    }
};
