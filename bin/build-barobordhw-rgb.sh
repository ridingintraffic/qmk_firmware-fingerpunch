#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/xoiviox/handwired/barobordhw/rules-rgb.mk keyboards/xoiviox/handwired/barobordhw/rules.mk
make xoiviox/handwired/barobordhw:sadekbaroudi ; cp .build/xoiviox_handwired_barobordhw_sadekbaroudi* /mnt/c/Users/sadek/Google\ Drive/qmk-keyboards/barobordhw-rgb/ ;
rm keyboards/xoiviox/handwired/barobordhw/rules.mk
