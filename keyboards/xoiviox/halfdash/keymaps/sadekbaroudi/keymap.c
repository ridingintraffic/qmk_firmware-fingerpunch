#include QMK_KEYBOARD_H


#define _GAME 0
#define _FUNCTION 1
#define _KICAD 2
#define _FUSION 3
#define _ALPHA 4

enum custom_keycodes {
  GAME = SAFE_RANGE,
  FUNCTION,
  KICAD,
  FUSION,
  ALPHA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GAME] = LAYOUT_halfdash( \
    KC_F4,   KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G,    KC_N, \
    KC_Z,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_D,    KC_Y, \
    KC_P,    KC_A,    KC_F,    KC_TAB,    KC_L,    KC_H,    KC_F7, \
    KC_LSFT, KC_T,    KC_COMM, KC_K,    KC_SCLN, KC_DOT,  \
    KC_LCTL, KC_GRV,  MO(_FUNCTION),  KC_LALT,          KC_J,  KC_X, KC_B \
  ),


  [_FUNCTION] = LAYOUT_halfdash( \
    RESET,   TG(_KICAD), TG(_FUSION), TG(_ALPHA), KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  RGB_TOG,   RGB_MOD,    RGB_HUD,     RGB_HUI, KC_T,    KC_MINS, \
    KC_CAPS, BL_TOGG,   BL_BRTG,    BL_INC,      BL_DEC,  KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,      KC_X,       KC_C,        KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI,   _______,    KC_LALT,             KC_BSPC,   KC_SPC, KC_ENT \
  ),

  [_KICAD] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI, TG(_KICAD), KC_LALT,            KC_BSPC,  KC_SPC, KC_ENT \
  ),

  [_FUSION] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI, TG(_FUSION), KC_LALT,             KC_BSPC,  KC_SPC, KC_ENT \
  ),

  [_ALPHA] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MINS, \
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    \
    KC_LCTL, KC_LGUI, TG(_ALPHA), KC_LALT,            KC_BSPC,  KC_SPC, KC_ENT \
  ),
};
