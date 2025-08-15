#pragma once

#include "trackball.h"

#define XXX KC_NO

#define LAYOUT_5x6( \
    L00, L01, L02, L03, L04,            R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,            R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,            R20, R21, R22, R23, R24, \
         L31, L32,                                     R33, \
              L40, L41, L42,            R41, R40, \
              L43, L44, L45,            R44, R43 \
) { \
    { L00, L01, L02, L03, L04, XXX }, \
    { L10, L11, L12, L13, L14, XXX }, \
    { L20, L21, L22, L23, L24, XXX }, \
    { XXX, L31, L32, XXX, XXX, XXX }, \
    { L40, L41, L42, L43, L44, L45 }, \
\
    { R00, R01, R02, R03, R04, XXX }, \
    { R10, R11, R12, R13, R14, XXX }, \
    { R20, R21, R22, R23, R24, XXX }, \
    { XXX, XXX, XXX, R33, XXX, XXX }, \
    { R40, R41, XXX, R43, R44, XXX } \
}
