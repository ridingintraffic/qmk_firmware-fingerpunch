#include QMK_KEYBOARD_H

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *                         ,--------------------.    ,--------------------.
 *                         | LOWER| Enter|  Del |    |BckSpc| Space| RAISE|
 *                         `--------------------'    `--------------------.
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumbwheel
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                                            LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_VOLD, KC_MUTE,      KC_VOLU
),

/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *                         ,--------------------.    ,--------------------.
 *                         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|
 *                         `--------------------'    `--------------------.
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumbwheel
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RCTL,
                                            LOWER,        KC_ENT,       KC_QUOT,      KC_BSPC, KC_SPC,       RAISE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_VOLD, KC_MUTE,      KC_VOLU
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Left | Down |  Up  | Right| Tab |           |      |   -  |   =  |   [  |   ]  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *                         ,--------------------.    ,--------------------.
 *                         | LOWER|      |      |    |      |      | RAISE|
 *                         `--------------------'    `--------------------.
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumbwheel
 *                         `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT_ximi(
  _______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______,      KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, _______,
                                  _______, _______, _______,      _______, _______, _______,
                                  _______, _______, _______,      _______, _______, _______
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   '  | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *                         ,--------------------.    ,--------------------.
 *                         | LOWER|      |      |    |  Del |      | RAISE|
 *                         `--------------------'    `--------------------.
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumbwheel
 *                         `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_ximi(
  _______,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______,      KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______,      KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                                  _______, _______, _______,      KC_DEL,  _______, _______,
                                  _______, _______, _______,      _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ | RGB_T| RGB_R| RGB_F|      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_D| HUE_D| SAT_D| VAL_D|      |           |  F11 |  F12 |      |      | Reset| ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *                         ,--------------------.    ,--------------------.
 *                         | LOWER|      |      |    |      |      | RAISE|
 *                         `--------------------'    `--------------------.
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumbwheel
 *                         `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_ximi(
  _______,      RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______,
  _______,      RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  _______,      RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,           KC_F11,  KC_F12,  _______, _______,  QK_RBT,  _______,
                                   _______, _______, _______,           _______, _______, _______,
                                   _______, _______, _______,           _______, _______, _______
)
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _QWERTY:
        case _COLEMAK:
#ifdef HAPTIC_ENABLE
            DRV_pulse(soft_bump);
#endif
            break;
        case _RAISE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(sh_dblsharp_tick);
#endif
            break;
        case _LOWER:
#ifdef HAPTIC_ENABLE
            DRV_pulse(lg_dblclick_str);
#endif
            break;
        case _ADJUST:
#ifdef HAPTIC_ENABLE
            DRV_pulse(pulsing_sharp);
#endif
            break;
        default:
            break;
    }

    return state;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch(keycode) {
        case KC_BTN1:
#ifdef HAPTIC_ENABLE
            DRV_pulse(medium_click1);
#endif
            break;
        case KC_BTN2:
#ifdef HAPTIC_ENABLE
            DRV_pulse(sh_dblclick_str);
#endif
            break;
        case KC_BTN3:
#ifdef HAPTIC_ENABLE
            DRV_pulse(lg_dblclick_med);
#endif
            break;
        default:
            break;
    }

    return true;
}


#ifdef POINTING_DEVICE_ENABLE
static bool scrolling_mode = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

layer_state_t layer_state_set_pointing(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
        case _LOWER:
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

#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
#endif // POINTING_DEVICE_COMBINED
#endif // POINTING_DEVICE_ENABLE