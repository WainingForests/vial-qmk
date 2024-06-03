#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_5x7( \
    L00, L01, L02, L03, L04, L05, L06,                R06, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, L16,                R16, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
              L32, L33,                                              R32, R33, \
                   L40, L41, L42,                          R42, R41, R40, \
                   L45, L44, L43,                          R43, R44, R45 \
) { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, XXX }, \
    { XXX, XXX, L32, L33, XXX, XXX, XXX }, \
    { L40, L41, L42, L43, L44, L45, XXX }, \
\
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, XXX }, \
    { XXX, XXX, R32, R33, XXX, XXX, XXX }, \
    { R40, R41, R42, R43, R44, R45, XXX } \
}
