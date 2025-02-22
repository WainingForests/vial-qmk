#pragma once

#include "config_common.h"

#define JOYSTICK_BUTTON_COUNT 0
// Max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXES_COUNT 2

#ifdef RGBLIGHT_ENABLE
#  define RGB_DI_PIN D6
#  define RGBLED_NUM 21
#  define RGBLIGHT_ANIMATIONS
#endif

#define COMBO_COUNT 1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U