#!/bin/bash

# TODO: consolidate all the build files into one

make fingerpunch/rockon/rgbmatrix_oled:sadekbaroudi
cp .build/fingerpunch_rockon_rgbmatrix_oled_sadekbaroudi.hex /mnt/g/My\ Drive/qmk-keyboards/rock-on/rgbmatrix/fingerpunch_rockon_rgbmatrix_oled_sadekbaroudi.hex

make fingerpunch/rockon/rgblight_oled:sadekbaroudi
cp .build/fingerpunch_rockon_rgblight_oled_sadekbaroudi.hex /mnt/g/My\ Drive/qmk-keyboards/rock-on/rgblight/fingerpunch_rockon_rgblight_oled_sadekbaroudi.hex
