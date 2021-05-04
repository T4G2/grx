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





class AbstractManager{
int manager_type;

public:
    int getManagerType() { return manager_type; }
};


template <class T>
class BaseResourceManager: public AbstractBaseManager{
     // path = name
    std::vector<T> _resources;
    std::map<std::string, uint32_t> _path_map; // 

public:
    virtual void load(std::string path) = 0;
    virtual void* get(uint32_t idx) = 0;
    virtual void* get_by_name(std::string name) = 0;
    virtual void remove(uint32_t idx)  = 0;
};


class MainManager {
    // managers
    std::vector<std::unique_pointer<AbstractManager>> _managers;
public:

    int register_manager(std::unique_pointer<AbstractManager>&& man) {
      managers.push_back( &man);
      return _managers.size() - 1;
    } 

    template < class T>
    T get(int i) {
        return dynamic_cast<T*>(managers[i]);
    }
};




class Texture: Resource {
...
}

class TextureManager : BaseResourceManager<Texture> {
...
}

int main() {
  MainManager m;
  int TEXTURE_MANAGER = m.register_manager(TextureManager());
}
