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
layout(binding = 1) uniform sampler2D normal_texture;
layout(binding = 2) uniform sampler2D specular_texture;
layout(binding = 3) uniform sampler2D metalic_texture;

layout(binding = 4) uniform samplerCube enviroment;

layout(location = 0) in vec3 fs_position;
layout(location = 1) in vec3 fs_normal;
layout(location = 2) in vec2 fs_texture_coordinate;
layout(location = 4) in vec3 fs_tangent;


layout(location = 0) out vec4 final_color;


const float CONE_LIGHT_INNER_RATIO = 0.8;


vec3 CalcBumpedNormal() // https://www.ogldev.org/www/tutorial26/tutorial26.html
{
    vec3 N = normalize(fs_normal);
    vec3 T = normalize(fs_tangent);
    T= normalize(T - dot(T, N) * N);
    vec3 BT = cross(T, N);
    vec3 BumpMapNormal = texture(normal_texture, fs_texture_coordinate).xyz;
    BumpMapNormal = 2.0 * BumpMapNormal - vec3(1.0, 1.0, 1.0);
    vec3 NewNormal;
    mat3 TBN = mat3(T, BT, N);
    NewNormal = fs_normal +  TBN * BumpMapNormal;
    NewNormal = normalize(NewNormal);
    return NewNormal;
}


void main()
{

    vec3 color_sum = vec3(0);
    vec3 texture_color_diffuse = texture(diffuse_texture, fs_texture_coordinate).rgb;   
    vec3 N = CalcBumpedNormal() ;
    vec3 specular_texture =  texture(specular_texture, fs_texture_coordinate).rgb;   

    final_color =  vec4(texture(metalic_texture, fs_texture_coordinate).rgb, 1.0);
    vec3 I = normalize(fs_position - eye_position);
    vec3 R = reflect(I, N);

    vec3 reflected_color = texture(enviroment, R).rgb;
    reflected_color *= texture(metalic_texture, fs_texture_coordinate).rgb;
    

    //final_color = vec4(normalize(N), 1.0f);
    //return;

    for (int i = 0; i < lights.length(); i++ ) { 
        Light light = lights[i];

        vec3 light_v = fs_position - light.position.xyz;
        float theta = dot(normalize(-light.rotation.xyz),normalize(light_v ));
        float outter_angle = radians(light.angle);
        float inner_angle = outter_angle * CONE_LIGHT_INNER_RATIO;

        float theta_angle = acos(theta);

        float factor_angle = max(0, min(1, (outter_angle - abs(theta_angle)) / (outter_angle - inner_angle)));

        factor_angle = light.position.w == 0  || light.angle == 0 ? 1 : factor_angle;


        vec3 light_vector = (light.position.xyz - fs_position * light.position.w);
        //vec3 N = fs_normal;
        vec3 E = normalize( (eye_position - fs_position));
        vec3 L =  normalize(light_vector);
        vec3 H = normalize((L + E));


        float NdotL = max(dot(N, L), 0.01);
        float NdotH = max(dot(N, H), 0.0001);


        float factor = light.intensity ;
        factor /=  (light.position.w == 0.0)  ? 1  : ( pow(length(light_vector), 2));

        vec3 diffuse = material_diffuse_color.rgb * light.diffuse_color.rgb * texture_color_diffuse;
        vec3 specular = specular_texture * material_specular_color.rgb * light.specular_color.rgb;

        vec3 color = NdotL * diffuse * factor + pow(NdotH, material_shininess) * specular * factor + reflected_color;


        color_sum += color*factor_angle;

    }

    final_color = vec4(color_sum, 1.0);
}
