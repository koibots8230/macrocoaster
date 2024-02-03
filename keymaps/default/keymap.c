// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

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
                l_pos = 0;
                joystick_set_axis(0, l_pos);
            } else {
			    unregister_joystick_button(3);
            }
            return false;
       case 1:
            if (active) {
			    register_joystick_button(0);
                r_pos = 0;
                joystick_set_axis(1, r_pos);
            } else {
			    unregister_joystick_button(0);
            }
            return false;
    }
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 1:
            if (!clockwise) {
                //register_joystick_button(13);
                //unregister_joystick_button(13);
                l_pos -= JOYSTICK_AXIS_PRECISION;
            } else {
                //register_joystick_button(14);
                //unregister_joystick_button(14);
                l_pos += JOYSTICK_AXIS_PRECISION;
            }
            joystick_set_axis(0, l_pos);
            joystick_set_axis(0, 1000);
            break;
        case 0:
            if (clockwise) {
                //register_joystick_button(15);
                //unregister_joystick_button(15);
                r_pos -= JOYSTICK_AXIS_PRECISION;
            } else {
                //register_joystick_button(16);
                //unregister_joystick_button(16);
                r_pos += JOYSTICK_AXIS_PRECISION;
            }
            joystick_set_axis(1, r_pos);
            break;
    }
    return true;
}

