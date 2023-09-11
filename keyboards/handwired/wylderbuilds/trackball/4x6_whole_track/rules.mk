MCU = RP2040
SPLIT_KEYBOARD = yes
BOOTLOADER = rp2040
POINTING_DEVICE_DRIVER = pmw3389

SERIAL_DRIVER = vendor
RGBLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
#COMMAND_ENABLE = yes
BOOTMAGIC_ENABLE = yes
OLED_ENABLE = NO
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # Enable N-Key Rollover
ENCODER_ENABLE = NO
#ENCODER_MAP_ENABLE = yes

#OPT_DEFS += -DHAL_USE_I2C=TRUE