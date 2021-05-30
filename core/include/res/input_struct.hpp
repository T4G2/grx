/**
 * @file input_struct.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 */
#pragma once


enum input_type_enum {
UNDEFINED = 0,
KEY_PRESS,
KEY_RELEASE,
KEY_DOWN,
MOUSE_MOVE,
MOUSE_BUTTON_PRESS,
MOUSE_BUTTON_RELEASE,
MOUSE_BUTTON_DOWN,
RESIZE
};


struct input_struct {
    input_type_enum input_type = UNDEFINED;
    
    /** KEY EVENT **/
    int key, scancode = -1;

    /** MOUSE_MOVE **/
    double dx= -1;
    double dy= -1;

    /** MOUSE PRESS **/
    int button= -1;

    /** BOTH KEY_EVENT AND MOUSE_PRESS **/
    int action= -1;
    int mods = -1; 

    /** RESIZE **/
    int width = -1;
    int height = -1;
};

