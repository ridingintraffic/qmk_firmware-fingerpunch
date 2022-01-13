#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/fingerpunch/handwired/barobordhw/rules-rgb-matrix.mk keyboards/fingerpunch/handwired/barobordhw/rules.mk
make fingerpunch/handwired/barobordhw:sadekbaroudi ; cp .build/fingerpunch_handwired_barobordhw_sadekbaroudi* /mnt/g/My\ Drive/qmk-keyboards/barobordhw-rgb-matrix/ ;
rm keyboards/fingerpunch/handwired/barobordhw/rules.mk
