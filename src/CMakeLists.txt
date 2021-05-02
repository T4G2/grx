# Sets the name of the project, and stores it in the variable PROJECT_NAME.


add_subdirectory(${CMAKE_SOURCE_DIR}/core ${CMAKE_BINARY_DIR}/core)

project(pv112 CXX)

# Adds a new executable target.
add_executable(
    ${PROJECT_NAME}
    main.cpp
)


set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES CXX_STANDARD 20
               CXX_EXTENSIONS OFF
)

# Specifies libraries or flags to use when linking a given target and/or its dependents.
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE CORE
)

file(
    GENERATE
    OUTPUT "$<TARGET_FILE_DIR:${PROJECT_NAME}>/configuration.toml"
    CONTENT "
framework_shaders = \"${CMAKE_SOURCE_DIR}/framework/core/shaders\"
shaders = \"${CMAKE_CURRENT_SOURCE_DIR}/shaders\"
"
)
