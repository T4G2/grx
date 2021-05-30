#version 450




layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 proj;
layout(location = 3) uniform float time;

const vec2 triangle[3] = {
	vec2(0.2, -0.2),
	vec2(-0.2, -0.2),
	vec2(0.0, 0.2)
};

void main()
{
	float x = triangle[gl_VertexID].x;
	float y = triangle[gl_VertexID].y;

	//float z = 0.0;
	float z = 0.1 * sin(x * y * time * 50);
	vec3 pos = vec3(x, y, z);


    gl_Position =  proj * view * model *vec4(pos, 1);
}
