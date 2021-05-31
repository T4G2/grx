/**
 * @file mesh.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-09
 */

#include <iostream>

#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include "tiny_obj_loader.h"

#include "mesh.hpp"



Mesh::Mesh(std::string path, BaseResourceManager<Material>& material_manager) {
    _path = std::move(path);

    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = "./res/materials"; // Path to material files
    reader_config.triangulate = true;
    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(_path, reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error() << "\n";
        }
    }

    if (!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning() << "\n";
    }

    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();
    auto& materials = reader.GetMaterials();

    if (shapes.size() == 0) {
        std::cout << "No shape in .obj file <"  << _path <<">  \n";
        return;
    }

    if (shapes.size() > 1) {
        std::cout << "More than 1 shape in .obj file <"  << _path <<"> (Not implemented yet) \n";
        return;
    }

    auto& shape = shapes.at(0);
    auto& mesh = shape.mesh;


    glCreateBuffers(BUFF_COUNT, vbos);
    //glNamedBufferStorage(buffers[POSITION_BUFF], )

    for( auto& indice : mesh.indices) {
        count++;
        int vertex_pos =  3*indice.vertex_index;
        int texcoord_pos =  2*indice.texcoord_index;
        int normal_pos =  3*indice.normal_index;
        positions.push_back(attrib.vertices[vertex_pos]);
        positions.push_back(attrib.vertices[vertex_pos+1]);
        positions.push_back(attrib.vertices[vertex_pos+2]);
        colors.push_back(attrib.colors[vertex_pos]);
        colors.push_back(attrib.colors[vertex_pos+1]);
        colors.push_back(attrib.colors[vertex_pos+2]);
        uv_coords.push_back(attrib.texcoords[texcoord_pos]);
        uv_coords.push_back(attrib.texcoords[texcoord_pos+1]);
        normals.push_back(attrib.normals[normal_pos]);
        normals.push_back(attrib.normals[normal_pos+1]);
        normals.push_back(attrib.normals[normal_pos+2]);
    }

    glNamedBufferStorage(vbos[POSITION_BUFF], sizeof(float) * positions.size(), positions.data(), 0);
    glNamedBufferStorage(vbos[NORMAL_BUFF], sizeof(float) * normals.size(), normals.data(), 0);
    glNamedBufferStorage(vbos[COLOR_BUFF], sizeof(float) * colors.size(), colors.data(), 0);
    glNamedBufferStorage(vbos[UV_BUFF], sizeof(float) * uv_coords.size(), uv_coords.data(), 0);

    glCreateVertexArrays(1, &vao);
    glVertexArrayVertexBuffer(vao, POSITION_BIND, vbos[POSITION_BUFF], 0, 3 * sizeof(float));
    glVertexArrayVertexBuffer(vao, NORMAL_BIND, vbos[NORMAL_BUFF], 0, 3 * sizeof(float));
    glVertexArrayVertexBuffer(vao, UV_BIND, vbos[UV_BUFF], 0, 2 * sizeof(float));
    glVertexArrayVertexBuffer(vao, COLOR_BIND, vbos[COLOR_BUFF], 0, 3 * sizeof(float));

    glEnableVertexArrayAttrib(vao, POSITION_BIND);
    glVertexArrayAttribFormat(vao, POSITION_BIND, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vao, POSITION_BIND, POSITION_BIND);

    glEnableVertexArrayAttrib(vao, NORMAL_BIND);
    glVertexArrayAttribFormat(vao, NORMAL_BIND, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vao, NORMAL_BIND, NORMAL_BIND);

    glEnableVertexArrayAttrib(vao, UV_BIND);
    glVertexArrayAttribFormat(vao, UV_BIND, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vao, UV_BIND, UV_BIND);

    glEnableVertexArrayAttrib(vao, COLOR_BIND);
    glVertexArrayAttribFormat(vao, COLOR_BIND, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vao, COLOR_BIND, COLOR_BIND);
    /**

    glEnableVertexArrayAttrib(vao_a[VAO_D], LOC_POS);
    glVertexArrayAttribFormat(vao_a[VAO_D], LOC_POS, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vao_a[VAO_D], LOC_POS, LOC_POS);
 
     */

    /*if (materials.size() > 1) {
        std::cout << "More than 1 material in .obj file <"  << _path <<"> (Not implemented yet) \n";
    }*/

    // this will NOT READ MATERIALS
    // we will read materials in render_node

}
