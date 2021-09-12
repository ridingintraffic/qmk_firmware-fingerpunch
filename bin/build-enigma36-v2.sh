#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/handwired/enigma36/config-v2.h keyboards/xoiviox/handwired/enigma36/config.h
cp keyboards/xoiviox/handwired/enigma36/rules-v2.mk keyboards/xoiviox/handwired/enigma36/rules.mk
make xoiviox/handwired/enigma36:sadekbaroudi ; cp .build/xoiviox_handwired_enigma36_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/enigma36-v2/ ;
rm keyboards/xoiviox/handwired/enigma36/config.h
rm keyboards/xoiviox/handwired/enigma36/rules.mk
