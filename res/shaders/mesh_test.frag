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


/** TODO
struct Light {
	vec4 position;
	vec4 ambient_color;
	vec4 diffuse_color;
	vec4 specular_color;
    float intensity;
    bool enabled;
};

layout(binding = 1, std430) buffer Lights {
	Light lights[];
};
*/


void main()
{

    vec3 color;

    vec4 FORWARD = vec4(0, 0, 1, 0);
    vec3 forward = vec3(view * FORWARD); 

    vec3 N = normalize(fs_normal);
    vec3 E = normalize(eye_position - fs_position);
    float angle = dot(N, E);

    color = material_ambient_color;
    color.x += angle;
    color.y += angle;
    color.z += angle;
    

    final_color = vec4(color, 1.0);
}
