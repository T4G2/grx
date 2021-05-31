#version 450



layout(location = 12) uniform float time;

layout(location = 3) uniform vec3 eye_position;
layout(location = 1) uniform mat4 view;

//layout(location = 4) uniform vec4 light_position;
//layout(location = 5) uniform vec3 light_ambient_color;
//layout(location = 6) uniform vec3 light_diffuse_color;
//layout(location = 7) uniform vec3 light_specular_color;

layout(location = 8) uniform vec3 material_ambient_color;
layout(location = 9) uniform vec3 material_diffuse_color;
layout(location = 10) uniform vec3 material_specular_color;
layout(location = 11) uniform float material_shininess;

//layout(binding = 0) uniform sampler2D material_diffuse_texture;

layout(location = 0) in vec3 fs_position;
layout(location = 1) in vec3 fs_normal;
layout(location = 2) in vec2 fs_texture_coordinate;

layout(location = 0) out vec4 final_color;


void main()
{
    vec4 FORWARD = vec4(0, 0, 1, 0);
    vec3 forward = vec3(view * FORWARD); 

    vec3 N = normalize(fs_normal);
    vec3 E = normalize(eye_position - fs_position);
    float angle = dot(N, E );

    float x = fs_normal.x;
    float y = fs_normal.y;
    float z = fs_normal.z;

    //float fx = sin(x + time) + cos(y + time);
    //float fy = cos(x + time) + sin(y + time);
    //float fz = sin(time) / 2 + 0.5;
    final_color = vec4(angle, angle, angle, 1.0);
}
