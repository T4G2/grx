#version 450

#define PI 3.1415926538

layout(location = 3) uniform float time;

layout(location = 0) out vec4 final_color;


void main()
{
    float r = mod(time, 1.0);
    final_color = vec4(sin(r * PI) , 1.0, 1.0, 1.0);
}
