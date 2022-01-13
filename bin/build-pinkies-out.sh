#!/bin/bash

# TODO: consolidate all the build files into one

#make fingerpunch/pinkiesout/rgbmatrix_oled:default
#cp .build/fingerpunch_pinkiesout_rgbmatrix_oled_default* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout

#make fingerpunch/pinkiesout/rgblight_oled:sadekbaroudi
#cp .build/fingerpunch_pinkiesout_rgblight_oled_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout/rgblight_oled/

make fingerpunch/pinkiesout/rgbmatrix_oled:sadekbaroudi
cp .build/fingerpunch_pinkiesout_rgbmatrix_oled_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout/rgbmatrix/
