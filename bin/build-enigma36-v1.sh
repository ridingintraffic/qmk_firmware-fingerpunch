#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/handwired/enigma36/config-v1.h keyboards/xoiviox/handwired/enigma36/config.h
cp keyboards/xoiviox/handwired/enigma36/rules-v1.mk keyboards/xoiviox/handwired/enigma36/rules.mk
make xoiviox/handwired/enigma36:sadekbaroudi ; cp .build/xoiviox_handwired_enigma36_sadekbaroudi* /mnt/c/Users/sadek/Google\ Drive/qmk-keyboards/enigma36-v1/ ;
rm keyboards/xoiviox/handwired/enigma36/config.h
rm keyboards/xoiviox/handwired/enigma36/rules.mk
