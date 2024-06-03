#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_5  ,         KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_5  ,         KC_5  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
                         KC_X  , KC_C  ,                                                        KC_COMM,KC_DOT ,
                                 RAISE , KC_SPC, KC_GRV,                         KC_ENT, LOWER ,KC_LGUI,
                                 KC_TAB, KC_TAB,KC_HOME,                         KC_TAB, KC_END,  KC_DEL
    ),

    [_LOWER] = LAYOUT_5x7(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,_______,        _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        _______,_______,_______,_______,_______,KC_LBRC,_______,        _______,KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
                        _______,_______,                                                         KC_P2 , KC_P3 ,
                                _______,_______,_______,                        _______,_______,_______,
                                _______,_______,_______,                        _______,_______,QK_BOOT

    ),

    [_RAISE] = LAYOUT_5x7(
          KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,_______,        _______,KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          _______,_______,_______,_______,_______,KC_LBRC,_______,        _______,KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
          _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
                          _______,_______,                                                        _______,_______,
                                  _______,_______,_______,                        _______,_______,_______,
                                  QK_BOOT,_______,_______,                        _______,_______,QK_BOOT

    )
};