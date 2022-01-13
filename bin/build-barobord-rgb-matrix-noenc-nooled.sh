#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/barobord/rules.mk keyboards/fingerpunch/barobord/rules.mk.bak
cp keyboards/fingerpunch/barobord/rules-rgb-matrix-noenc-nooled.mk keyboards/fingerpunch/barobord/rules.mk
cp keyboards/fingerpunch/barobord/config.h keyboards/fingerpunch/barobord/config.h.bak
cp keyboards/fingerpunch/barobord/rules-rgb-matrix-noenc-nooled.config.h keyboards/fingerpunch/barobord/config.h
make fingerpunch/barobord:sadekbaroudi ; cp .build/fingerpunch_barobord_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/barobord-rgb-matrix-noenc-nooled/ ;
mv keyboards/fingerpunch/barobord/rules.mk.bak keyboards/fingerpunch/barobord/rules.mk
mv keyboards/fingerpunch/barobord/config.h.bak keyboards/fingerpunch/barobord/config.h
