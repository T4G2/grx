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


- Add AppExceptions : std::runtime_exception


# How many managers there had to be ??

- Textures
  - load_from file  DONE
  - create (empty for buffers etc) 
  - create mip-maps DONE

- Models
  - load
  - ?? create VAO objects ?
  - bind

- Scenes
  - load
  - create
  - set_as_active  



