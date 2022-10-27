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

#include "quantum.h"

#define LAYOUT_absolem( \
    K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10, \
    K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K20, \
    K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K30, \
                  K33,   K34,   K35,   K36,   K37,   K38  \
) { \
    { K01,   K02,   K03,   K04,   K05 }, \
    { K11,   K12,   K13,   K14,   K15 }, \
    { K21,   K22,   K23,   K24,   K25 }, \
    { KC_NO, KC_NO, K33,   K34,   K35 }, \
    { K10,   K09,   K08,   K07,   K06 }, \
    { K20,   K19,   K18,   K17,   K16 }, \
    { K30,   K29,   K28,   K27,   K26 }, \
    { KC_NO, KC_NO, K38,   K37,   K36 }, \
}

#include "keyboards/fingerpunch/fp.h"
