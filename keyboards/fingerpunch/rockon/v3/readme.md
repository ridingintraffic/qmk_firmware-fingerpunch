# rockon

An ergonomic 70% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:
```
    make fingerpunch/rockon/v3:default RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes CIRQUE_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    CIRQUE_ENABLE=yes
    FP_TRACKBALL_ENABLE=yes
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=yes
    ENCODER_ENABLE=yes
```

Example of flashing this keyboard:
```
    make fingerpunch/rockon/v3:default:flash RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes CIRQUE_ENABLE=yes
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
