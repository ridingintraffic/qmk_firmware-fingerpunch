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

#define MASTER_LEFT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_POINTING_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define POINTING_DEVICE_COMBINED
#define SOFT_SERIAL_PIN GP0
#define USE_SERIAL
#define SELECT_SOFT_SERIAL_SPEED 0

#define RGB_DI_PIN GP26
#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_SPLIT
#  define RGBLED_SPLIT { 21, 21 }
#  define RGBLED_NUM 42
#  define RGBLIGHT_HUE_STEP 16
#  define RGBLIGHT_SAT_STEP 16
#  define RGBLIGHT_VAL_STEP 16
#  define RGBLIGHT_LIMIT_VAL 180 /* The maximum brightness level for RGBLIGHT_ENABLE */
#  define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#endif

#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define DRIVER_LED_TOTAL 42 // Number of LEDs
#    define RGB_MATRIX_SPLIT { 21, 21 }
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#    define RGB_MATRIX_STARTUP_HUE 35
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* audio support */
// Pending https://github.com/qmk/qmk_firmware/pull/17723 and https://github.com/qmk/qmk_firmware/pull/17706
#ifdef AUDIO_ENABLE
#    define AUDIO_VOICES
#    define AUDIO_PIN GP4
#    define AUDIO_PWM_DRIVER PWMD2
#    define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_4
#    define NO_MUSIC_MODE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif 

#ifdef HAPTIC_ENABLE
#    define FB_ERM_LRA 1
#    define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 
#    define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3 
#    define RATED_VOLTAGE 2
#    define V_PEAK 2.8
#    define V_RMS 2.0
#    define F_LRA 150 // resonance freq 
#    define DRV_GREETING  alert_750ms
#    define NO_HAPTIC_ALPHA
#    define NO_HAPTIC_PUNCTUATION
#    define NO_HAPTIC_NAV
#    define NO_HAPTIC_NUMERIC
#    define NO_HAPTIC_MOD
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

// cirque trackpad config
#define CIRQUE_PINNACLE_ADDR 0x2A
#define POINTING_DEVICE_TASK_THROTTLE_MS 5
#define POINTING_DEVICE_ROTATION_90 // move to cirque specific config
#define POINTING_DEVICE_ROTATION_90_RIGHT
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

// Trackball config
// Move into pwm3360 feature directory
#define PMW33XX_CS_PIN GP26
#define PMW33XX_CPI 800
#define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
// #define POINTING_DEVICE_INVERT_Y // move to trackball specific config

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
