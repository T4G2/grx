/**
 * @file base_resource.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>



/**
 * @brief Base Class for all resources
 * 
 */
class BaseResource {

protected:
    bool _empty = false;
    uint32_t _resource_id;
    std::string _path = std::string(); // name == math

public:

    bool is_empty() {
        return _empty;
    }

    uint32_t get_id() {
        return _resource_id;
    }

    const std::string& get_path() {
        return _path;
    }
};
