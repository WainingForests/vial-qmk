#pragma once

#include "quantum.h"

#define XXX KC_NO

typedef union {
    uint32_t raw;
    struct {
        uint8_t dpi_config;
    };
} keyboard_config_t;
_Static_assert(sizeof(keyboard_config_t) == sizeof(uint32_t), "keyboard_config_t size mismatch compared to EEPROM area");

extern keyboard_config_t keyboard_config;
extern uint16_t          dpi_array[];

enum ploopy_keycodes {
    DPI_CONFIG = QK_KB_0,
    DRAG_SCROLL,
};
