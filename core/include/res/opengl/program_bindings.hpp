/**
 * @file program_bindings.hpp
 * @author your name (you@domain.com)
 * @brief Binding for programs unforms etc..
 * @version 0.1
 * @date 2021-05-17
 */



/** Those two can be changed onlyu by camera **/
const int VIEW_MATRIX = 0;
const int PROJECTION_MATRIX = 1;

/** can be written by any Render object, which need to change its position while drawing **/
const int POS_MATRIX = 2;

/** LIGHTS**/

/** Will be changed by current MATERIAL**/

const int AMBIENT_COLOR_BIND = 3;
const int DIFFUSE_COLOR_BIND = 4;
const int SPECULAR_COLOR_BIND = 5;
const int SHININESS_BIND = 6;

const int ALBEDO_MAP_BIND = 7;
const int NORMAL_MAP_BIND = 8;
const int SPECULAR_MAP_BIND = 9;

const int BIND_SIZE = 10;