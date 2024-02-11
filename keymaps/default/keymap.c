#include "keycodes.h"
#include QMK_KEYBOARD_H


int16_t l_pos = 0;
int16_t r_pos = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        JS_1, JS_2, KC_NO,
        JS_4, JS_5, JS_6,
        JS_7, JS_8, JS_9,
        JS_10, JS_11, JS_12
    )
};


joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL,
    JOYSTICK_AXIS_VIRTUAL
};


bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
       case 0:
            if (active) {
			    register_joystick_button(3);
                r_pos = 0;
                joystick_set_axis(1, r_pos);
            } else {
			    unregister_joystick_button(3);
            }
            break;
        case 1:
            if (active) {
			    register_joystick_button(0);
                l_pos = 0;
                joystick_set_axis(0, l_pos);
            } else {
			    unregister_joystick_button(0);
            }
            break;
    }
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (!clockwise) {
                register_joystick_button(13);
                unregister_joystick_button(13);
                #ifndef JOYSTICK_AXIS_ALLOW_OVERFLOW
                if (l_pos - JOYSTICK_AXIS_SENSITIVITY > -128) {
                    l_pos -= JOYSTICK_AXIS_SENSITIVITY;
                    joystick_set_axis(0, l_pos);
                }
                #endif
                #ifdef JOYSTICK_AXIS_ALLOW_OVERFLOW
                l_pos -= JOYSTICK_AXIS_SENSITIVITY;
                joystick_set_axis(0, l_pos);
                #endif
            } else {
                register_joystick_button(14);
                unregister_joystick_button(14);
                #ifndef JOYSTICK_AXIS_ALLOW_OVERFLOW
                if (l_pos + JOYSTICK_AXIS_SENSITIVITY < 128) {
                    l_pos += JOYSTICK_AXIS_SENSITIVITY;
                    joystick_set_axis(0, l_pos);
                }
                #endif
                #ifdef JOYSTICK_AXIS_ALLOW_OVERFLOW
                l_pos += JOYSTICK_AXIS_SENSITIVITY;
                joystick_set_axis(0, l_pos);
                #endif
            }
            return false;
        case 1:
            if (clockwise) {
                register_joystick_button(15);
                unregister_joystick_button(15);
                #ifndef JOYSTICK_AXIS_ALLOW_OVERFLOW
                if (r_pos - JOYSTICK_AXIS_SENSITIVITY > -128) {
                    r_pos -= JOYSTICK_AXIS_SENSITIVITY;
                    joystick_set_axis(1, r_pos);
                }
                #endif
                #ifdef JOYSTICK_AXIS_ALLOW_OVERFLOW
                r_pos -= JOYSTICK_AXIS_SENSITIVITY;
                joystick_set_axis(1, r_pos);
                #endif
            } else {
                register_joystick_button(16);
                unregister_joystick_button(16);
                #ifndef JOYSTICK_AXIS_ALLOW_OVERFLOW
                if (r_pos + JOYSTICK_AXIS_SENSITIVITY < 128) {
                    r_pos += JOYSTICK_AXIS_SENSITIVITY;
                    joystick_set_axis(1, r_pos);
                }
                #endif
                #ifdef JOYSTICK_AXIS_ALLOW_OVERFLOW
                r_pos += JOYSTICK_AXIS_SENSITIVITY;
                joystick_set_axis(1, r_pos);
                #endif
            }
            return false;
    }
    return true;
}

