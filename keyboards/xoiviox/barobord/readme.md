# barobord

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Barobord supports vial! Build the via keymap as shown in the commands, and then use Vial to sideload via.json

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make xoiviox/barobord/ec11:via
    make xoiviox/barobord/evq:via
    make xoiviox/barobord/no-features:via
    make xoiviox/barobord/oled:via
    make xoiviox/barobord/oled-ec11:via
    make xoiviox/barobord/oled-evq:via
    make xoiviox/barobord/pimoroni:via
    make xoiviox/barobord/pimoroni-ec11:via
    make xoiviox/barobord/pimoroni-evq:via
    make xoiviox/barobord/readme.md:via
    make xoiviox/barobord/rgblight:via
    make xoiviox/barobord/rgblight-oled-ec11:via
    make xoiviox/barobord/rgblight-oled-evq:via
    make xoiviox/barobord/rgblight-pimoroni-ec11:via
    make xoiviox/barobord/rgblight-pimoroni-evq:via
    make xoiviox/barobord/rgbmatrix:via
    make xoiviox/barobord/rgbmatrix-oled-ec11:via
    make xoiviox/barobord/rgbmatrix-oled-evq:via
    make xoiviox/barobord/rgbmatrix-pimoroni-ec11:via
    make xoiviox/barobord/rgbmatrix-pimoroni-evq:via

Example of flashing this keyboard:

    make xoiviox/barobord/no-features:via:flash


Once you have completed the build, flash it onto your keyboard. At this point, make sure you have [Vial](https://get.vial.today/) installed. Use the "Sideload VIA JSON" and use the via.json found in this directory. You should be able to edit your keymap directly from your machine!

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
