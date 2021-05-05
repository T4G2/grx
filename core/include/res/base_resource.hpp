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
    uint32_t resource_id;
    std::string path; // name == math

public:
    uint32_t get_id() {
        return resource_id;
    }

    const std::string& get_path() {
        return path;
    }
};
