# luakeeb

* Keyboard Maintainer: sadekbaroudi
* Hardware Supported: luakeeb PCB

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/luakeeb:default RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    RGBLIGHT_ENABLE=yes
    ENCODER_ENABLE=yes
```

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Build Guide

See:
https://github.com/sadekbaroudi/fingerpunch/blob/master/luakeeb/BUILDGUIDE.md

## Choosing which board to plug the USB cable into (choosing Master)

Because the two boards are identical, the firmware has logic to differentiate the left and right board. It uses two strategies to figure things out, [EE_HANDS](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom) or [by define](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-define). See [setting-handedness](https://docs.qmk.fm/#/config_options?id=setting-handedness) for more information.
