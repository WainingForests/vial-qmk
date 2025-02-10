// Include external files
#include QMK_KEYBOARD_H
#include "sharedDefines.h"
#include "tap-dance.c"

// Keymappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[colemak]   = LAYOUT_5x6(
                KC_ESC,       KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8,   KC_9,   KC_0,    KC_BSPC,
                KC_TAB,       KC_Q, KC_W, KC_F, KC_P, KC_B,     KC_J, KC_L, KC_U,   KC_Y,   KC_SCLN, KC_BSLS,
                KC_LSFT,      KC_A, KC_R, KC_S, KC_T, KC_G,     KC_M, KC_N, KC_E,   KC_I,   KC_O,    KC_QUOT,
                TD(ALT_OSL3), KC_Z, KC_X, KC_C, KC_D, KC_V,     KC_K, KC_H,KC_COMM, KC_DOT, KC_SLSH, KC_INT3,
                         KC_LBRC,KC_RBRC,                             KC_MINS,KC_EQL,
                                         MO(3),KC_SPC,    KC_ENT,TG(1),
                                          KC_LCTL, KC_LSFT, KC_RSFT,KC_RCTL,
                                          KC_LALT, KC_LGUI, KC_RGUI,KC_RALT),
  [hub]       = LAYOUT_5x6(
                TO(2), TO(3), KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DB_TOGG,
                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EE_CLR,
                              KC_NO, KC_NO,                                  KC_NO, KC_NO,
                                            KC_NO, KC_NO,      KC_NO, KC_TRNS,
                                             KC_NO, KC_NO,    KC_NO, KC_NO,
                                             KC_NO, KC_NO,    KC_NO, KC_NO),
  [qwerty]    = LAYOUT_5x6(
                KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSPC,
                KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
                KC_LSFT,KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                KC_LCTL,KC_Z, KC_X, KC_C, KC_V, KC_B,                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_INT3,
                              KC_LBRC, KC_RBRC,                                  KC_MINS, KC_EQL,
                                               TO(0), KC_SPC,       KC_ENT, KC_NO,
                                                KC_LCTL,KC_LSFT,   KC_RSFT,KC_RCTL,
                                                KC_LALT,KC_LGUI,   MO(3),KC_RALT),
  [furo]      = LAYOUT_5x6(
                KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                KC_GRV,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PSCR, KC_SCRL, KC_CAPS, KC_TRNS, KC_TRNS, KC_PGUP,
                KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_INS,  KC_HOME, KC_PAUS, KC_TRNS, KC_UP,   KC_PGDN,
                TD(ALT_OSL3),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_DEL,  KC_END,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,
                                 KC_TRNS, KC_TRNS,                                      KC_TRNS,KC_TRNS,
                                                  TO(0), KC_TRNS,       KC_TRNS, TO(2),
                                                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
                                                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS)

};
