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


Mesh::Mesh(std::string path) {
    _path = std::move(path);

    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = "./res/materials"; // Path to material files
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
}
