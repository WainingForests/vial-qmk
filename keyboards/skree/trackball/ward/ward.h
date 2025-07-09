#pragma once

#include "trackball.h"

#define XXX KC_NO

#define LAYOUT_6x6( \
    L00, L01, L02, L03, L04, L05, L06,                R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,                R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,                R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,                          R31, R32, R33, R34, R35, R36, \
              L42, L43,                                              R43, R44,  \
                   L50, L51, L52,                          R52, R51, R50, \
                   L53, L54, L55,                          R55, R54, R53 \
) { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, L26 }, \
    { L30, L31, L32, L33, L34, L35, XXX }, \
    { XXX, XXX, L42, L43, XXX, XXX, XXX }, \
    { L50, L51, L52, L53, L54, L55, XXX }, \
\
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, R26 }, \
    { XXX, R31, R32, R33, R34, R35, R36 }, \
    { XXX, XXX, XXX, R43, R44, XXX, XXX }, \
    { R50, R51, R52, R53, R54, R55, XXX } \
}
