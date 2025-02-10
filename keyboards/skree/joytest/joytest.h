#pragma once

#include "quantum.h"

#define XXX KC_NO


#define LAYOUT_3x5( \
     K01, K02, K03, K04, \
     K11, K12, K13, K14, K15, \
K20, K21, K22, K23, K24, K25, K35, \
     K31, K32, K33, K34 \
) { \
    { XXX, K01, K02, K03, K04, XXX }, \
    { XXX, K11, K12, K13, K14, K15 }, \
    { K20, K21, K22, K23, K24, K25 }, \
    { XXX, K31, K32, K33, K34, K35 } \
}
