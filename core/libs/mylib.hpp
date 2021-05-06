/**
 * @file mylib.hpp
 * @author your name (you@domain.com)
 * @brief  Basic library with few basic functions
 * @version 0.1
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <string>
#include <fstream>
#include <tuple>
#include <filesystem>


/**
 * @brief Load File
 * 
 * @param path which file
 * @return std::pair<std::string, bool> : File Source, Error
 */
static std::pair<std::string, bool> load_file(std::string path) {
    try {
        std::ifstream ifs(path);
    std::string content( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>() ) );
    return {std::move(content), false};

    } catch (std::exception) {
        return {std::string(), true};
    }
}


static void change_curr_dir_debug(std::string path) {
    std::filesystem::current_path(path); //setting path
}