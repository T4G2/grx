/**
 * @file base_manager.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-03
 */


#include <map>
#include <vector>

template<class T>
class BaseManager{

    // path = name
    std::vector<T> _resources;
    std::map<std::string, uint32_t> _path_map; // 

public:
    void load(std::string path) {
         // load from file and call T with name
         _path_map.insert();
    }

    T& get(uint32_t idx) {
        return _resources[idx];
    }

    T& get_by_name(std::string name) {
        return _resources[_path_map[name]];
    }

     void delete(uint32_t idx) {
         std::string name = resources[idx].get_name();
        _resources[idx] = null_ptr;
        
        _path_map[name] = nullptr; // ERASE ??
    }


};