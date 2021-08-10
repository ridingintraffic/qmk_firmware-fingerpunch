#include "encoder.h"

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }

void encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) {
        return;
    }

    // default behavior if undefined
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      if(clockwise) {
        tap_code16(C(KC_RGHT));
      }
      else{
        tap_code16(C(KC_LEFT));
      }
    }
}
