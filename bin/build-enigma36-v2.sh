#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/handwired/enigma36/config-v2.h keyboards/fingerpunch/handwired/enigma36/config.h
cp keyboards/fingerpunch/handwired/enigma36/rules-v2.mk keyboards/fingerpunch/handwired/enigma36/rules.mk
make fingerpunch/handwired/enigma36:sadekbaroudi ; cp .build/fingerpunch_handwired_enigma36_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/enigma36-v2/ ;
rm keyboards/fingerpunch/handwired/enigma36/config.h
rm keyboards/fingerpunch/handwired/enigma36/rules.mk
