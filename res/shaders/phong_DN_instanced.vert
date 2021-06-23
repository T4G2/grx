#version 450

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;


layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texture_coordinate;
layout(location = 3) in vec3 color;
layout(location = 4) in vec3 tangent;


layout(location = 0) out vec3 fs_position;
layout(location = 1) out vec3 fs_normal;
layout(location = 2) out vec2 fs_texture_coordinate;
layout(location = 3) out vec3 fs_color;
layout(location = 4) out vec3 fs_tang;
layout(location = 5) out flat int fs_instance_id;

struct Object {
	mat4 model_matrix;
	vec4 ambient_color;
	vec4 diffuse_color;
	vec4 specular_color;

};

layout (binding = 1, std430) buffer Objects {
	Object objects[];
};


void main()
{
	Object object = objects[gl_InstanceID];

	fs_tang = tangent;

	fs_position = vec3(object.model_matrix * vec4(position, 1.0));
	fs_normal = transpose(inverse(mat3(object.model_matrix))) * normal;
	fs_texture_coordinate = texture_coordinate;
    fs_color = color;
    gl_Position =  projection * view * object.model_matrix *  vec4(position, 1.0);
}
