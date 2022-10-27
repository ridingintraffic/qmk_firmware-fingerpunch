#include "sadekbaroudi.h"
#include "casemodes.h"
#if defined(USERSPACE_RGBLIGHT_ENABLE)
#include "rgb_stuff.h"
#endif
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in sadekbaroudi.h file
// Then runs the _keymap's record handler if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CASEMODES_ENABLE
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    // If console is enabled, it will print the matrix position and status of each key pressed
    #endif
#ifdef KEYLOGGER_ENABLE
#    if defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_keebio_iris_rev2)
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed);
#    else
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#    endif
#endif  // KEYLOGGER_ENABLE

    if (!(process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
// #ifdef RGB_MATRIX_ENABLE
//         && process_record_user_rgb_matrix(keycode, record)
// #endif
#ifdef USERSPACE_RGBLIGHT_ENABLE
        && process_record_user_rgb_light(keycode, record)
#endif
    && true)) {
        return false;
    }

    switch (keycode) {
        // COMMENT TO DISABLE MACROS
        case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed) {
#ifndef MAKE_BOOTLOADER
                uint8_t temp_mod = mod_config(get_mods());
                uint8_t temp_osm = mod_config(get_oneshot_mods());
                clear_mods();
                clear_oneshot_mods();
#endif
                send_string_with_delay_P(PSTR("qmk"), TAP_CODE_DELAY);
#ifndef MAKE_BOOTLOADER
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
                {
                    send_string_with_delay_P(PSTR(" flash "), TAP_CODE_DELAY);
#ifndef MAKE_BOOTLOADER
                } else {
                    send_string_with_delay_P(PSTR(" compile "), TAP_CODE_DELAY);
#endif
                }
                send_string_with_delay_P(PSTR("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
#ifdef RGB_MATRIX_SPLIT_RIGHT
                send_string_with_delay_P(PSTR(" RGB_MATRIX_SPLIT_RIGHT=yes"), TAP_CODE_DELAY);
#    ifndef OLED_DRIVER_ENABLE
                send_string_with_delay_P(PSTR(" OLED_DRIVER_ENABLE=no"), TAP_CODE_DELAY);
#    endif
#endif
                send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
            }

            break;
        // COMMENT TO DISABLE MACROS
        case VRSN:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            break;

        case KC_RGB_T:  // This allows me to use underglow as layer indication, or as normal
#if defined(USERSPACE_RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                userspace_config.rgb_layer_change ^= 1;
                xprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                eeconfig_update_user(userspace_config.raw);
                if (userspace_config.rgb_layer_change) {
// #    if defined(USERSPACE_RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
//                     USERSPACE_RGBLIGHT_ENABLE_noeeprom();
// #    endif
                    layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
                } else {
// #    if defined(USERSPACE_RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
//                     rgblight_disable_noeeprom();
// #    endif
#    if defined(USERSPACE_RGBLIGHT_ENABLE)
                    rgblight_set_hsv_and_mode(userspace_config.hue, userspace_config.sat, userspace_config.val, userspace_config.mode);
#    endif
                    ;
                }
            }
#endif  // USERSPACE_RGBLIGHT_ENABLE
            break;
        case KC_RGB_BLT:  // This enables the base layer as a static color, or allows you to override using RGB
#if defined(USERSPACE_RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                userspace_config.rgb_base_layer_override ^= 1;
                xprintf("rgblight base layer override change [EEPROM]: %u\n", userspace_config.rgb_base_layer_override);
                eeconfig_update_user(userspace_config.raw);
                if (userspace_config.rgb_base_layer_override) {
// #    if defined(USERSPACE_RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
//                     USERSPACE_RGBLIGHT_ENABLE_noeeprom();
// #    endif
                    layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
// #    if defined(USERSPACE_RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
//                 } else {
//                     rgblight_disable_noeeprom();
// #    endif
                }
            }
#endif  // USERSPACE_RGBLIGHT_ENABLE
            break;

#if defined(USERSPACE_RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_TOG:
            // Split keyboards need to trigger on key-up for edge-case issue
#    ifndef SPLIT_KEYBOARD
            if (record->event.pressed) {
#    else
            if (!record->event.pressed) {
#    endif
#    if defined(USERSPACE_RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgblight_toggle();
#    endif
// #    if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
//                 rgb_matrix_toggle();
// #    endif
            }
            return false;
            break;
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
            if (record->event.pressed) {
                xprintf("RGB: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
                bool is_eeprom_updated = false;

                if (userspace_config.rgb_layer_change) {
#    if defined(USERSPACE_RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    // For some reason, this breaks setting base layer colors on the draculad, need to comment this line out
                    rgblight_set_hsv_and_mode(userspace_config.hue, userspace_config.sat, userspace_config.val, userspace_config.mode);
#    endif
                }

// #    if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
//                 if (userspace_config.rgb_matrix_idle_anim) {
//                     userspace_config.rgb_matrix_idle_anim = false;
//                     xprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb_matrix_idle_anim);
//                     is_eeprom_updated = true;
//                 }
// #    endif
                if (is_eeprom_updated) {
                    eeconfig_update_user(userspace_config.raw);
                }
            }
            if (!record->event.pressed) {
#    if defined(USERSPACE_RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgb_set_user_config_from_current_values();
#    endif
            }
            break;
#endif
        case C_CAPSWORD:
            // NOTE: if you change this behavior, may want to update in keymap.c for COMBO behavior
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_caps_word();
            }
            #endif
            break;
        case C_HYPHENCASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            #endif
            break;
        case C_ANYCASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase();
            }
            #endif
            break;
        case C_UNDERSCORECASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            #endif
            break;
        // COMMENT TO DISABLE MACROS
        case L_GREP:
            if (record->event.pressed) {
                SEND_STRING("grep -rn \"");
            } else {
                // when keycode is released
            }
            break;
        case L_FIND:
            if (record->event.pressed) {
                SEND_STRING("find . -name \"");
            } else {
                // when keycode is released
            }
            break;
        case L_GITCOMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -a -m \"\""SS_TAP(X_LEFT));
            } else {
                // when keycode is released
            }
            break;
        case N_DEL_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END));
                register_code(KC_LSHIFT);
                SEND_STRING(SS_TAP(X_HOME));
                unregister_code(KC_LSHIFT);
            } else {
                // when keycode is released
            }
            break;
        case N_SEL_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END));
                register_code(KC_LSHIFT);
                SEND_STRING(SS_TAP(X_HOME));
                unregister_code(KC_LSHIFT);
            }
            break;
        case P_ANGBRKT:
            if (record->event.pressed) {
                SEND_STRING("<>"SS_TAP(X_LEFT));
            } else {
                // when keycode is released
            }
            break;
        case P_PAREN:
            if (record->event.pressed) {
                SEND_STRING("()"SS_TAP(X_LEFT));
            } else {
                // when keycode is released
            }
            break;
        case P_CURLY:
            if (record->event.pressed) {
                SEND_STRING("{}"SS_TAP(X_LEFT));
            } else {
                // when keycode is released
            }
            break;
        case P_BRKT:
            if (record->event.pressed) {
                SEND_STRING("[]"SS_TAP(X_LEFT));
            } else {
                // when keycode is released
            }
            break;
        case P_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            } else {
                // when keycode is released
            }
            break;
        case E_ROBOT:
            if (record->event.pressed) {
                SEND_STRING("d[o_0]b");
            } else {
                // when keycode is released
            }
            break;
        case E_CAT:
            if (record->event.pressed) {
                SEND_STRING("=^..^=");
            } else {
                // when keycode is released
            }
            break;
        case G_GOD_ON:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                SEND_STRING(SS_TAP(X_ENTER));
                unregister_code(KC_LSHIFT);
                SEND_STRING("GOD MODE ENGAGED"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_GOD_OFF:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                SEND_STRING(SS_TAP(X_ENTER));
                unregister_code(KC_LSHIFT);
                SEND_STRING("GOD MODE DISENGAGED"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_PULLING:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER)"I am pulling, play safe"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_PUSH:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER)"Push the lane out"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        // COMMENT TO DISABLE MACROS
    }
    return true;
}
