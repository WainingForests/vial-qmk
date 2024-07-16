// Making sharedDefines defined
#ifndef SHAREDDEFINES_H
#define SHAREDDEFINES_H

// Inlcuding external files
#include QMK_KEYBOARD_H
#include "version.h"

// Defining some BOOLS
#define bool _Bool
#define true 1
#define false 0

// Defining keymappings
#define colemak 0
#define hub     1
#define qwerty  2
#define furo    3

extern bool scrollwheel_up_on;
extern bool scrollwheel_down_on;
extern uint16_t scroll_delay_timer;

#endif
