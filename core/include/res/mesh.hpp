/**
 * @file mesh.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief 
 * @version 0.1
 * @date 2021-05-01
  */
#pragma once

#include <string>

#include "base_resource.hpp"




 class Mesh : public BaseResource {


public:
    Mesh(std::string path);


    Mesh(Mesh&&) = default; 
    Mesh(const Mesh&) = delete;

  //virtual ~Mesh() = default;
};