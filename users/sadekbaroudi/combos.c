#include "combos.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM redo_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM apostrophe_combo[] = {KC_X, KC_DOT, COMBO_END};
//const uint16_t PROGMEM capsword_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
  [REDO] = COMBO_ACTION(redo_combo),
  [DELETE] = COMBO_ACTION(delete_combo),
  [APOSTROPHE] = COMBO_ACTION(apostrophe_combo),
//  [CAPSWORD] = COMBO_ACTION(capsword_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  static uint16_t kc;
  switch(combo_index) {
    case UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case REDO:
      if (pressed) {
        tap_code16(LCTL(KC_Y));
      }
      break;
    case DELETE:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;
    case APOSTROPHE:
      if (pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          kc = KC_DOUBLE_QUOTE;
        } else {
          kc = KC_QUOTE;
        }
        tap_code16(kc);
      }
      break;
    // case CAPSWORD:
    //   // NOTE: if you change this behavior, may want to update in process_records.c for capsword macro behavior
    //   if (pressed) {
    //     enable_caps_word();
    //   }
    //   break;
  }
}
// END COMBOS