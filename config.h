#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

//#define NO_DEBUG
//#define NO_PRINT

#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { B4, D7 }
#define ENCODERS_PAD_B { E6, C6 }
#define ENCODER_RESOLUTION 4
#define DIP_SWITCH_PINS { D4, B5 }

#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 1

#define JOYSTICK_BUTTON_COUNT 17
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_AXIS_RESOLUTION 8


/* Set how much the joystick moves per encoder click, ranges from -128 to 127 (works best with powers of 2) */
#define JOYSTICK_AXIS_SENSITIVITY 8

/* Enable to allow the joystick to overflow to the other side when at max value */
//#define JOYSTICK_AXIS_ALLOW_OVERFLOW
