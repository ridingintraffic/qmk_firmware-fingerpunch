#!/bin/bash

cp keyboards/fingerpunch/ffkb_byomcu/config.h keyboards/fingerpunch/ffkb_byomcu/config.h.bak
cp keyboards/fingerpunch/ffkb_byomcu/config.stemcell.h keyboards/fingerpunch/ffkb_byomcu/config.h

cp keyboards/fingerpunch/ffkb_byomcu/rules.mk keyboards/fingerpunch/ffkb_byomcu/rules.mk.bak
cp keyboards/fingerpunch/ffkb_byomcu/rules.stemcell.mk keyboards/fingerpunch/ffkb_byomcu/rules.mk

mv keyboards/fingerpunch/ffkb_byomcu/halconf.stemcell.h keyboards/fingerpunch/ffkb_byomcu/halconf.h
mv keyboards/fingerpunch/ffkb_byomcu/mcuconf.stemcell.h keyboards/fingerpunch/ffkb_byomcu/mcuconf.h

#make fingerpunch/ffkb_byomcu/rgblight_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/pimoroni_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_oled:sadekbaroudi
#make fingerpunch/ffkb_byomcu/oled:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_ec11:sadekbaroudi
make fingerpunch/ffkb_byomcu/rgbmatrix_oled_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_pimoroni_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_oled_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/pimoroni:sadekbaroudi
#make fingerpunch/ffkb_byomcu/evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_pimoroni_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_oled:sadekbaroudi
#make fingerpunch/ffkb_byomcu/oled_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_ec11_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight:sadekbaroudi
#make fingerpunch/ffkb_byomcu/no_features:sadekbaroudi
#make fingerpunch/ffkb_byomcu/pimoroni_ec11:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_pimoroni:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_ec11_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgbmatrix_oled_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/oled_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/ec11_evq:sadekbaroudi
#make fingerpunch/ffkb_byomcu/rgblight_oled_ec11:sadekbaroudi

mv keyboards/fingerpunch/ffkb_byomcu/config.h.bak keyboards/fingerpunch/ffkb_byomcu/config.h

mv keyboards/fingerpunch/ffkb_byomcu/rules.mk.bak keyboards/fingerpunch/ffkb_byomcu/rules.mk

mv keyboards/fingerpunch/ffkb_byomcu/halconf.h keyboards/fingerpunch/ffkb_byomcu/halconf.stemcell.h
mv keyboards/fingerpunch/ffkb_byomcu/mcuconf.h keyboards/fingerpunch/ffkb_byomcu/mcuconf.stemcell.h

cp fingerpunch_ffkb_byomcu_*_sadekbaroudi.bin /mnt/g/My\ Drive/qmk-keyboards/ffkb_stemcell/sadekbaroudi/
