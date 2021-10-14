#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/ffkb/rules.mk keyboards/xoiviox/ffkb/rules.mk.bak
cp keyboards/xoiviox/ffkb/rules-rgb-matrix-evq-ec11.mk keyboards/xoiviox/ffkb/rules.mk
make xoiviox/ffkb:sadekbaroudi
mv keyboards/xoiviox/ffkb/rules.mk.bak keyboards/xoiviox/ffkb/rules.mk
cp .build/xoiviox_ffkb_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/ffkb-rgb-matrix-evq-ec11/
