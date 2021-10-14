/* Copyright 2021 Sadek Baroudi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

/*
 * The `LAYOUT_ffkb_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_ffkb_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
        _______, K01,            K02,            K03,            LT(_FUNCTION, K04),     K05,                      K06,                   LT(_FUNCTION, K07),    LT(_WINNAV,K08),  K09,            K0A,          _______, \
        _______, LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),            K15,                      LT(_MOUSE, K16),       RSFT_T(K17),           RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A),  _______, \
        _______, K21,            K22,            K23,            K24,                    K25,                      K26,                   K27,                   K28,              K29,            K2A,          _______, \
                                 KC_MUTE,        KC_DEL,         LT(_NAVIGATION,KC_ENT), LT(_FUNCTION,KC_TAB),     LT(_MEDIA,KC_BSPC),    LT(_SYMBOLS,KC_SPACE), KC_QUOT,          LCTL(KC_BSPC), \
                                                                                                      N_DEL_LINE \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ffkb_base_wrapper(...)       LAYOUT_ffkb_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ffkb_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_ffkb_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_WORKMAN] = LAYOUT_ffkb_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        _______, ________________NAVIGATION_1_______________, _________________NUMPAD_1__________________, _______, 
        _______, ________________NAVIGATION_2_______________, _________________NUMPAD_2__________________, _______, 
        _______, ________________NAVIGATION_3_______________, _________________NUMPAD_3__________________, _______, 
                           _______, _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT, _______, 
                                                         _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        _______, ________________SYMBOLS_L1_________________, ________________SYMBOLS_R1_________________, _______, 
        _______, ________________SYMBOLS_L2_________________, ________________SYMBOLS_R2_________________, _______, 
        _______, ________________SYMBOLS_L3_________________, ________________SYMBOLS_R3_________________, _______, 
                           _______, _______, KC_ENT, KC_DEL,  KC_BSPC, _______, _______, _______,
                                                         _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______, ________________SHIFTNAV_1_________________, ________________FUNCTION_1_________________, _______, 
        _______, ________________SHIFTNAV_2_________________, ________________FUNCTION_2_________________, _______, 
        _______, ________________SHIFTNAV_3_________________, ________________FUNCTION_3_________________, _______, 
                          _______, _______, _______, _______, N_DEL_LINE, KC_SPACE, _______, _______, 
                                                         _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______, ___________________RGB_1___________________, _________________MACROS_1__________________, _______, 
        _______, ___________________RGB_2___________________, _________________MACROS_2__________________, _______, 
        _______, ___________________RGB_3___________________, _________________MACROS_3__________________, _______, 
                          _______, _______, _______, _______, _______, _______, _______, _______,
                                                         _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_1__________________, ___________________BLANK___________________, _______, 
        _______, __________________MOUSE_2__________________, ___________________BLANK___________________, _______, 
        _______, __________________MOUSE_3__________________, ___________________BLANK___________________, _______, 
                    _______, _______, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN3, KC_MS_BTN2, _______, _______,
                                                         _______
    ),

    [_WINNAV] = LAYOUT_wrapper(
        _______, __________________WIN_NAV_1________________, ___________________BLANK___________________, _______, 
        _______, __________________WIN_NAV_2________________, ___________________BLANK___________________, _______, 
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, 
                          _______, _______, _______, _______, _______, _______, _______, _______,
                                                         _______
    )

};


#ifdef OLED_DRIVER_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
} 


// Commenting out logo as it takes up a lot of space :(
static void render_logo(void) {
    // ffkb logo, 128x32px
    static const char PROGMEM ffkb_logo[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 
    0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x8f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x41, 0x41, 0x41, 
    0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
    0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x07, 0x8f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x8f, 0x07, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 
    0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x7f, 0x3f, 0x3e, 0x3e, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 
    0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc1, 0xcd, 0xcd, 0xcc, 0xc0, 0xc1, 0xe1, 0xe3, 0xff, 0xff, 0xef, 0xc1, 0xc1, 0xc1, 
    0xc4, 0xc4, 0xc4, 0xe0, 0xc1, 0xc1, 0xc1, 0xc3, 0xff, 0xff, 0xc1, 0xc0, 0xc0, 0xc1, 0xf9, 0xfd, 
    0xfc, 0xfc, 0xff, 0xe3, 0xe1, 0xc1, 0xc1, 0xcd, 0xcc, 0xcc, 0xcd, 0xc1, 0xc1, 0xe1, 0xe3, 0xff, 
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xcd, 0xcd, 0xcc, 0xc0, 0xc1, 0xe1, 0xe3, 0xff, 0xff, 0xe3, 
    0xe1, 0xc1, 0xc1, 0xcd, 0xcc, 0xcc, 0xcd, 0xc1, 0xc1, 0xe1, 0xe3, 0xff, 0xff, 0xc1, 0xc0, 0xc0, 
    0xc1, 0xf9, 0xfd, 0xfc, 0xfc, 0xff, 0xe3, 0xe1, 0xc1, 0xc0, 0xcc, 0xcd, 0xcd, 0xc9, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff

};
    oled_write_raw_P(ffkb_logo, sizeof(ffkb_logo));

}


/*
static void render_status(void) {
  oled_write_P(PSTR("ffkb\n"), false);
  // Uncomment to set up WPM
  //  sprintf(wpm_as_str, "WPM %03d", get_current_wpm());
  //  oled_write(wpm_as_str,false);
  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("Caps: "), false);
  oled_write_P(led_state.caps_lock ? PSTR("on ") : PSTR("off"), false);
  oled_write_P(PSTR("\n"),false);
  switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty "), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR("Workman"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Nav    "), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media  "), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse  "), false);
            break;
        case _WINNAV:
            oled_write_P(PSTR("Win nav"), false);
            break;

        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
}
*/

/*
static void render_logo_text(void) {
    oled_write_P(PSTR("ffkb"), false);
}
*/

void oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (false) {
        //render_status();
    } else if (true) {
        render_logo();
    } else {
        //render_logo_text();
    }
}

#endif
