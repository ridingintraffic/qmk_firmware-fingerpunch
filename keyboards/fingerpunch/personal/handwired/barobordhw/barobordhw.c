/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
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
#include "barobordhw.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 39,33,32,26,25,14,13,7, 6, 0},
    { 38,34,31,27,24,15,12,8 ,5, 1},
    { 37,35,30,28,23,16,11,9 ,4 ,2},
    { 36,29,22,21,20,19,18,17,10,3}
}, {
    {184,8},  {192,16}, {200,24}, {188,32}, {180,16}, {172,8},  {164,0},  {144,0},  {152,8},  {160,24},
    {168,32}, {144,32}, {136,6},  {128,8},  {112,16}, {120,24}, {128,48}, {160,48}, {136,56}, {120,64},
    {80,64},  {64,56},  {40,48},  {72,48},  {80,24},  {88,16},  {72,8},   {64,16},  {56,32},  {32,32},
    {40,24},  {48,8},   {56,0},   {36,0},   {28,8},   {20,16},  {12,32},  {0,24},   {8,16},   {16,8}
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif