#include "combos.h"
#include "sadekbaroudi.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
//const uint16_t PROGMEM redo_combo[] = {KC_C, KC_D, COMBO_END};
//const uint16_t PROGMEM enter_combo[] = {KC_K, KC_H, COMBO_END};
//const uint16_t PROGMEM delete_combo[] = {KC_D, KC_V, COMBO_END};
//const uint16_t PROGMEM backspace_combo[] = {KC_M, KC_N, COMBO_END};
//const uint16_t PROGMEM apostrophe_combo[] = {KC_Z, KC_SLSH, COMBO_END};
//const uint16_t PROGMEM tab_combo[] = {KC_COMMA, KC_SLSH, COMBO_END};
//const uint16_t PROGMEM capsword_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM p_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM l_combo[] = {LT(_MOUSE, KC_M), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

const uint16_t PROGMEM lbracket_combo[] = {LGUI_T(KC_R), KC_X, COMBO_END};
const uint16_t PROGMEM lcurly_combo[] = {LALT_T(KC_S), KC_C, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {LT(_MOUSE, KC_M), KC_K, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {RSFT_T(KC_N), KC_H, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {RALT_T(KC_E), KC_COMMA, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {RGUI_T(KC_I), KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
//  [REDO] = COMBO_ACTION(redo_combo),
//  [ENTER] = COMBO_ACTION(enter_combo),
//  [DELETE] = COMBO_ACTION(delete_combo),
//  [BACKSPACE] = COMBO_ACTION(backspace_combo),
//  [APOSTROPHE] = COMBO_ACTION(apostrophe_combo),
//  [TAB] = COMBO_ACTION(tab_combo),
//  [CAPSWORD] = COMBO_ACTION(capsword_combo),
  [Q] = COMBO_ACTION(q_combo),
  [P] = COMBO_ACTION(p_combo),
  [B] = COMBO_ACTION(b_combo),
  [J] = COMBO_ACTION(j_combo),
  [L] = COMBO_ACTION(l_combo),
  [SEMICOLON] = COMBO_ACTION(semicolon_combo),
  [LBRACKET] = COMBO_ACTION(lbracket_combo),
  [LCURLY] = COMBO_ACTION(lcurly_combo),
  [LPAREN] = COMBO_ACTION(lparen_combo),
  [LANGLE] = COMBO_ACTION(rangle_combo),
  [RANGLE] = COMBO_ACTION(rangle_combo),
  [RPAREN] = COMBO_ACTION(rparen_combo),
  [RCURLY] = COMBO_ACTION(rcurly_combo),
  [RBRACKET] = COMBO_ACTION(rbracket_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  // can comment out if I use the apostrophe below
  //static uint16_t kc;
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
    case TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case CAPSWORD:
      // NOTE: if you change this behavior, may want to update in process_records.c for capsword macro behavior
      if (pressed) {
        enable_caps_word();
      }
      break;
*/
    case Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;
    case P:
      if (pressed) {
        tap_code16(KC_P);
      }
      break;
    case B:
      if (pressed) {
        tap_code16(KC_B);
      }
      break;
    case J:
      if (pressed) {
        tap_code16(KC_J);
      }
      break;
    case L:
      if (pressed) {
        tap_code16(KC_L);
      }
      break;
    case SEMICOLON:
      if (pressed) {
        tap_code16(KC_SCOLON);
      }
      break;
    case LBRACKET:
      if (pressed) {
        tap_code16(KC_LBRACKET);
      }
      break;
    case LCURLY:
      if (pressed) {
        tap_code16(KC_LCBR);
      }
      break;
    case LPAREN:
      if (pressed) {
        tap_code16(KC_LPRN);
      }
      break;
    case LANGLE:
      if (pressed) {
        tap_code16(KC_LABK);
      }
      break;
    case RANGLE:
      if (pressed) {
        tap_code16(KC_RABK);
      }
      break;
    case RPAREN:
      if (pressed) {
        tap_code16(KC_RPRN);
      }
      break;
    case RCURLY:
      if (pressed) {
        tap_code16(KC_RCBR);
      }
      break;
    case RBRACKET:
      if (pressed) {
        tap_code16(KC_RBRACKET);
      }
      break;
  }
}
// END COMBOS
