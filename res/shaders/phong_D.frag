#version 450



struct Light {
	vec4 position;
    vec4 rotation;
	vec4 ambient_color;
	vec4 diffuse_color;
	vec4 specular_color;
    float intensity;
    float angle;
    float _pad1;
	float _pad2;
};

layout (binding = 0, std430) buffer Lights {
	Light lights[];
};


layout(location = 12) uniform float time;

layout(location = 3) uniform vec3 eye_position;
layout(location = 1) uniform mat4 view;
layout(location = 0) uniform mat4 model;

layout(location = 8) uniform vec3 material_ambient_color;
layout(location = 9) uniform vec3 material_diffuse_color;
layout(location = 10) uniform vec3 material_specular_color;
layout(location = 11) uniform float material_shininess;

layout(binding = 0) uniform sampler2D diffuse_texture;

layout(location = 0) in vec3 fs_position;
layout(location = 1) in vec3 fs_normal;
layout(location = 2) in vec2 fs_texture_coordinate;


layout(location = 0) out vec4 final_color;

const float CONE_LIGHT_INNER_RATIO = 0.8;

void main()
{

    vec3 color_sum = vec3(0);
    vec3 texture_color_diffuse = texture(diffuse_texture, fs_texture_coordinate).rgb;   



    for (int i = 0; i < lights.length(); i++ ) { 
        Light light = lights[i];

        vec3 light_v = fs_position - light.position.xyz;
        float theta = dot(normalize(-light.rotation.xyz),normalize(light_v ));
        float outter_angle = radians(light.angle);
        float inner_angle = outter_angle * CONE_LIGHT_INNER_RATIO;

        float theta_angle = acos(theta);

        float factor_angle = max(0, min(1, (outter_angle - abs(theta_angle)) / (outter_angle - inner_angle)));

        factor_angle = light.position.w == 0 ? 1 : factor_angle;


        vec3 light_vector = (light.position.xyz - fs_position * light.position.w);
        vec3 N = fs_normal;
        vec3 E = normalize( (eye_position - fs_position));
        vec3 L =  normalize(light_vector);
        vec3 H = normalize((L + E));

        float NdotL = max(dot(N, L), 0.01);
        float NdotH = max(dot(N, H), 0.0001);

        float factor = light.intensity ;
        factor /=  (light.position.w == 0.0) ? 1 : ( pow(length(light_vector), 2));

        vec3 diffuse = material_diffuse_color.rgb * light.diffuse_color.rgb * texture_color_diffuse;
        vec3 specular = material_specular_color.rgb * light.specular_color.rgb;

        vec3 color = NdotL * diffuse * factor  + pow(NdotH, material_shininess) * specular * factor;


        color_sum += color * factor_angle;

    }

    final_color = vec4(color_sum, 1.0);
}
