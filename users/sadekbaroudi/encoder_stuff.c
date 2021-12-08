#include "encoder_stuff.h"

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) {
        return true;
    }

    // default behavior if undefined
    if (index == 0) {
        switch(biton32(layer_state)){
            case _SYMBOLS:
                // Page up / page down
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_PGUP);
                    #else
                    tap_code(KC_PGDN);
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_PGDN);
                    #else
                    tap_code(KC_PGUP);
                    #endif
                }
                break;
            case _MEDIA:
                // zoom in and out
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(C(KC_MINS));
                    #else
                    tap_code16(C(S(KC_EQL)));
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(C(S(KC_EQL)));
                    #else
                    tap_code16(C(KC_MINS));
                    #endif
                }
                break;
            default:
                // volume up and down
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_VOLD);
                    #else
                    tap_code(KC_VOLU);
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_VOLU);
                    #else
                    tap_code(KC_VOLD);
                    #endif
                }
                break;
        }
    } else if (index == 1) {
        switch(biton32(layer_state)){
            case _NAVIGATION:
                // word select left and right
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(S(KC_LEFT)));
                    #else
                    tap_code16(C(S(KC_RIGHT)));
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(S(KC_RIGHT)));
                    #else
                    tap_code16(C(S(KC_LEFT)));
                    #endif
                }
                break;
            case _FUNCTION:
                // super alt tab 
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_alt_tab(true);
                    #else
                    press_super_alt_tab(false);
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_alt_tab(false);
                    #else
                    press_super_alt_tab(true);
                    #endif
                }
                break;
            default:
                // cursor move one word at a time, left and right
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(KC_LEFT));
                    #else
                    tap_code16(C(KC_RIGHT));
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(KC_RIGHT));
                    #else
                    tap_code16(C(KC_LEFT));
                    #endif
                }
                break;
        }
    }
    else if (index == 2) {
        switch(biton32(layer_state)){
            default:
                // scroll browser tab left and right
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(S(KC_TAB)));
                    #else
                    tap_code16(C(KC_TAB));
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(KC_TAB));
                    #else
                    tap_code16(C(S(KC_TAB)));
                    #endif
                }
                break;
        }
    }

    return true;
}
