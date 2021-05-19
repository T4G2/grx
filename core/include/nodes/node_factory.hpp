/**
 * @file node_factory.hpp
 * @author your name (you@domain.com)
 * @brief Node Factory will be used to Register New Typew of Nodes
 * @version 0.1
 * @date 2021-05-19
 */
#pragma once

#include <memory>
#include "node_instance.hpp"

class BaseNodeFactory {
public:
    virtual std::unique_ptr<BaseNodeInstance>  get_pointer_to_new_instance(BaseNodeInstance* parent, Scene& scene)
    {
        std::cerr<< "BaseNodeFactory::get_pointer_to_new_instance| Can't create New Instance from <BaseNodeFactory>\n";
        throw std::exception("BaseNodeFactory::get_pointer_to_new_instance| Can't create New Instance from <BaseNodeFactory>");
        return nullptr;
    };
    virtual std::string  get_name(){return "BASENODEFACTORY";};
};


template <class T>
class NodeFactory : public BaseNodeFactory {

public:
    std::unique_ptr<BaseNodeInstance>  get_pointer_to_new_instance(BaseNodeInstance* parent, Scene& scene) override {
        auto to_ret = std::unique_ptr<NodeInstance<T>>(new NodeInstance<T>(scene, parent));
        return to_ret;
    }


    std::string  get_name() override {
        return T::NODE_NAME;
    };

};
