# ----------------------------------------------------------------------------
# This is the configuration file for the FRAMEWORK_CORE module. The FRAMEWORK_CORE module provides the basic classes and method used in all
# courses.
# ----------------------------------------------------------------------------

# Sets the minimum required version of cmake.
cmake_minimum_required(VERSION 3.14)

# Sets the name of the project, and stores it in the variable PROJECT_NAME.
project(CORE CXX)

# Sets up a new target if it was not already registered.
if(NOT TARGET ${PROJECT_NAME})
    # Adds a new library target.
    add_library(${PROJECT_NAME} STATIC)

    # Sets the build properties. CXX_STANDARD - the C++ standard whose features are requested. CXX_EXTENSIONS - no compiler specific
    # extensions are requested.
    set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES CXX_STANDARD 20
                   CXX_EXTENSIONS OFF
                   PUBLIC_HEADER include/
    )

    if(MSVC)
        # force MSVC to define correct values for __cplusplus macro
        target_compile_options(
            ${PROJECT_NAME}
            PUBLIC "/Zc:__cplusplus"
        )
    endif()

    # Finds the external libraries and load their settings.
    find_package(glfw3 CONFIG REQUIRED)
    find_package(glad CONFIG REQUIRED)
    find_package(imgui CONFIG REQUIRED)
    find_package(glm CONFIG REQUIRED)
    find_package(toml11 CONFIG REQUIRED)
    find_package(tinyobjloader CONFIG REQUIRED)
    find_path(STB_INCLUDE_DIRS "stb.h")

    # Specifies libraries to use when linking the library target defined above.
    if (TARGET glm)
        target_link_libraries(
            ${PROJECT_NAME}
            PUBLIC glad::glad glfw imgui::imgui glm toml11::toml11 tinyobjloader::tinyobjloader
        )
    endif()

    if (TARGET glm::glm)
        target_link_libraries(
            ${PROJECT_NAME}
            PUBLIC glad::glad glfw imgui::imgui glm::glm toml11::toml11 tinyobjloader::tinyobjloader 
        )
    endif()

    # Specifies the include directories to use when compiling the library target.
    target_include_directories(
        ${PROJECT_NAME}
        PUBLIC include include/res/opengl  include/res include/managers include/nodes libs  ${STB_INCLUDE_DIRS}

    )

    # Collects the source files and specifis them as target sources.
    target_sources(
        ${PROJECT_NAME}
        PRIVATE include/iapplication.hpp
                include/graphics_pipeline.hpp
                include/managers/abstract_manager.hpp
                include/managers/base_resource_manager.hpp
                include/managers/scene_manager.hpp
                include/res/scene.hpp
                include/res/base_resource.hpp
                include/res/mesh.hpp
                include/res/opengl/program.hpp
                include/res/opengl/shader.hpp
                include/res/material.hpp
                include/res/texture.hpp

                include/nodes/base_node.hpp
                include/nodes/base_node_instance.hpp
                include/nodes/node_instance.hpp

                src/iapplication.cpp
                src/res/opengl/shader.cpp
                src/res/texture.cpp
                src/res/mesh.cpp
                src/res/scene.cpp
                src/res/material.cpp

                libs/mylib.hpp
                libs/open_gl_error.hpp
                libs/glad_include.hpp
                )
endif()
