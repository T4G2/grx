/**
 * @file skybox_node.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-21
 */


#pragma once

#include "base_node.hpp"
#include "cubemap_texture.hpp"
#include "program.hpp"




class SkyboxNode : public BaseNode {

    static constexpr const float skyboxVertices[] = {
    // positions          
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};

GLuint SKYBOX_CUBE_POS_BIND = 0;



    std::map<std::string, init_prop<SkyboxNode>> prop_func = 
    {
        {"active", &SkyboxNode::init_active},
        {"program", &SkyboxNode::init_program},
        {"left", &SkyboxNode::init_left},
        {"right", &SkyboxNode::init_right},
        {"top", &SkyboxNode::init_top},
        {"bottom", &SkyboxNode::init_bottom},
        {"front", &SkyboxNode::init_front},
        {"back", &SkyboxNode::init_back}
    };

public:



     SkyboxNode(std::string name_a, BaseNodeInstance& instance): BaseNode(name_a, instance) {};

    inline static const std::string NODE_NAME = "Skybox";
    CubemapTexture cubemap;
    bool active = true;
    std::string left, right, top, bottom, front, back;
    Program* program_ptr = nullptr;

    GLuint _vbo;
    GLuint _vao;

    virtual void init() override;
    virtual void update(float delta) override;
    virtual void draw() override;
    virtual void input(input_struct event) override;

    /** init_attributes
    
    void init_attribute(toml_value);
    **/
   void init_active(toml_value data);
   void init_program(toml_value data);

   void init_left(toml_value data);
   void init_right(toml_value data);
   void init_top(toml_value data);
   void init_bottom(toml_value data);
   void init_front(toml_value data);
   void init_back(toml_value data);


   void activate();
   void draw_skybox();
   void bind_cubemap(GLuint binding);
   

   virtual void init_custom_toml(BaseNodeInstance::toml_properties_t props) override;

   virtual ~SkyboxNode()= default;

};