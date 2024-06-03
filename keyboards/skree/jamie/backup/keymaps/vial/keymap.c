#include QMK_KEYBOARD_H
#include "4x5_3_track.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_4x5(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I,   KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K,   KC_L,   KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM,KC_DOT ,KC_SLSH,
              KC_LBRC, KC_RBRC,                                           KC_EQL, KC_BSLS,
                         RAISE, KC_SPC, KC_BSPC,      KC_DEL, KC_ENT, LOWER
        ),

    [_LOWER] = LAYOUT_4x5(
        QK_BOOT,_______,_______,_______,KC_LBRC,                  KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,WYLD_AUTO_MS_TOG,
        KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                  KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,
        _______,_______,_______,SNIPING,DRGSCRL,                  _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,
                         KC_LBRC, KC_RBRC,                                         KC_EQL, KC_BSLS,
                            _______, KC_BTN1, KC_BTN3,    _______, _______, _______
        ),

    [_RAISE] = LAYOUT_4x5(
        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6, KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,
        _______,_______,_______,_______,KC_LBRC,                    KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,
        KC_LEFT,KC_UP,KC_DOWN,KC_RGHT,KC_LPRN,                      KC_RPRN,KC_MPRV,KC_MPLY,KC_VOLU,KC_VOLD,
                KC_LBRC, KC_RBRC,                                                   KC_EQL, KC_BSLS,
                                _______, _______,_______,     _______,_______,_______
        ),
    [_MOUSE] = LAYOUT_4x5(
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, SNIPING, DRGSCRL,         _______, _______, _______, _______, _______,
                 _______, _______,                                             _______, _______,
                            _______, KC_BTN1, KC_BTN3,    _______, _______, _______
        )
};

void pointing_device_init_user(void) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);
#endif
#ifdef POINTING_DEVICE_COMBINED
    pointing_device_set_cpi_on_side(true, CHARYBDIS_DRAGSCROLL_DPI); // LEFT
    pointing_device_set_cpi_on_side(false, 2000);  // RIGHT
#endif// always required before the auto mouse feature will work
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WYLD_AUTO_MS_TOG:
            if (record->event.pressed) {
                set_auto_mouse_enable(!get_auto_mouse_enable());
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}
#endif

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#else
    debug_enable=false;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;
#endif
}
