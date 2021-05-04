/**
 * @file base_manager.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */


#include <map>
#include <vector>
#include <memory>

#include "abstract_manager.hpp"

template <class T>
class BaseResourceManager: public AbstractManager{

     // path = name
    std::vector<T> _resources;
    std::map<std::string, uint32_t> _path_map; // 

public:

    ~BaseResourceManager() = default;

    vvoid load(std::string path) {
        _resources.push_back(T::load_from_file(path));
    }
    T* get(uint32_t idx) = 0 {
        return resources[idx];
    }
    T* get_by_name(std::string name) {
        if (_path_map.count(name) == 0) {
            return nullptr;
        }
        return _resources[_path_map[name]];
    }
    virtual void remove(uint32_t idx) {
        _resources[idx = T::empty()];
        //TODO remove name from _path_map
    }

};