#include "combos.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
//const uint16_t PROGMEM redo_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM apostrophe_combo[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_COMMA, KC_SLSH, COMBO_END};
//const uint16_t PROGMEM capsword_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
//  [REDO] = COMBO_ACTION(redo_combo),
  [ENTER] = COMBO_ACTION(enter_combo),
  [DELETE] = COMBO_ACTION(delete_combo),
  [BACKSPACE] = COMBO_ACTION(backspace_combo),
  [APOSTROPHE] = COMBO_ACTION(apostrophe_combo),
  [Q] = COMBO_ACTION(q_combo),
  [SEMICOLON] = COMBO_ACTION(semicolon_combo),
  [TAB] = COMBO_ACTION(tab_combo),
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
/*
    case REDO:
      if (pressed) {
        tap_code16(LCTL(KC_Y));
      }
      break;
*/
    case ENTER:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
    case DELETE:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;
    case BACKSPACE:
      if (pressed) {
        tap_code16(KC_BSPC);
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
    case Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;
    case SEMICOLON:
      if (pressed) {
        tap_code16(KC_SCOLON);
      }
      break;
    case TAB:
      if (pressed) {
        tap_code16(KC_TAB);
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
