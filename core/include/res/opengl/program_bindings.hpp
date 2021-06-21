/**
 * @file program_bindings.hpp
 * @author your name (you@domain.com)
 * @brief Binding for programs unforms etc..
 * @version 0.1
 * @date 2021-05-17
 */



/** Those two can be changed onlyu by camera **/
const int VIEW_MATRIX_LOCATION = 0;
const int PROJECTION_MATRIX_LOCATION = 1;

/** can be written by any Render object, which need to change its position while drawing **/
const int MODEL_MATRIX_LOCATION = 2;

/** LIGHTS**/

/** Will be changed by current MATERIAL**/

const int MATERIAL_AMBIENT_COLOR_LOCATION = 3;
const int MATERIAL_DIFFUSE_COLOR_LOCATION = 4;
const int MATERIAL_SPECULAR_COLOR_LOCATION = 5;
const int MATERIAL_SHININESS_LOCATION = 6;

const int DIFFUSE_TEXTURE_BINDING = 7;
const int NORMAL_TEXTURE_BINDING = 8;
const int SPECULAR_TEXTURE_BINDING = 9;
const int METALIC_TEXTURE_BINDING = 10;

const int CUBEMAP_BINDING = 11;

const int LIGHTS_BINDING = 12;
const int INSTANCED_BINDING = 13;

const int TIME_LOCATION = 14;
const int EYE_POS_LOCATION = 15;

const int BIND_SIZE = 16;