/* Copyright 2022 Sadek Baroudi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.j
 */

#pragma once

#include QMK_KEYBOARD_H

#include "eeprom.h"

bool fp_caps_lock_get(void);
void fp_caps_lock_toggle(void);
void handle_caps_lock_change(void);
void press_super_tab(bool shift);

#include "keyboards/fingerpunch/fp_color.h"
#include "keyboards/fingerpunch/fp_keyhandler.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "keyboards/fingerpunch/fp_rgb_common.h"
#endif
#ifdef RGBLIGHT_ENABLE
#    include "keyboards/fingerpunch/fp_rgblight.h"
#endif
#ifdef RGB_MATRIX_ENABLE
#    include "keyboards/fingerpunch/fp_rgb_matrix.h"
#endif
#ifdef HAPTIC_ENABLE
#    include "keyboards/fingerpunch/fp_haptic.h"
#endif
#ifdef POINTING_DEVICE_ENABLE
#    include "keyboards/fingerpunch/fp_pointing.h"
#endif

// clang-format off
typedef union {
    uint32_t raw;
    struct {
        uint8_t rgb_mode;
        uint8_t rgb_hue;
        uint8_t rgb_sat;
        uint8_t rgb_val;
        uint8_t rgb_speed;
    };
} fp_config_t;
// clang-format on

extern fp_config_t fp_config;
