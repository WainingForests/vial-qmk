#include QMK_KEYBOARD_H
#include "dualtb4x6_6.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3
#define _UPTWO 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                _______,_______,_______,            _______,_______,_______
    ),

    [_LOWER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                _______,_______,_______,            _______,_______,_______
    ),

    [_RAISE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                _______,_______,_______,            _______,_______,_______
    ),
    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                _______,_______,_______,            _______,_______,_______
        ),
    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                _______,_______,_______,            _______,_______,_______
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
    check_drag(&left_report); // updated in trackball.c
    return pointing_device_combine_reports(left_report, right_report);
}
#endif


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


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

static const char PROGMEM wylderbuilds[] = {
// 'skree custom logo', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0x8c, 0x8c, 0x8c, 0x8c, 
0x3c, 0x3c, 0x0c, 0x00, 0xe0, 0xf0, 0x80, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x10, 0x00, 0xe0, 0xf0, 
0x30, 0x10, 0x10, 0xb0, 0xf0, 0xe0, 0x00, 0x00, 0xe0, 0xf0, 0x30, 0x30, 0x90, 0x90, 0x98, 0x18, 
0x00, 0xe0, 0xf0, 0x30, 0x30, 0x90, 0x90, 0x98, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
0xc0, 0x60, 0x30, 0x38, 0x18, 0x0c, 0x0c, 0x0c, 0x1c, 0x3c, 0x0c, 0xe0, 0xf8, 0x10, 0x00, 0x00, 
0x80, 0xf0, 0x78, 0x00, 0x00, 0xe0, 0xf0, 0xb0, 0x30, 0x30, 0x70, 0x70, 0x00, 0x20, 0x30, 0x30, 
0xb0, 0xf0, 0x30, 0x30, 0x30, 0x10, 0x10, 0x80, 0xc0, 0x60, 0x30, 0x30, 0x38, 0xf0, 0xf0, 0x00, 
0x00, 0xe0, 0xf0, 0xf0, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x38, 0x30, 0x30, 0x31, 0x31, 0x19, 0x1b, 
0x0f, 0x06, 0x00, 0x1e, 0x1f, 0x03, 0x07, 0x0e, 0x0c, 0x1c, 0x18, 0x00, 0x00, 0x1c, 0x1f, 0x07, 
0x07, 0x0f, 0x0f, 0x1d, 0x19, 0x18, 0x00, 0x3e, 0x3f, 0x13, 0x1b, 0x19, 0x19, 0x19, 0x19, 0x00, 
0x3e, 0x3f, 0x13, 0x1b, 0x19, 0x19, 0x19, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 
0x39, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x18, 0x08, 0x00, 0x00, 0x1f, 0x19, 0x18, 0x18, 0x18, 
0x1f, 0x0f, 0x00, 0x1e, 0x1e, 0x19, 0x19, 0x1b, 0x1b, 0x1b, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 
0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x19, 0x18, 0x18, 0x0c, 0x07, 0x03, 0x00, 0x1c, 
0x0f, 0x03, 0x03, 0x1f, 0x1e, 0x07, 0x03, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void render_wylderbuilds(void) {
    oled_write_raw_P(wylderbuilds, sizeof(wylderbuilds));
}

bool oled_task_user(void) {
    oled_set_cursor(0, 3);
    if (is_keyboard_left()) {
//        oled_write_P(PSTR("Layer\n"), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR(" BASE\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("RAISE\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("MOUSE\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        oled_set_cursor(2, 7);
        oled_write_P(PSTR("WPM "), false);
        oled_set_cursor(1, 8);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
        // Host Keyboard LED Status

        oled_set_cursor(0, 9);
        led_t led_state = host_keyboard_led_state();

        oled_write_P(led_state.num_lock ? PSTR("NUMLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAPLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("    \n"), false);
    } else {
        // write WPM to right OLED
        oled_set_cursor(0, 0);
        render_wylderbuilds();
        oled_scroll_left();
    }

    return false;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
// TWO ENCODERS
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_MOUSE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

