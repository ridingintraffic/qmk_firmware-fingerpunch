# rockon

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Rock On supports vial! If you want to use Vial, go to https://github.com/sadekbaroudi/vial-qmk/keyboards/fingerpunch/rockon/

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make fingerpunch/rockon/no-features:default
    make fingerpunch/rockon/oled:default
    make fingerpunch/rockon/rgblight:default
    make fingerpunch/rockon/rgblight-oled:default
    make fingerpunch/rockon/rgbmatrix:default
    make fingerpunch/rockon/rgbmatrix-oled:default

If using the vial repository, use these:
    make fingerpunch/rockon/no-features:vial
    make fingerpunch/rockon/oled:vial
    make fingerpunch/rockon/rgblight:vial
    make fingerpunch/rockon/rgblight-oled:vial
    make fingerpunch/rockon/rgbmatrix:vial
    make fingerpunch/rockon/rgbmatrix-oled:vial

Example of flashing this keyboard:

    make fingerpunch/rockon/no-features:default:flash

Or in the vial repository:

    make fingerpunch/rockon/no-features:vial:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
