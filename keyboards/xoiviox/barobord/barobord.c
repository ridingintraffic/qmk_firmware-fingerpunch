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
#include "barobord.h"
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 0, 6, 7,13,14,25,26,32,33,39},
    { 1, 5, 8,12,15,24,27,31,34,38},
    { 2, 4, 9,11,16,23,28,30,35,37},
    { 3,10,17,18,19,20,21,22,29,36}
}, {
    {1,1},  {1,2},  {0,3},  {1,4},  {2,2},  {2,1},  {3,0},  {5,0},  {4,1},  {2,3},
    {4,4},  {5,4},  {6,2},  {6,1},  {7,2},  {7,3},  {6,6},  {4,6},  {5,7},  {6,8},
    {11,8}, {12,7}, {13,6}, {11,6}, {10,3}, {10,2}, {11,1}, {11,2}, {12,4}, {13,4},
    {15,3}, {13,1}, {12,0}, {14,0}, {15,1}, {15,2}, {16,4}, {17,3}, {16,2}, {16,1}
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif


