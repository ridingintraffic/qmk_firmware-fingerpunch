# Adding fingerpunch feature support

The purpose of this doc is mostly to make note to myself on adding the fingerpunch library support, as described in the README.md in this directory.

That said, if you are looking to leverage the features, you may be able to follow these steps for your keyboard as well. Note that this is untested.

## Required additions to the keyboard codebase

1. Add the following line to your keyboard {keyboard_name}.h file, e.g. ffkb_byomcu.h

`#include "keyboards/fingerpunch/fp.h"`

2. Include the source files in your keyboard's `rules.mk` file

Note that below is an example. You should check for the latest version of this code block as found in `keyboards/fingerpunch/ffkb_byomcu/rules.mk`

```make
DEFERRED_EXEC_ENABLE = yes
SRC +=  keyboards/fingerpunch/fp.c \
        keyboards/fingerpunch/fp_haptic.c \
        keyboards/fingerpunch/fp_keyhandler.c \
        keyboards/fingerpunch/fp_pointing.c \
        keyboards/fingerpunch/fp_rgblight.c \
        keyboards/fingerpunch/fp_rgb_matrix.c
```

## Personal notes for Sadek's keymaps

* Add the following to my keymap
    * `FP_SCROLL_TOG` (pointing)
    * `FP_SNIPE_TOG` (pointing)
    * `FP_SUPER_TAB` (replace `S_ALT_TAB` if it exists)
* Change keymap mouse layer for pointing keyboards with pointing devices
    * `__________________MOUSE_1__________________` to `_______________AUTO_MOUSE_1________________`
* Add the keyboard to my personal userspace `process_records.h` so that I can continue to use my own keycodes in addition to fingerpunch ones

```C
// Check to see which keyboard you're using, and define the PLACEHOLDER_SAFE_RANGE based on that.
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
    || defined(KEYBOARD_fingerpunch_rockon_bp) \
    || defined(KEYBOARD_fingerpunch_sweeeeep) \
    || defined(KEYBOARD_fingerpunch_ximi)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif
```
