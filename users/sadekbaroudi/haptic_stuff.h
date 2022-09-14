#pragma once
#include "quantum.h"

layer_state_t layer_state_set_haptic(layer_state_t state);
bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record);