/**
 * @file gvector.hpp
 * @author your name (you@domain.com)
 * @brief Gap Vector, vector with gaps
 * @version 0.1
 * @date 2021-05-19
 */
#pragma once

#include <vector>

template <class T>
class gvector {
    // invariant: _items.size() == _gaps.size()
    std::vector<T> _items;
    std::vector<bool> _gaps;


public:
    T& get();
    void defragmentize();

    begin();
    end();
    rbegin();
    rend();
    cbegin();
    cend();
    

};
