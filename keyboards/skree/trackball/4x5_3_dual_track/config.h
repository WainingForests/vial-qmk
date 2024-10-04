// Dactyl Manuform Hotswap
#pragma once

// Basic Config

#ifndef WYLD_QMK_FIRMWARE_CONFIG_H
#define WYLD_QMK_FIRMWARE_CONFIG_H

#endif // WYLD_QMK_FIRMWARE_CONFIG_H

#define USE_SERIAL
#define SPLIT_HAND_PIN      GP28  // high = left, low = right

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX 
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

/* key matrix size */
// Columns are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

#define MATRIX_COL_PINS { GP6, GP7, GP8, GP14, GP15 }
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP12, GP13 }
#define DIODE_DIRECTION COL2ROW

#define SPLIT_LAYER_STATE_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_ROTATION_90
#define ROTATIONAL_TRANSFORM_ANGLE  -45 // TESTING RIGHT SHIFTED FROM -35 TO -45 TO TEST LEFT
#define POINTING_DEVICE_INVERT_Y_RIGHT
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X
#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4
#define PMW33XX_CS_PIN GP5
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PMW33XX_LIFTOFF_DISTANCE 0x03

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 3

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

//#define ENCODERS_PAD_A { }
//#define ENCODERS_PAD_B { }
//#define ENCODER_RESOLUTIONS { }
//#define ENCODERS_PAD_A_RIGHT { GP17, GP15 }
//#define ENCODERS_PAD_B_RIGHT { GP16, GP14 }
//#define ENCODER_RESOLUTIONS_RIGHT { 2 }


//// Sensor Notes ////
//// Pi Pico pins ////
// 3V3  -- Power (not 3v3_EN)
// GP17 -- CS pin
// GP20 -- MISO pin
// GP19 -- MOSI pin
// GP18 -- SCK pin clock Driver
#ifdef RGBLIGHT_ENABLE
#define WS2812_PIO_USE_PIO1
//#define WS2812_PIO_USE_PIO1
//#define WS2812_PIO_USE_PIO1
#define RGBLIGHT_LAYERS
#define WS2812_DI_PIN GP22 // can use trackball jack if not used
//#define WS2812_EXTERNAL_PULLUP
#define RGBLED_NUM 24
//#define DRIVER_LED_TOTAL 34
#define RGBLED_SPLIT { 12, 12 }
#define RGBLIGHT_SPLIT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 100
//#define STM32_SYSCLK KINETIS_SYSCLK_FREQUENCY
#define NOP_FUDGE 0.4  // may not be needed if ws driver loaded
#endif

//// OLED Pins and Driver
#ifdef OLED_ENABLE
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
// OLED Options
#define SPLIT_OLED_ENABLE
//#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_MATRIX_SIZE 512
#define OLED_RESET -1
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 32000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 0
#endif

// Misc settings
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE// Enables This makes it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD
// End of Basic Config
