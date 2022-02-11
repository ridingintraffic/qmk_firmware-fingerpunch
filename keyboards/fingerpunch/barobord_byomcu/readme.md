# barobord

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Barobord supports vial! Build the via keymap as shown in the commands

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make fingerpunch/barobord_byomcu/ec11:vial
    make fingerpunch/barobord_byomcu/evq:vial
    make fingerpunch/barobord_byomcu/no-features:vial
    make fingerpunch/barobord_byomcu/oled:vial
    make fingerpunch/barobord_byomcu/oled-ec11:vial
    make fingerpunch/barobord_byomcu/oled-evq:vial
    make fingerpunch/barobord_byomcu/pimoroni:vial
    make fingerpunch/barobord_byomcu/pimoroni-ec11:vial
    make fingerpunch/barobord_byomcu/pimoroni-evq:vial
    make fingerpunch/barobord_byomcu/readme.md:vial
    make fingerpunch/barobord_byomcu/rgblight:vial
    make fingerpunch/barobord_byomcu/rgblight-oled-ec11:vial
    make fingerpunch/barobord_byomcu/rgblight-oled-evq:vial
    make fingerpunch/barobord_byomcu/rgblight-pimoroni-ec11:vial
    make fingerpunch/barobord_byomcu/rgblight-pimoroni-evq:vial
    make fingerpunch/barobord_byomcu/rgbmatrix:vial
    make fingerpunch/barobord_byomcu/rgbmatrix-oled-ec11:vial
    make fingerpunch/barobord_byomcu/rgbmatrix-oled-evq:vial
    make fingerpunch/barobord_byomcu/rgbmatrix-pimoroni-ec11:vial
    make fingerpunch/barobord_byomcu/rgbmatrix-pimoroni-evq:vial

Example of flashing this keyboard:

    make fingerpunch/barobord_byomcu/no-features:vial:flash


Once you have completed the build, flash it onto your keyboard. At this point, make sure you have [Vial](https://get.vial.today/) installed. You should be able to edit your keymap directly from your machine!

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
