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



Mesh::Mesh(std::string path, BaseResourceManager<Material>& material_manager, bool normal_mapping) {
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


    if (attrib.normals.empty()) {
        std::cout << "ERROR| No Normal Data for Mesh <" << _path << "> \n";
        exit(1);
    }

    for( auto& indice : mesh.indices) {
        count++;
        int vertex_pos =  3*indice.vertex_index;
        int texcoord_pos =  2*indice.texcoord_index;
        int normal_pos =  3*indice.normal_index;
        positions.push_back(glm::vec3(attrib.vertices[vertex_pos], attrib.vertices[vertex_pos + 1], attrib.vertices[vertex_pos + 2]));
        colors.push_back(glm::vec3(attrib.colors[vertex_pos], attrib.colors[vertex_pos+1], attrib.colors[vertex_pos+2]));
        uv_coords.push_back(glm::vec2(attrib.texcoords[texcoord_pos], attrib.texcoords[texcoord_pos+1]));
        normals.push_back(glm::vec3(attrib.normals[normal_pos], attrib.normals[normal_pos+1], attrib.normals[normal_pos+2]));
    }

    glNamedBufferStorage(vbos[POSITION_BUFF], sizeof(glm::vec3) * positions.size(), positions.data(), 0);
    glNamedBufferStorage(vbos[NORMAL_BUFF], sizeof(glm::vec3) * normals.size(), normals.data(), 0);
    glNamedBufferStorage(vbos[COLOR_BUFF], sizeof(glm::vec3) * colors.size(), colors.data(), 0);
    glNamedBufferStorage(vbos[UV_BUFF], sizeof(glm::vec2) * uv_coords.size(), uv_coords.data(), 0);

    if (normal_mapping) {
        // Create tangent and bitangetns
        std::cout << " NORMAL MAPPING  ON THIS <" << _path << "\n";

        for ( int i=0; i<positions.size(); i+=3){

            // Shortcuts for vertices
            glm::vec3 & v0 = positions[i+0];
            glm::vec3 & v1 = positions[i+1];
            glm::vec3 & v2 = positions[i+2];

            // Shortcuts for UVs
            glm::vec2 & uv0 = uv_coords[i+0];
            glm::vec2 & uv1 = uv_coords[i+1];
            glm::vec2 & uv2 = uv_coords[i+2];

            // Edges of the triangle : position delta
            glm::vec3 deltaPos1 = v1-v0;
            glm::vec3 deltaPos2 = v2-v0;

            // UV delta
            glm::vec2 deltaUV1 = uv1-uv0;
            glm::vec2 deltaUV2 = uv2-uv0;

            float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
            glm::vec3 tangent = (deltaPos1 * deltaUV2.y   - deltaPos2 * deltaUV1.y)*r;

            tangents.push_back(tangent);
            tangents.push_back(tangent);
            tangents.push_back(tangent);

        }
    }

    glCreateVertexArrays(1, &vao);
    glVertexArrayVertexBuffer(vao, POSITION_BIND, vbos[POSITION_BUFF], 0, sizeof(glm::vec3));
    glVertexArrayVertexBuffer(vao, NORMAL_BIND, vbos[NORMAL_BUFF], 0, sizeof(glm::vec3));
    glVertexArrayVertexBuffer(vao, UV_BIND, vbos[UV_BUFF], 0, sizeof(glm::vec2));
    glVertexArrayVertexBuffer(vao, COLOR_BIND, vbos[COLOR_BUFF], 0, sizeof(glm::vec3));

    if (normal_mapping) { 
        glNamedBufferStorage(vbos[TANGENT_BUFF], sizeof(glm::vec3) * tangents.size(), tangents.data(), 0);
        glVertexArrayVertexBuffer(vao, TANGENT_BIND, vbos[TANGENT_BUFF], 0, sizeof(glm::vec3));  
    }

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

    if (normal_mapping) { 
        
        glEnableVertexArrayAttrib(vao, TANGENT_BIND);
        glVertexArrayAttribFormat(vao, TANGENT_BIND, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(vao, TANGENT_BIND, TANGENT_BIND);
    }

}
