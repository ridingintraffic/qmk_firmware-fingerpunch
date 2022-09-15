#pragma once
#include "quantum.h"

void pointing_device_set_default_cpi(void);

#define LAYOUT_ximi( \
  K00, K01, K02, K03, K04, K05, K35, K34, K33, K32, K31, K30, \
  K10, K11, K12, K13, K14, K15, K45, K44, K43, K42, K41, K40, \
  K20, K21, K22, K23, K24, K25, K55, K54, K53, K52, K51, K50, \
                 K06, K16, K26, K56, K46, K36,                \
                 K07, K17, K27, K57, K47, K37 \
  ) \
  { \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 } \
  }

