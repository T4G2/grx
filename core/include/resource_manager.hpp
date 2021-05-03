/**
 * @file resource_manager.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */

#pragma once


class ResourceManager {
    // managers
    int data = -1;
public:

    ResourceManager() {
        data = 0;
    }

    void init() {
        
    }

    void setData(int d) {
        data = d;
    }

    int getData() {
        return data;
    }
};
