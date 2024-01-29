
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        JS_1, JS_2, KC_NO,
        JS_4, JS_5, JS_6,
        JS_7, JS_8, JS_9,
        JS_10, JS_11, JS_12
    )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =  {ENCODER_CCW_CW(JS_13, JS_14), ENCODER_CCW_CW(JS_0, JS_15)},
};


/*
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
			    tap_code(JS_3);
			    // JS_3;
            }
            break;
        case 1:
            if (active) {
			    tap_code(JS_0);
			    // JS_0;
            }
            break;
    }

    return true;
}
*/

