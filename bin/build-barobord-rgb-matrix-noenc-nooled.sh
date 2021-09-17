#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/barobord/rules.mk keyboards/xoiviox/barobord/rules.mk.bak
cp keyboards/xoiviox/barobord/rules-rgb-matrix-noenc-nooled.mk keyboards/xoiviox/barobord/rules.mk
cp keyboards/xoiviox/barobord/config.h keyboards/xoiviox/barobord/config.h.bak
cp keyboards/xoiviox/barobord/rules-rgb-matrix-noenc-nooled.config.h keyboards/xoiviox/barobord/config.h
make xoiviox/barobord:sadekbaroudi ; cp .build/xoiviox_barobord_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/barobord-rgb-matrix-noenc-nooled/ ;
mv keyboards/xoiviox/barobord/rules.mk.bak keyboards/xoiviox/barobord/rules.mk
mv keyboards/xoiviox/barobord/config.h.bak keyboards/xoiviox/barobord/config.h
