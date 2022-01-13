#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/ffkb/config.h keyboards/fingerpunch/ffkb/config.h.bak
cp keyboards/fingerpunch/ffkb/rules.mk keyboards/fingerpunch/ffkb/rules.mk.bak
cp keyboards/fingerpunch/ffkb/config-rgblight-ec11.h keyboards/fingerpunch/ffkb/config.h
cp keyboards/fingerpunch/ffkb/rules-rgblight-ec11.mk keyboards/fingerpunch/ffkb/rules.mk
make fingerpunch/ffkb:sadekbaroudi
mv keyboards/fingerpunch/ffkb/config.h.bak keyboards/fingerpunch/ffkb/config.h
mv keyboards/fingerpunch/ffkb/rules.mk.bak keyboards/fingerpunch/ffkb/rules.mk
cp .build/fingerpunch_ffkb_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/ffkb-rgblight-ec11/
