#version 450



layout(location = 0) uniform mat4 proj_view;
layout(location = 1) uniform mat4 model;

const vec2 triangle[3] = {
	vec2(0.5, -0.5),
	vec2(-0.5, -0.5),
	vec2(0.0, 0.5)
};

void main()
{
	vec3 pos = vec3(triangle[gl_VertexID], 0.0);

    gl_Position = proj_view * vec4(pos, 0);
}
