#include "dual_trackball.h"

//#ifdef CONSOLE_ENABLE
#include "print.h"
//#endif

//report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
//#ifdef CONSOLE_ENABLE
//    print("in pointing device task combined user\n");
//#endif
//    left_report.h = left_report.x;
//    left_report.v = left_report.y;
//    left_report.x = 0;
//    left_report.y = 0;
//    return pointing_device_combine_reports(left_report, right_report);
//}


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
        mouse_report->v = scro;ll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {

    print("combined_user\n");
    check_drag(&left_report);
    return pointing_device_combine_reports(left_report, right_report);
}

report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {
    print("combined_kb\n");
//    if (is_keyboard_master()) {
    check_drag(&left_report);
    report_mouse_t combined = pointing_device_combine_reports(left_report, right_report);
//    pointing_device_task_charybdis(&combined);
//        mouse_report = pointing_device_task_user(mouse_report);
//    }
    return combined;
}