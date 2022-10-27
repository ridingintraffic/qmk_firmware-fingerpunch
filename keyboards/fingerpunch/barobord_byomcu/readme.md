# barobord

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Barobord supports vial! Build the via keymap as shown in the commands

To build the firmware for this keyboard (after setting up your build environment):
```
    make fingerpunch/barobord_byomcu:default RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes PIMORONI_TRACKBALL_ENABLE=yes
```

Options are:
```
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=yes
    OLED_ENABLE=yes
    ENCODER_ENABLE=yes
    PIMORONI_TRACKBALL_ENABLE=yes
```


Once you have completed the build, flash it onto your keyboard. At this point, make sure you have [Vial](https://get.vial.today/) installed. You should be able to edit your keymap directly from your machine!

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
