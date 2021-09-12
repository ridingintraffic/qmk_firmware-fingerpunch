#pragma once

#define MASTER_LEFT

#define USE_SERIAL

#define RGB_DI_PIN B3

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 18 // Number of LEDs
#    define RGBLED_SPLIT \
        { 9, 9 }
#    define RGBLIGHT_SPLIT
#endif