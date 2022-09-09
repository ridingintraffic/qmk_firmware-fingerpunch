/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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
#define PRODUCT_ID      0xB171
#define MANUFACTURER    sadekbaroudi
#define PRODUCT         sadekbaroudi ximi

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

#define SHIFTREG_MATRIX_COL_CS GP1
#define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
// These next two should match the MATRIX_ROWS and MATRIX_COLS if a unibody, and should be cut in half if a split keyboard
#define SHIFTREG_ROWS 3
#define SHIFTREG_COLS 8

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS_SR { GP27, GP28, GP29 }

#define SOFT_SERIAL_PIN GP0

#define USE_SERIAL

#define RGB_DI_PIN GP26
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SPLIT
  #define RGBLED_SPLIT { 21, 21 }
  #define RGBLED_NUM 42
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 120 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// cirque trackpad config
#define CIRQUE_PINNACLE_ADDR 0x2A
#define POINTING_DEVICE_TASK_THROTTLE_MS 5
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

// Trackball config
// Move into pwm3360 feature directory
#define PMW33XX_CS_PIN GP26
#define PMW33XX_CPI 800
#define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
#define POINTING_DEVICE_INVERT_Y

#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4

/* SPI config for pmw3360 sensor. */
// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN GP2
// #define SPI_SCK_PAL_MODE 5
// #define SPI_MOSI_PIN GP3
// #define SPI_MOSI_PAL_MODE 5
// #define SPI_MISO_PIN GP4
// #define SPI_MISO_PAL_MODE 5
// end Trackball config
