#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_5x6( \
         L01, L02, L03, L04,                        R00, R01, R02, R03,  \
    L10, L11, L12, L13, L14,                        R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                        R20, R21, R22, R23, R24, \
         L31, L32, L33,                                  R31, R32, R33,  \
         L41, L42,                                            R42, R43, \
                   L50, L51, L52,                R52, R51, R50 \
) { \
    { XXX, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, L31, L32, L33, XXX }, \
    { XXX, L41, L42, XXX, XXX }, \
    { L50, L51, L52, XXX, XXX }, \
\
    { R00, R01, R02, R03, XXX }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { XXX, R31, R32, R33, XXX }, \
    { XXX, XXX, R42, R43, XXX }, \
    { R50, R51, R52, XXX, XXX } \
}
