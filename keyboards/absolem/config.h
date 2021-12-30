/* Copyright 2020 Sadek Baroudi
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1777
#define PRODUCT_ID      0x8577
#define DEVICE_VER      0x0001
#define MANUFACTURER    mrzealot
#define PRODUCT         absolem

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, B1, B2, B6, D1, D7, B5, F6 }
#define MATRIX_COL_PINS { D4, C6, E6, B4, D3 }
// #define UNUSED_PINS     { D7, F4, D3 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5  /* 5 is default */
