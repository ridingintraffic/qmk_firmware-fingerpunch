#include QMK_KEYBOARD_H


#define _BASE 0
#define _FUNCTION 1
#define _GAME 2
#define _KICAD 3
#define _FUSION 4

enum custom_keycodes {
  BASE = SAFE_RANGE,
  FUNCTION,
  GAME,
  KICAD,
  FUSION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MINS, \
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    \
    KC_LCTL, KC_LGUI, KC_LALT, MO(_FUNCTION),            KC_BSPC,  KC_SPC, KC_ENT \
  ),


  [_FUNCTION] = LAYOUT_halfdash( \
    RESET,   TG(_GAME), TG(_KICAD), TG(_FUSION), KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  RGB_TOG,   RGB_MOD,    RGB_HUD,     RGB_HUI, KC_T,    KC_MINS, \
    KC_CAPS, BL_TOGG,   BL_BRTG,    BL_INC,      BL_DEC,  KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,      KC_X,       KC_C,        KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI,   KC_LALT,    _______,            KC_BSPC,   KC_SPC, KC_ENT \
  ),

  [_GAME] = LAYOUT_halfdash( \
    KC_F4,   KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G,    KC_N, \
    KC_Z,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_D,    KC_Y, \
    KC_P,    KC_A,    KC_F,    KC_D,    KC_L,    KC_H,    KC_F7, \
    KC_LSFT, KC_T,    KC_K,    KC_SCLN, KC_DOT,  KC_B,    \
    KC_LCTL, KC_GRV, KC_LALT, TG(_GAME),            KC_J,  KC_X, KC_COMM \
  ),

  [_KICAD] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI, KC_LALT, TG(_KICAD),            KC_BSPC,  KC_SPC, KC_ENT \
  ),

  [_FUSION] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI, KC_LALT, TG(_FUSION),            KC_BSPC,  KC_SPC, KC_ENT \
  )

};
