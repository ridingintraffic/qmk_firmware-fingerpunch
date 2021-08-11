#include "encoder_stuff.h"

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }

void encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) {
        return;
    }

    // default behavior if undefined
    if (index == 0) {
        // Volume control
        if (clockwise) {
            #ifdef RGBLIGHT_ENABLE
            rgblight_increase_hue();
            #else
            tap_code(KC_VOLU);
            #endif
        } else {
            #ifdef RGBLIGHT_ENABLE
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
      if(clockwise) {
        #ifdef RGBLIGHT_ENABLE
        rgblight_step();
        #else
        tap_code16(C(KC_RGHT));
        #endif
      }
      else{
        #ifdef RGBLIGHT_ENABLE
        rgblight_step_reverse();
        #else
        tap_code16(C(KC_LEFT));
        #endif
      }
      #ifdef RGBLIGHT_ENABLE
      rgb_set_user_config_from_current_values();
      #endif
    }
}
