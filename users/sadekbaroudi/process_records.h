#pragma once
#include "sadekbaroudi.h"

#if defined(KEYBOARD_fingerpunch_arachnophobe) \
    || defined(KEYBOARD_fingerpunch_barobord) \
    || defined(KEYBOARD_fingerpunch_barobord_byomcu) \
    || defined(KEYBOARD_fingerpunch_bgkeeb) \
    || defined(KEYBOARD_fingerpunch_bigbarobord) \
    || defined(KEYBOARD_fingerpunch_euclid36) \
    || defined(KEYBOARD_fingerpunch_euclid36_proto) \
    || defined(KEYBOARD_fingerpunch_ffkb) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v2) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v3) \
    || defined(KEYBOARD_fingerpunch_luakeeb) \
    || defined(KEYBOARD_fingerpunch_pinkiesout) \
    || defined(KEYBOARD_fingerpunch_rockon_v1) \
    || defined(KEYBOARD_fingerpunch_rockon_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_v3) \
    || defined(KEYBOARD_fingerpunch_rockon_bp) \
    || defined(KEYBOARD_fingerpunch_sweeeeep) \
    || defined(KEYBOARD_fingerpunch_ximi) \
    || defined(KEYBOARD_fingerpunch_personal_badwings)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#elif defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    KC_RGB_BLT,                     // Toggles RGB Base Layer Override mode
    RGB_IDL,                        // RGB Idling animations
    KC_MAKE,                        // Run keyboard's customized make command
    L_GREP,
    L_FIND,
    L_GITCOMMIT,
    N_DEL_LINE,
    N_SEL_LINE,
    S_ALT_TAB,
    P_ANGBRKT,
    P_PAREN,
    P_CURLY,
    P_BRKT,
    P_ARROW,
    E_ROBOT,
    E_CAT,
    C_CAPSWORD,
    C_HYPHENCASE,
    C_UNDERSCORECASE,
    C_ANYCASE,
    G_GOD_ON,
    G_GOD_OFF,
    G_PULLING,
    G_PUSH,
    NEW_SAFE_RANGE
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
#if defined(MOUSEKEY_ENABLE) || defined(POINTING_DEVICE_ENABLE)
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report);
#endif

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define KC_RESET RESET
#define KC_RST   KC_RESET
