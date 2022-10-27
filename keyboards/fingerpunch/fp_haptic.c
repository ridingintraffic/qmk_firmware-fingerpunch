/* Copyright 2022 Sadek Baroudi
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

#include "keyboards/fingerpunch/fp_haptic.h"

#ifdef HAPTIC_ENABLE
layer_state_t fp_layer_state_set_haptic(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            break;
    }
    return state;
}

bool fp_process_record_haptic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#       ifndef FP_DISABLE_CUSTOM_KEYCODES
        // NOTE TO SELF: IF I EVER ADD KEYCODES HERE, DETERMINE WHETHER THEY ARE CONSIDERED CUSTOM KEYCODES OR NOT
        // In the case of the mouse buttons and ctrl-x,c,v,s features below, they are treated independently, so they aren't effected by FP_DISABLE_CUSTOM_KEYCODES
#       endif // FP_DISABLE_CUSTOM_KEYCODES
#       ifdef FP_HAPTIC_MOUSE_BUTTONS
        case KC_BTN1:
            if (record->event.pressed) {
                DRV_pulse(medium_click1);
            }
            break;
        case KC_BTN2:
            if (record->event.pressed) {
                DRV_pulse(sh_dblclick_str);
            }
            break;
        case KC_BTN3:
            if (record->event.pressed) {
                DRV_pulse(medium_click1);
            }
            break;
#       endif
#       ifdef FP_HAPTIC_CUT_COPY_PASTE
        case KC_C: // copy
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if (get_mods() & MOD_MASK_CTRL) {
#               else
                if (get_mods() & MOD_MASK_GUI) {
#               endif
                    DRV_pulse(lg_dblclick_str);
                }
            }
            break;
        case KC_X: // cut
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if (get_mods() & MOD_MASK_CTRL) {
#               else
                if (get_mods() & MOD_MASK_GUI) {
#               endif
                    DRV_pulse(lg_dblclick_str);
                }
            }
            break;
        case KC_V: // paste
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if (get_mods() & MOD_MASK_CTRL) {
#               else
                if (get_mods() & MOD_MASK_GUI) {
#               endif
                    DRV_pulse(soft_bump);
                }
            }
            break;
#       endif
#       ifdef FP_HAPTIC_SAVE
        case KC_S: // save
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if (get_mods() & MOD_MASK_CTRL) {
#               else
                if (get_mods() & MOD_MASK_GUI) {
#               endif
                    DRV_pulse(pulsing_strong);
                }
            }
            break;
#endif
        default:
            break;
    }

    return true;
}
#endif
