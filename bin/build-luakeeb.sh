#!/bin/bash

# TODO: consolidate all the build files into one

# NOTE: I had to set COMBO_ENABLE to no in my users/sadekbaroudi/rules.mk due to space limitations

make fingerpunch/luakeeb:sadekbaroudi ; cp .build/fingerpunch_luakeeb_sadekbaroudi.hex /mnt/g/My\ Drive/qmk-keyboards/luakeeb/ ;
