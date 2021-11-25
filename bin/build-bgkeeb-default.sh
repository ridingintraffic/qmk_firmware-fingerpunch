#!/bin/bash

# TODO: consolidate all the build files into one

# NOTE: I had to set COMBO_ENABLE to no in my users/sadekbaroudi/rules.mk due to space limitations

cp keyboards/xoiviox/bgkeeb/config.h keyboards/xoiviox/bgkeeb/config.h.bak
cp keyboards/xoiviox/bgkeeb/config.left.h keyboards/xoiviox/bgkeeb/config.h
make xoiviox/bgkeeb:default ; cp .build/xoiviox_bgkeeb_default.hex /mnt/g/My\ Drive/qmk-keyboards/bgkeeb-default/left/ ;

cp keyboards/xoiviox/bgkeeb/config.right.h keyboards/xoiviox/bgkeeb/config.h
make xoiviox/bgkeeb:default ; cp .build/xoiviox_bgkeeb_default.hex /mnt/g/My\ Drive/qmk-keyboards/bgkeeb-default/right/ ;

mv keyboards/xoiviox/bgkeeb/config.h.bak keyboards/xoiviox/bgkeeb/config.h
