#version 450

out vec4 final_color;

in vec3 tex_coords;

layout(binding = 0) uniform samplerCube skybox;

void main() {
    final_color = texture(skybox, tex_coords);
    //final_color = vec4(tex_coords, 1);
}