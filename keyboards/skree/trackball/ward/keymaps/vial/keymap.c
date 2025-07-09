#include QMK_KEYBOARD_H
#include "ward.h"

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
    [_QWERTY] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                                _______,_______,
                                _______,_______,_______,                                _______,_______,_______,
                                _______,_______,_______,                                _______,_______,_______
    ),

    [_LOWER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                                _______,_______,
                                _______,_______,_______,                                _______,_______,_______,
                                _______,_______,_______,                                _______,_______,_______
    ),

    [_RAISE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                                _______,_______,
                                _______,_______,_______,                                _______,_______,_______,
                                _______,_______,_______,                                _______,_______,_______
    ),
    [_MOUSE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                                _______,_______,
                                _______,_______,_______,                                _______,_______,_______,
                                _______,_______,_______,                                _______,_______,_______
        ),
    [_MOUSE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                                _______,_______,
                                _______,_______,_______,                                _______,_______,_______,
                                _______,_______,_______,                                _______,_______,_______
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
    pointing_device_set_cpi_on_side(false, 3000);  // RIGHT
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
