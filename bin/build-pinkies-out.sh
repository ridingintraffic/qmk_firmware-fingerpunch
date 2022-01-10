#!/bin/bash

# TODO: consolidate all the build files into one

#make xoiviox/pinkiesout/rgbmatrix_oled:default
#cp .build/xoiviox_pinkiesout_rgbmatrix_oled_default* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout

#make xoiviox/pinkiesout/rgblight_oled:sadekbaroudi
#cp .build/xoiviox_pinkiesout_rgblight_oled_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout/rgblight_oled/

make xoiviox/pinkiesout/rgbmatrix_oled:sadekbaroudi
cp .build/xoiviox_pinkiesout_rgbmatrix_oled_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/pinkiesout/rgbmatrix/
