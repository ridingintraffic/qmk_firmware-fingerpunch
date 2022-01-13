#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/barobord/rules.mk keyboards/fingerpunch/barobord/rules.mk.bak
cp keyboards/fingerpunch/barobord/rules-pimoroni.mk keyboards/fingerpunch/barobord/rules.mk
make fingerpunch/barobord:sadekbaroudi ; cp .build/fingerpunch_barobord_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/barobord-pimoroni/ ;
mv keyboards/fingerpunch/barobord/rules.mk.bak keyboards/fingerpunch/barobord/rules.mk
