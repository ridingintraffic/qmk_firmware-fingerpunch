#pragma once
#include "sadekbaroudi.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung39))
#    define LAYOUT LAYOUT_reviung39
#endif

// Since Reviung41 uses the name LAYOUT_reviung41 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung41))
#    define LAYOUT LAYOUT_reviung41
#endif

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_5x12))
#    define LAYOUT LAYOUT_ortho_5x12
#endif

// Since enigma36 uses the name LAYOUT_enigma36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_enigma36))
#    define LAYOUT LAYOUT_enigma36
#endif

// Since Euclid36 uses the name LAYOUT_euclid36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36))
#    define LAYOUT LAYOUT_euclid36
#endif

// Since euclid36proto uses the name LAYOUT_euclid36proto instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36proto))
#    define LAYOUT LAYOUT_euclid36proto
#endif

// Since pteron38 uses the name LAYOUT_pteron38 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_pteron38))
#    define LAYOUT LAYOUT_pteron38
#endif

// Since barobordhw uses the name LAYOUT_barobordhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobordhw))
#    define LAYOUT LAYOUT_barobordhw
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobord))
#    define LAYOUT LAYOUT_barobord
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_4x12))
#    define LAYOUT LAYOUT_ortho_4x12
#endif

// Since ffkbhw uses the name LAYOUT_ffkbhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkbhw))
#    define LAYOUT LAYOUT_ffkbhw
#endif

// Since ffkbhw uses the name LAYOUT_ffkb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkb))
#    define LAYOUT LAYOUT_ffkb
#endif

// Since bgkeeb uses the name LAYOUT_bgkeeb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_bgkeeb))
#    define LAYOUT LAYOUT_bgkeeb
#endif

// Since absolem uses the name LAYOUT_absolem instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_absolem))
#    define LAYOUT LAYOUT_absolem
#endif


// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)        LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_pteron38_wrapper(...)         LAYOUT_pteron38(__VA_ARGS__)
#define LAYOUT_ffkbhw_wrapper(...)           LAYOUT_ffkbhw(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/


// QWERTY
#define _________________QWERTY_L1_________________			KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________			KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________			KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________			KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________			KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________			KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

// COLEMAK
#define ______________COLEMAK_MOD_DH_L1____________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________			KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________			KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

// ISRT
#define _________________ISRT_L1________________			  KC_Y,    KC_C,    KC_L,   KC_M,     KC_K
#define _________________ISRT_L2________________			  KC_I,    KC_S,    KC_R,   KC_T,     KC_G
#define _________________ISRT_L3________________			  KC_Q,    KC_V,    KC_W,   KC_D,     KC_J

#define _________________ISRT_R1________________			  KC_Z,    KC_F,    KC_U,    KC_COMM, KC_SCLN
#define _________________ISRT_R2________________			  KC_P,    KC_N,    KC_E,    KC_A,    KC_O
#define _________________ISRT_R3________________			  KC_B,    KC_H,    KC_SLSH, KC_DOT,  KC_X

// BLANK FULL LINE
#define ___________________BLANK___________________			_______, _______, _______, _______, _______

// NAVIGATION

#define __META_NAV_1_K1__ KC_ESC
#define __META_NAV_1_K2__ KC_PGUP
#define __META_NAV_1_K3__ KC_UP
#define __META_NAV_1_K4__ KC_PGDN
#define __META_NAV_1_K5__ _______

#define __META_NAV_2_K1__ KC_HOME
#define __META_NAV_2_K2__ KC_LEFT
#define __META_NAV_2_K3__ KC_DOWN
#define __META_NAV_2_K4__ KC_RGHT
#define __META_NAV_2_K5__ KC_END

#define _________________META_NAV_1________________     __META_NAV_1_K1__, __META_NAV_1_K2__, __META_NAV_1_K3__, __META_NAV_1_K4__, __META_NAV_1_K5__
#define _________________META_NAV_2________________     __META_NAV_2_K1__, __META_NAV_2_K2__, __META_NAV_2_K3__, __META_NAV_2_K4__, __META_NAV_2_K5__

#define __NAV_3_K1__ LCTL(KC_Z)
#define __NAV_3_K2__ LCTL(KC_X)
#define __NAV_3_K3__ LCTL(KC_C)
#define __NAV_3_K4__ _______
#define __NAV_3_K5__ LCTL(KC_V)

#define ________________NAVIGATION_1_______________			_________________META_NAV_1________________
#define ________________NAVIGATION_2_______________			_________________META_NAV_2________________
#define ________________NAVIGATION_3_______________			__NAV_3_K1__, __NAV_3_K2__, __NAV_3_K3__, __NAV_3_K4__, __NAV_3_K5__

#define __NUMPAD_1_K1__ KC_ASTR
#define __NUMPAD_1_K2__ KC_7
#define __NUMPAD_1_K3__ KC_8
#define __NUMPAD_1_K4__ KC_9
#define __NUMPAD_1_K5__ KC_MINS

#define __NUMPAD_2_K1__ KC_SLSH
#define __NUMPAD_2_K2__ KC_4
#define __NUMPAD_2_K3__ KC_5
#define __NUMPAD_2_K4__ KC_6
#define __NUMPAD_2_K5__ KC_PLUS

#define __NUMPAD_3_K1__ KC_EQL
#define __NUMPAD_3_K2__ KC_1
#define __NUMPAD_3_K3__ KC_2
#define __NUMPAD_3_K4__ KC_3
#define __NUMPAD_3_K5__ KC_0

#define _________________NUMPAD_1__________________			__NUMPAD_1_K1__, __NUMPAD_1_K2__, __NUMPAD_1_K3__, __NUMPAD_1_K4__, __NUMPAD_1_K5__
#define _________________NUMPAD_2__________________			__NUMPAD_2_K1__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__, __NUMPAD_2_K5__
#define _________________NUMPAD_3__________________			__NUMPAD_3_K1__, __NUMPAD_3_K2__, __NUMPAD_3_K3__, __NUMPAD_3_K4__, __NUMPAD_3_K5__

// SYMBOLS

#define __SYMBOLS_L1_K1__ KC_EXLM
#define __SYMBOLS_L1_K2__ KC_AT
#define __SYMBOLS_L1_K3__ KC_HASH
#define __SYMBOLS_L1_K4__ KC_DLR
#define __SYMBOLS_L1_K5__ KC_PERC

#define __SYMBOLS_L2_K1__ KC_MINS
#define __SYMBOLS_L2_K2__ KC_LBRC
#define __SYMBOLS_L2_K3__ KC_LCBR
#define __SYMBOLS_L2_K4__ KC_LPRN
#define __SYMBOLS_L2_K5__ KC_LT

#define __META_NAV_L1_K1__ KC_CAPS
#define __META_NAV_L1_K2__ KC_GRV
#define __META_NAV_L1_K3__ LCTL(LSFT(KC_TAB))
#define __META_NAV_L1_K4__ LCTL(LGUI(KC_LEFT))
#define __META_NAV_L1_K5__ C_CAPSWORD

#define __SYMBOLS_R1_K1__ KC_CIRC
#define __SYMBOLS_R1_K2__ KC_AMPR
#define __SYMBOLS_R1_K3__ KC_ASTR
#define __SYMBOLS_R1_K4__ KC_UNDS
#define __SYMBOLS_R1_K5__ KC_EQL

#define __SYMBOLS_R2_K1__ KC_GT
#define __SYMBOLS_R2_K2__ KC_RPRN
#define __SYMBOLS_R2_K3__ KC_RCBR
#define __SYMBOLS_R2_K4__ KC_RBRC
#define __SYMBOLS_R2_K5__ KC_PLUS

#define __META_NAV_L2_K1__ C_UNDERSCORECASE
#define __META_NAV_L2_K2__ LCTL(LGUI(KC_RIGHT))
#define __META_NAV_L2_K3__ LCTL(KC_TAB)
#define __META_NAV_L2_K4__ C_ANYCASE
#define __META_NAV_L2_K5__ KC_BSLS


#define _________________META_NAV_L1_______________     __META_NAV_L1_K1__, __META_NAV_L1_K2__, __META_NAV_L1_K3__, __META_NAV_L1_K4__, __META_NAV_L1_K5__
#define _________________META_NAV_R1_______________     __META_NAV_L2_K1__, __META_NAV_L2_K2__, __META_NAV_L2_K3__, __META_NAV_L2_K4__, __META_NAV_L2_K5__

#define ________________SYMBOLS_L1_________________			__SYMBOLS_L1_K1__, __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__, __SYMBOLS_L1_K5__
#define ________________SYMBOLS_L2_________________			__SYMBOLS_L2_K1__, __SYMBOLS_L2_K2__, __SYMBOLS_L2_K3__, __SYMBOLS_L2_K4__, __SYMBOLS_L2_K5__
#define ________________SYMBOLS_L3_________________			_________________META_NAV_L1_______________

#define ________________SYMBOLS_R1_________________			__SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__, __SYMBOLS_R1_K5__
#define ________________SYMBOLS_R2_________________			__SYMBOLS_R2_K1__, __SYMBOLS_R2_K2__, __SYMBOLS_R2_K3__, __SYMBOLS_R2_K4__, __SYMBOLS_R2_K5__
#define ________________SYMBOLS_R3_________________			_________________META_NAV_R1_______________

// SHIFT NAVIGATION LAYER

#define __SHIFTNAV_1_K1__ _______
#define __SHIFTNAV_1_K2__ LSFT(KC_PGUP)
#define __SHIFTNAV_1_K3__ LSFT(KC_UP)
#define __SHIFTNAV_1_K4__ LSFT(KC_PGDN)
#define __SHIFTNAV_1_K5__ _______

#define __SHIFTNAV_2_K1__ LSFT(KC_HOME)
#define __SHIFTNAV_2_K2__ LSFT(KC_LEFT)
#define __SHIFTNAV_2_K3__ LSFT(KC_DOWN)
#define __SHIFTNAV_2_K4__ LSFT(KC_RGHT)
#define __SHIFTNAV_2_K5__ LSFT(KC_END)

#define __SHIFTNAV_3_K1__ LCTL(KC_Z)
#define __SHIFTNAV_3_K2__ LCTL(KC_X)
#define __SHIFTNAV_3_K3__ LCTL(KC_C)
#define __SHIFTNAV_3_K4__ KC_MUTE
#define __SHIFTNAV_3_K5__ LCTL(KC_V)

#define ________________SHIFTNAV_1_________________			__SHIFTNAV_1_K1__, __SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__, __SHIFTNAV_1_K4__, __SHIFTNAV_1_K5__
#define ________________SHIFTNAV_2_________________			__SHIFTNAV_2_K1__, __SHIFTNAV_2_K2__, __SHIFTNAV_2_K3__, __SHIFTNAV_2_K4__, __SHIFTNAV_2_K5__
#define ________________SHIFTNAV_3_________________			__SHIFTNAV_3_K1__, __SHIFTNAV_3_K2__, __SHIFTNAV_3_K3__, __SHIFTNAV_3_K4__, __SHIFTNAV_3_K5__

#define __FUNCION_1_K1__ KC_MPLY
#define __FUNCION_1_K2__ KC_F7
#define __FUNCION_1_K3__ KC_F8
#define __FUNCION_1_K4__ KC_F9
#define __FUNCION_1_K5__ KC_F10

#define __FUNCION_2_K1__ KC_VOLU
#define __FUNCION_2_K2__ KC_F4
#define __FUNCION_2_K3__ KC_F5
#define __FUNCION_2_K4__ KC_F6
#define __FUNCION_2_K5__ KC_F11

#define __FUNCION_3_K1__ KC_VOLD
#define __FUNCION_3_K2__ KC_F1
#define __FUNCION_3_K3__ KC_F2
#define __FUNCION_3_K4__ KC_F3
#define __FUNCION_3_K5__ KC_F12

#define ________________FUNCTION_1_________________			__FUNCION_1_K1__, __FUNCION_1_K2__, __FUNCION_1_K3__, __FUNCION_1_K4__, __FUNCION_1_K5__
#define ________________FUNCTION_2_________________			__FUNCION_2_K1__, __FUNCION_2_K2__, __FUNCION_2_K3__, __FUNCION_2_K4__, __FUNCION_2_K5__
#define ________________FUNCTION_3_________________			__FUNCION_3_K1__, __FUNCION_3_K2__, __FUNCION_3_K3__, __FUNCION_3_K4__, __FUNCION_3_K5__

// MEDIA LAYER

#define __RGB_1_K1__ RGB_TOG
#define __RGB_1_K2__ RGB_MODE_REVERSE
#define __RGB_1_K3__ RGB_MODE_FORWARD
#define __RGB_1_K4__ _______
#define __RGB_1_K5__ TG(_QWERTY)

#define __RGB_2_K1__ KC_RGB_BLT
#define __RGB_2_K2__ RGB_HUI
#define __RGB_2_K3__ RGB_SAI
#define __RGB_2_K4__ RGB_VAI
#define __RGB_2_K5__ TG(_COLEMAK)

#define __RGB_3_K1__ KC_RGB_T
#define __RGB_3_K2__ RGB_HUD
#define __RGB_3_K3__ RGB_SAD
#define __RGB_3_K4__ RGB_VAD
#define __RGB_3_K5__ TG(_ISRT)

#define ___________________RGB_1___________________			__RGB_1_K1__, __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__, __RGB_1_K5__
#define ___________________RGB_2___________________			__RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__
#define ___________________RGB_3___________________			__RGB_3_K1__, __RGB_3_K2__, __RGB_3_K3__, __RGB_3_K4__, __RGB_3_K5__

#define __MACROS_1_K1__ RGB_SPI
#define __MACROS_1_K2__ L_FIND
#define __MACROS_1_K3__ L_GITCOMMIT
#define __MACROS_1_K4__ _______
#define __MACROS_1_K5__ E_ROBOT

#define __MACROS_2_K1__ P_ANGBRKT
#define __MACROS_2_K2__ P_PAREN
#define __MACROS_2_K3__ P_CURLY
#define __MACROS_2_K4__ P_BRKT
#define __MACROS_2_K5__ P_ARROW

#define __MACROS_3_K1__ RGB_SPD
#define __MACROS_3_K2__ L_GREP
#define __MACROS_3_K3__ _______
#define __MACROS_3_K4__ _______
#define __MACROS_3_K5__ E_CAT

// // UNCOMMENT TO DISABLE MACROS
// #define _________________MACROS_1__________________			___________________BLANK___________________
// #define _________________MACROS_2__________________			___________________BLANK___________________
// #define _________________MACROS_3__________________			___________________BLANK___________________

// COMMENT TO DISABLE MACROS
#define _________________MACROS_1__________________			__MACROS_1_K1__, __MACROS_1_K2__, __MACROS_1_K3__, __MACROS_1_K4__, __MACROS_1_K5__
#define _________________MACROS_2__________________			__MACROS_2_K1__, __MACROS_2_K2__, __MACROS_2_K3__, __MACROS_2_K4__, __MACROS_2_K5__
#define _________________MACROS_3__________________			__MACROS_3_K1__, __MACROS_3_K2__, __MACROS_3_K3__, __MACROS_3_K4__, __MACROS_3_K5__

// MOUSE LAYER

#define __MOUSE_1_K1__ RESET
#define __MOUSE_1_K2__ KC_MS_WH_UP
#define __MOUSE_1_K3__ KC_MS_UP
#define __MOUSE_1_K4__ KC_MS_WH_DOWN
#define __MOUSE_1_K5__ _______

#define __MOUSE_2_K1__ KC_MS_WH_LEFT
#define __MOUSE_2_K2__ KC_MS_LEFT
#define __MOUSE_2_K3__ KC_MS_DOWN
#define __MOUSE_2_K4__ KC_MS_RIGHT
#define __MOUSE_2_K5__ KC_MS_WH_RIGHT

#define __MOUSE_3_K1__ KC_MS_ACCEL0
#define __MOUSE_3_K2__ KC_MS_ACCEL1
#define __MOUSE_3_K3__ KC_MS_ACCEL2
#define __MOUSE_3_K4__ _______
#define __MOUSE_3_K5__ _______

#define __________________MOUSE_1__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_2__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_3__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__


// WIN NAVIGATION

#define __WIN_NAV_1_K1__ _______
#define __WIN_NAV_1_K2__ _______
#define __WIN_NAV_1_K3__ LGUI(KC_UP)
#define __WIN_NAV_1_K4__ _______
#define __WIN_NAV_1_K5__ _______

#define __WIN_NAV_2_K1__ _______
#define __WIN_NAV_2_K2__ LGUI(KC_LEFT)
#define __WIN_NAV_2_K3__ LGUI(KC_DOWN)
#define __WIN_NAV_2_K4__ LGUI(KC_RGHT)
#define __WIN_NAV_2_K5__ _______

#define __________________WIN_NAV_1________________     __WIN_NAV_1_K1__, __WIN_NAV_1_K2__, __WIN_NAV_1_K3__, __WIN_NAV_1_K4__, __WIN_NAV_1_K5__
#define __________________WIN_NAV_2________________     __WIN_NAV_2_K1__, __WIN_NAV_2_K2__, __WIN_NAV_2_K3__, __WIN_NAV_2_K4__, __WIN_NAV_2_K5__

// clang-format on
