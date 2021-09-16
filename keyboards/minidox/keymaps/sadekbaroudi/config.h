#pragma once

#define MASTER_LEFT

#define USE_SERIAL

#define RGB_DI_PIN B3

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 18 // Number of LEDs
#    define RGBLED_SPLIT \
        { 9, 9 }
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_LED_MAP {6,7,8,0,1,2,3,4,5,14,13,12,11,10,9,17,16,15}
#endif