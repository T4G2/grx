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
    std::vector<bool> _occupied;
    std::map<std::string, uint32_t> _path_map; // 

public:

    ~BaseResourceManager() = default;

    void load(T&& t) {

        // maybe iterate and find first empty, or defragment once in a while
        _resources.push_back(t);
         _occupied.push_back(true);
    }

    T* get(uint32_t idx) {
        return _resources[idx];
    }

    T* get_by_name(std::string name) {
        if (_path_map.count(name) == 0) {
            return nullptr;
        }
        return _resources[_path_map[name]];
    }
    virtual void remove(uint32_t idx) {
        //_resources[idx]; //TODO Remove somehow
        //TODO remove name from _path_map
    }

};