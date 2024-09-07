#include QMK_KEYBOARD_H
#include "5x6and2.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        RGB_TOG,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,   KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                        KC_Y,      KC_U,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                         _______,_______,
                                _______,_______,_______,                         _______,_______,_______,
                                        _______,_______,                         _______,_______
        ),

    [_LOWER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                         _______,_______,
                                _______,_______,_______,                         _______,_______,_______,
                                        _______,_______,                         _______,_______
        ),

    [_RAISE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                         _______,_______,
                                _______,_______,_______,                         _______,_______,_______,
                                        _______,_______,                         _______,_______
        )
};
