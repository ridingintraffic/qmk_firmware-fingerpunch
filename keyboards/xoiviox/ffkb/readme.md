# ffkb

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Faux fox keyboard (ffkb) supports vial!

Once you have completed the build, flash it onto your keyboard. At this point, make sure you have [Vial](https://get.vial.today/) installed. Use the "Sideload VIA JSON" and use the via.json found in this directory. You should be able to edit your keymap directly from your machine without having to re-flash it!

Make example for this keyboard (after setting up your build environment):

    make xoiviox/ffkb/ec11:via
    make xoiviox/ffkb/ec11_evq:via
    make xoiviox/ffkb/evq:via
    make xoiviox/ffkb/no_features:via
    make xoiviox/ffkb/oled:via
    make xoiviox/ffkb/oled_ec11:via
    make xoiviox/ffkb/oled_evq:via
    make xoiviox/ffkb/pimoroni:via
    make xoiviox/ffkb/pimoroni_ec11:via
    make xoiviox/ffkb/pimoroni_evq:via
    make xoiviox/ffkb/rgblight:via
    make xoiviox/ffkb/rgblight_ec11:via
    make xoiviox/ffkb/rgblight_ec11_evq:via
    make xoiviox/ffkb/rgblight_evq:via
    make xoiviox/ffkb/rgblight_oled:via
    make xoiviox/ffkb/rgblight_oled_ec11:via
    make xoiviox/ffkb/rgblight_oled_evq:via
    make xoiviox/ffkb/rgblight_pimoroni:via
    make xoiviox/ffkb/rgblight_pimoroni_ec11:via
    make xoiviox/ffkb/rgblight_pimoroni_evq:via
    make xoiviox/ffkb/rgbmatrix:via
    make xoiviox/ffkb/rgbmatrix_ec11:via
    make xoiviox/ffkb/rgbmatrix_ec11_evq:via
    make xoiviox/ffkb/rgbmatrix_evq:via
    make xoiviox/ffkb/rgbmatrix_oled:via
    make xoiviox/ffkb/rgbmatrix_oled_ec11:via
    make xoiviox/ffkb/rgbmatrix_oled_evq:via
    make xoiviox/ffkb/rgbmatrix_pimoroni:via
    make xoiviox/ffkb/rgbmatrix_pimoroni_ec11:via
    make xoiviox/ffkb/rgbmatrix_pimoroni_evq:via

Example of flashing this keyboard:

    make xoiviox/ffkb/rgblight_oled_ec11:via:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
