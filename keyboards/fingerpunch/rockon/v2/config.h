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

#define DEVICE_VER      0x0002

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 8
#define MATRIX_COLS 9

// wiring
#define MATRIX_ROW_PINS \
    { B6, F4, B5, B4, B2, B3, B7, D5 }
#define MATRIX_COL_PINS \
    { D2, D4, C6, D7, E6, F5, F6, F7, B1 }


/* encoder config */
#define ENCODERS_PAD_A {F0, C7}
#define ENCODERS_PAD_B {F1, F1}
#define ENCODER_RESOLUTION 2

#ifdef CIRQUE_ENABLE
	// cirque trackpad config
	#define CIRQUE_PINNACLE_ADDR 0x2A
	// If using fingerpunch case
	// #define POINTING_DEVICE_ROTATION_270
	// If using chewiedies case
	#define POINTING_DEVICE_ROTATION_90
	#define POINTING_DEVICE_TASK_THROTTLE_MS 5
#endif

// BEGIN PWM driver: uncomment if using STeMcell as it's a better led driver
// #define WS2812_PWM_DRIVER PWMD2  // default: PWMD2
// #define WS2812_PWM_CHANNEL 2  // default: 2
// #define WS2812_PWM_PAL_MODE 2  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.
// END PWM driver: uncomment if using STeMcell as it's a better led driver

#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#endif
