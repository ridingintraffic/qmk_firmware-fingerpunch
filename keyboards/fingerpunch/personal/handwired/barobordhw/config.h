/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "config_common.h"


/* USB Device descriptor parameter */
#define DEVICE_VER      0x0001
#define VENDOR_ID       0xFEFE
#define PRODUCT_ID      0xBB00
#define MANUFACTURER    sadekbaroudi
#define PRODUCT         barobordhw

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

// wiring
#define MATRIX_ROW_PINS { D0, D4, F6, F5 }
#define MATRIX_COL_PINS { F7, B1, B3, B2, B6, C6, D7, E6, B4, B5 }
#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

// Use twinkle as the default rgb mode for the layers
//#define DEFAULT_RGB_LAYER_MODE RGBLIGHT_MODE_TWINKLE+2

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 40
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
//   /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
//   /*==== use exp() and sin() ====*/
//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

#ifdef RGB_MATRIX_ENABLE
  #define DRIVER_LED_TOTAL 40
  #define RGB_MATRIX_CENTER {100, 32}
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 112  /* The maximum brightness level for RGB_MATRIX */
  #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_KEYREACTIVE_ENABLED
  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  // #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  // #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  #define ENABLE_RGB_MATRIX_BAND_VAL
  // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  // #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  // #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define ENABLE_RGB_MATRIX_DUAL_BEACON
  // #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  // #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  // #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  // #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_RAINDROPS
  #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  // #define ENABLE_RGB_MATRIX_SPLASH
  // #define ENABLE_RGB_MATRIX_MULTISPLASH
  // #define ENABLE_RGB_MATRIX_SOLID_SPLASH
  // #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
