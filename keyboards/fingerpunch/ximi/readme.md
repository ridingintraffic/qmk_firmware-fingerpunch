# ximi

* Keyboard Maintainer: sadekbaroudi
* Hardware Supported: ximi PCB

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/ximi:default RGBLIGHT_ENABLE=yes FP_CIRQUE_BOTH=yes HAPTIC_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    FP_TRACKBALL_BOTH=yes
    FP_TRACKBALL_LEFT=yes
    FP_TRACKBALL_RIGHT=yes
    FP_CIRQUE_BOTH=yes
    FP_CIRQUE_LEFT=yes
    FP_CIRQUE_RIGHT=yes
    RGBLIGHT_ENABLE=yes
    AUDIO_ENABLE=yes
    HAPTIC_FEEDBACK=yes
```

Notes:
* Pick one (or none) of FP_TRACKBALL_* only. Pick one (or none) of FP_CIRQUE_* only.
* If you are using a trackball, you cannot use per key rgb or audio. It will be automatically disabled. The hardware doesn't support them together.

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Build Guide

See:
https://github.com/sadekbaroudi/fingerpunch/blob/master/ximi/

## Choosing which board to plug the USB cable into (choosing Master)

Because the two boards are identical, the firmware has logic to differentiate the left and right board. It uses two strategies to figure things out, [EE_HANDS](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom) or [by define](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-define). See [setting-handedness](https://docs.qmk.fm/#/config_options?id=setting-handedness) for more information.
