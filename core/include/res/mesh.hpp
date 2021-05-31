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
#include "base_resource_manager.hpp"
#include "material.hpp"

const int POSITION_BUFF = 0;
const int NORMAL_BUFF = 1;
const int UV_BUFF = 2;
const int COLOR_BUFF = 3;
const int BUFF_COUNT = 4;

const int POSITION_BIND = 0;
const int NORMAL_BIND = 1;
const int UV_BIND = 2;
const int COLOR_BIND = 3;


class Mesh : public BaseResource {

  GLuint vbos[BUFF_COUNT];
  GLuint vao;

  std::vector<int> indices;
  std::vector<float> positions;
  std::vector<float> normals;
  std::vector<float> colors;
  std::vector<float> uv_coords;

public:

    int count = 0;
    Mesh(std::string path, BaseResourceManager<Material>& material_manager);


    Mesh(Mesh&&) = default; 
    Mesh(const Mesh&) = delete;

    void bind() { glBindVertexArray(vao); };

  //virtual ~Mesh() = default;
};