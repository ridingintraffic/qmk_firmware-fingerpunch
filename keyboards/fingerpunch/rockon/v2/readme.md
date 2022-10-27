# rockon

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Rock On supports vial! If you want to use Vial, go to https://github.com/sadekbaroudi/vial-qmk/keyboards/fingerpunch/rockon/v1/

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:
```
    make fingerpunch/rockon/v2:default RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes CIRQUE_ENABLE=yes OLED_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    CIRQUE_ENABLE=yes
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=yes
    OLED_ENABLE=yes
    ENCODER_ENABLE=yes
    PIMORONI_TRACKBALL_ENABLE=yes
```

Example of flashing this keyboard:
```
    make fingerpunch/rockon/v2:default:flash RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes CIRQUE_ENABLE=yes
```

Or in the vial repository:
```
    make fingerpunch/rockon/v2/no-features:vial:flash
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
