#include "sadekbaroudi.h"

static bool scrolling_mode = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

layer_state_t layer_state_set_pointing(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAVIGATION:
            scrolling_mode = true;
            pointing_device_set_cpi(200);
            break;
        default:
            if (scrolling_mode) {
                scrolling_mode = false;
                pointing_device_set_cpi(2000);
            }
            break;
    }
    return state;
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = -left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}