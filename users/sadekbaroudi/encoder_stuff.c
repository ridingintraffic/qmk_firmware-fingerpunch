#include "encoder_stuff.h"

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) {
        return true;
    }

    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            #if defined(RGBLIGHT_ENABLE) && defined(ENCODERS_FOR_RGB)
            rgblight_increase_hue();
            #else
            tap_code(KC_VOLU);
            #endif
        } else {
            #if defined(RGBLIGHT_ENABLE) && defined(ENCODERS_FOR_RGB)
            rgblight_decrease_hue();
            #else
            tap_code(KC_VOLD);
            #endif
        }

        #ifdef RGBLIGHT_ENABLE
        rgb_set_user_config_from_current_values();
        #endif
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        #if defined(RGBLIGHT_ENABLE) && defined(ENCODERS_FOR_RGB)
        rgblight_step();
        #else
        tap_code16(C(KC_RGHT));
        #endif
      }
      else{
        #if defined(RGBLIGHT_ENABLE) && defined(ENCODERS_FOR_RGB)
        rgblight_step_reverse();
        #else
        tap_code16(C(KC_LEFT));
        #endif
      }
      #if defined(RGBLIGHT_ENABLE) && defined(ENCODERS_FOR_RGB)
      rgb_set_user_config_from_current_values();
      #endif
    }

    return true;
}
