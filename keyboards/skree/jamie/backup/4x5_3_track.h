#pragma once

#include "trackball.h"

#define XXX KC_NO


#define LAYOUT_4x5( \
    L00, L01, L02, L03, L04,                  R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,                  R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                  R20, R21, R22, R23, R24, \
         L31, L32,                                      R32, R33,\
                   L42, L43, L44,        R40, R41, R42 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, L31, L32, XXX, XXX }, \
    { XXX, XXX, L42, L43, L44 }, \
\
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { XXX, XXX, R32, R33, XXX }, \
    { R40, R41, R42, XXX, XXX } \
}
