# TODO

## Application

### Window
### Input

## OpenGL

### Program Creation
### Shader Loading -Composition


## Scenes

### Objects
### Render
### Camera (Special object)

## Resources

### Models
### Textures
### Texture batches -> Albedo, Normal, Displacement, etc Map..


# Design ideas:
 - Every object is responsible for way how it will be drawed
   - Object will be grouped by programs
   - Program groups,
  

- All resources will be loaded from toml file


# How many managers there had to be ??

- Textures
  - load_from file
  - create (empty for buffers etc)
  - create mip-maps

- Models
  - load
  - ?? create VAO objects ?
  - bind

- Scenes
  - load
  - create
  - set_as_active  
