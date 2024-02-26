#include QMK_KEYBOARD_H
#include "5x6_full_track.h"

//#define _WORKMAN 0
#define _QWERTY 0
//#define _COLEMAK 1
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3

#define QWERTY MO(_QWERTY)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                      KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
        KC_LCTL, KC_LALT, KC_LBRC,KC_RBRC,                                                    KC_PLUS, KC_EQL, KC_RALT,  KC_RCTL,
                                                RAISE, KC_SPC,                LOWER,
                                                KC_TAB, KC_HOME,              KC_ENT,
                                                KC_BSPC, KC_GRV,     KC_LGUI, KC_LALT
        ),

    [_LOWER] = LAYOUT_5x6(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                     KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        WYLD_AUTO_MS_TOG,_______,_______,_______,_______,KC_LBRC,            KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,QK_BOOT,KC_PLUS,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,_______,_______,DPI_RMOD,DPI_MOD,DPI_RST,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
        _______,_______, _______,KC_PSCR,                                                     _______, KC_P0,_______,_______,
                                                _______, KC_BTN1,            _______,
                                                KC_BTN3, KC_BTN2,            _______,
                                                SNIPING,DRGSCRL,     _______,QK_BOOT

        ),

    [_RAISE] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,QK_BOOT,_______,_______,_______,KC_LBRC,                     KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
        _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
        _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,KC_VOLD,
        _______,_______,_______,_______,                                                     KC_EQL ,_______,_______,_______,
                                                _______,_______,             _______,
                                                _______,_______,             _______,
                                                QK_BOOT,_______,     _______,_______
        ),
    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,DPI_RMOD,DPI_MOD,DPI_RST,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,                                                    _______ ,_______,_______,_______,
                                                _______, KC_BTN1,           _______,
                                                KC_BTN3, KC_BTN2,           _______,
                                                SNIPING,DRGSCRL,    _______,QK_BOOT
        )
};

#ifdef POINTING_DEVICE_COMBINED
static void check_drag(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;

#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
    scroll_buffer_x -= mouse_report->x;
#    else
    scroll_buffer_x += mouse_report->x;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_X
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
    scroll_buffer_y -= mouse_report->y;
#    else
    scroll_buffer_y += mouse_report->y;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_Y
    mouse_report->x = 0;
    mouse_report->y = 0;
    if (abs(scroll_buffer_x) > 6) {
        mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
    }
    if (abs(scroll_buffer_y) > 6) {
        mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    check_drag_scroll(&left_report); // updated in trackball.c
    return pointing_device_combine_reports(left_report, right_report);
}
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
    set_auto_mouse_enable(false);  // default is off, must be explicitly enabled
}

// Ensures only the pointing device activates mouse layer on dual track builds
// And also prevents dragscroll from activating it
bool auto_mouse_activation(report_mouse_t mouse_report) {
    return mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.buttons;
}

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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [_LOWER] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_RAISE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

//#ifdef ENCODER_ENABLE
//bool encoder_update_user(uint8_t index, bool clockwise) {
//===
//    if (clockwise) {
//        tap_code(KC_VOLD);
//    } else {
//        tap_code(KC_VOLU);
//    }
//
//    return false;
//}
//#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static char layer_names[5][8] = {
            " BASE\n",
            "LOWER\n",
            "RAISE\n",
            "MOUSE\n",
            " XTRA\n"
            };

bool oled_task_user(void) {
    char* layer_name = layer_names[get_highest_layer(layer_state)];
    char* mode = get_mouse_mode_string();

    if (is_keyboard_left()) {
        //        oled_write_P(PSTR("Layer\n"), false);
        oled_set_cursor(0, 3);
        oled_write_P(PSTR(layer_name), false);

        // Host Keyboard LED Status

//        oled_set_cursor(0, 9);
//        led_t led_state = host_keyboard_led_state();

//        oled_write_P(led_state.num_lock ? PSTR("NUMLK \n") : PSTR("    \n"), false);
//        oled_write_P(led_state.caps_lock ? PSTR("CAPLK \n") : PSTR("    \n"), false);
//        oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("    \n"), false);

        // write WPM to right OLED

        uint16_t dpi = get_current_dpi();
        oled_set_cursor(2, 3);
        oled_write_P(PSTR("DPI "), false);
        oled_set_cursor(0, 5);
        oled_write_P(PSTR(get_u16_str(dpi, ' ')), false);
        oled_set_cursor(0, 8);
        oled_write(PSTR(mode), false);
        oled_set_cursor(2, 10);
        oled_write_P(PSTR("WPM "), false);
        oled_set_cursor(2, 12);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }

    return false;
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
