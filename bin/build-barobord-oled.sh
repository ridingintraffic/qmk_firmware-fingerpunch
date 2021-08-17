#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/barobord/rules-oled.mk keyboards/xoiviox/barobord/rules.mk
make xoiviox/barobord:sadekbaroudi ; cp .build/xoiviox_barobord_sadekbaroudi* /mnt/c/Users/sadek/Google\ Drive/qmk-keyboards/barobord-oled/ ;
rm keyboards/xoiviox/barobord/rules.mk
