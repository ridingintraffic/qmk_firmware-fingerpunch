# pinkiesout

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Pinkies Out supports vial! If you want to use Vial, go to https://github.com/sadekbaroudi/vial-qmk/keyboards/xoiviox/pinkiesout/

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make xoiviox/pinkiesout/no-features:default
    make xoiviox/pinkiesout/oled:default
    make xoiviox/pinkiesout/rgblight:default
    make xoiviox/pinkiesout/rgblight-oled:default
    make xoiviox/pinkiesout/rgbmatrix:default
    make xoiviox/pinkiesout/rgbmatrix-oled:default

If using the vial repository, use these:
    make xoiviox/pinkiesout/no-features:vial
    make xoiviox/pinkiesout/oled:vial
    make xoiviox/pinkiesout/rgblight:vial
    make xoiviox/pinkiesout/rgblight-oled:vial
    make xoiviox/pinkiesout/rgbmatrix:vial
    make xoiviox/pinkiesout/rgbmatrix-oled:vial

Example of flashing this keyboard:

    make xoiviox/pinkiesout/no-features:default:flash

Or in the vial repository:

    make xoiviox/pinkiesout/no-features:vial:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
