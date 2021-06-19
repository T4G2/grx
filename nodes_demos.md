# Base Node
```
[[ name ]]
    pos = [x, y, z]
    rot = [x, y, z]
    scl = [x, y, z]
```
# Camera Node
```
[[ name ]]
    fov = float
    postprocess = str  // TODO
    projection_type = "perspective"/"orthogonal"
    auto_size = bool
    size = [1084 545]
```

# Mesh Node
```
[[ name ]]
    normal = true  // if normal mapping, it must be before MESH parameter
    mesh = path
    material = material
```
# Light Node
```
[[ name ]]
    intensity = float
    diffuse = [r, g, b]
    specular = [r, g, b]
```
