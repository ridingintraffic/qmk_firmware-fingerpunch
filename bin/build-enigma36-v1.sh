#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/handwired/enigma36/config-v1.h keyboards/fingerpunch/handwired/enigma36/config.h
cp keyboards/fingerpunch/handwired/enigma36/rules-v1.mk keyboards/fingerpunch/handwired/enigma36/rules.mk
make fingerpunch/handwired/enigma36:sadekbaroudi ; cp .build/fingerpunch_handwired_enigma36_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/enigma36-v1/ ;
rm keyboards/fingerpunch/handwired/enigma36/config.h
rm keyboards/fingerpunch/handwired/enigma36/rules.mk
