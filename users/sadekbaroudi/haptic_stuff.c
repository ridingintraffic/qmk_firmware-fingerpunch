#include "sadekbaroudi.h"
#include "haptic_stuff.h"
#include "drivers/haptic/DRV2605L.h"

layer_state_t layer_state_set_haptic(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _ALPHA_ALT:
        case _ALPHA:
#ifdef HAPTIC_ENABLE
            // DRV_pulse(soft_bump);
#endif
            break;
        case _NAVIGATION:
#ifdef HAPTIC_ENABLE
            // DRV_pulse(sh_dblsharp_tick);
#endif
            break;
        case _SYMBOLS:
#ifdef HAPTIC_ENABLE
            // DRV_pulse(lg_dblclick_str);
#endif
            break;
        case _FUNCTION:
#ifdef HAPTIC_ENABLE
            // DRV_pulse(pulsing_sharp);
#endif
            break;
        case _MEDIA:
#ifdef HAPTIC_ENABLE
            // DRV_pulse(transition_rampup_short_smooth1);
#endif
            break;
        case _MOUSE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(transition_rampdown_med_smooth1_50);
#endif
            break;
        default:
            break;
    }

    return state;
}

// manually handle haptic
bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
            break;
    }
}