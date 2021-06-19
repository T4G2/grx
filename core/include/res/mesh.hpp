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
const int TANGENT_BUFF = 4;
const int BUFF_COUNT = 5;

const int POSITION_BIND = 0;
const int NORMAL_BIND = 1;
const int UV_BIND = 2;
const int COLOR_BIND = 3;
const int TANGENT_BIND = 4;





class Mesh : public BaseResource {

  GLuint vbos[BUFF_COUNT];
  GLuint vao;

  std::vector<int> indices;
  std::vector<glm::vec3> positions;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec3> colors;
  std::vector<glm::vec2> uv_coords;

   bool normal_mapped = false;

  std::vector<glm::vec3> tangents;

public:

    int count = 0;
    Mesh(std::string path ,BaseResourceManager<Material>& material_manager, bool normal_mapping = false);


    Mesh(Mesh&&) = default; 
    Mesh(const Mesh&) = delete;

    void bind() { glBindVertexArray(vao); };

  //virtual ~Mesh() = default;
};