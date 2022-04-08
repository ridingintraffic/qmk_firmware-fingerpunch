#!/bin/bash

# TODO: consolidate all the build files into one

make fingerpunch/rockon_bp/rgbmatrix_oled:sadekbaroudi
cp .build/fingerpunch_rockon_bp_rgbmatrix_oled_sadekbaroudi.bin /mnt/g/My\ Drive/qmk-keyboards/rock-on_bp/sadekbaroudi/fingerpunch_rockon_bp_rgbmatrix_oled_sadekbaroudi.bin

make fingerpunch/rockon_bp/rgblight_oled:sadekbaroudi
cp .build/fingerpunch_rockon_bp_rgblight_oled_sadekbaroudi.bin /mnt/g/My\ Drive/qmk-keyboards/rock-on_bp/sadekbaroudi/fingerpunch_rockon_bp_rgblight_oled_sadekbaroudi.bin

make fingerpunch/rockon_bp/rgbmatrix:sadekbaroudi
cp .build/fingerpunch_rockon_bp_rgbmatrix_sadekbaroudi.bin /mnt/g/My\ Drive/qmk-keyboards/rock-on_bp/sadekbaroudi/fingerpunch_rockon_bp_rgbmatrix_sadekbaroudi.bin


