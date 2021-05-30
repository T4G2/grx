grX is university project for subject PV112 - Computer Graphics API


Glad - binding for OpenGL
glfw - Widnwos, inputs, events
glm - OpenGL Math

Conventions:
    do not change state in render/draw
    only change state in update

    textures and files that accompany .obj files should be put in the same folder as .obj file
    in material files there should be only custom materials for textures

    .obj files should be linked into materials and .mtl files directly
    .obj files should have no perface material
    .obj files should have only ONE shape

    demo.toml is demo scene where there are basic principles of scene building showed
    you can view how to construct basic nodes in nodes_demos.md 


Classes architecture:
   ` IApplication` - basic framework for `Application`
    res - resource Classes
        all resources are then stored in `BaseResourceManager<res>`
    nodes - all nodes, you can have in scene and classes that system need to work
    managers - Managers of different resources
       ` BaseResourceManager<res> `- look up for description

    libs - my own little libraries , where I implement basic things i need in code 

How to create game:
- We create class derived from `IApplication`,
        
    - in IApplication we already have managers for:
        Texture, Programs, Shaders, Meshes, Scenes
    - we must override `IApplication` virtual classes:
        you cna see in `iapplication.hpp`
    - Then we must register nodes we want to use in `scene_manager` like `scene_manager.register_node(NodeFactory<Node>());`

Creating new Nodes:
- New nodes must be inherited from `BaseNode`
  - `BaseNode` already has position, rotation and scale
  - `BaseNode` has input(), draw(), update() funtions


Tags on Nodes:

- Every node can have tags,
  - every node added into scene with given tag will be specially processed by  SceneManager 
    - (Mostly RenderNodes and Light Nodes, special fro rendering)


Do not Create New Nodes with properties, type(default type), scl, rot, pos


THERE ARE 10 LAYERS OF DRAWING 

Credits:

    https://textures.pixel-furnace.com/
