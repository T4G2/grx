#version 450

layout (location = 0) in vec3 in_pos;

out vec3 tex_coords;

layout(location = 2) uniform mat4 projection;
layout(location = 1) uniform mat4 view;
layout(location = 0) uniform vec3 eye_pos;


const float FAR_PLANE = 1700.0;

void main() {
    tex_coords = in_pos;
    gl_Position =   projection * view *  vec4(eye_pos +  FAR_PLANE * in_pos, 1.0);
}