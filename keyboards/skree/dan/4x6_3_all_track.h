#pragma once

#include "trackball.h"

#define XXX KC_NO


#define LAYOUT_4x6( \
    L00, L01, L02, L03, L04, L05,                  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                  R20, R21, R22, R23, R24, R25, \
              L32, L33,                                      R32, R33, \
                        L46, L45, L44,        R44, R45, R46 \
) { \
    { L00, L01, L02, L03, L04, L05, XXX }, \
    { L10, L11, L12, L13, L14, L15, XXX }, \
    { L20, L21, L22, L23, L24, L25, XXX }, \
    { XXX, XXX, L32, L33, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, L44, L45, L46 }, \
\
    { R00, R01, R02, R03, R04, R05, XXX }, \
    { R10, R11, R12, R13, R14, R15, XXX }, \
    { R20, R21, R22, R23, R24, R25, XXX }, \
    { XXX, XXX, R32, R33, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, R44, R45, R46 } \
}
