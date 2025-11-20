#MCU = atmega32u4										# MCU name
#BOOTLOADER = caterina 							# Bootloader selection

#Build Options. change yes to no to disable
VIA_ENABLE = no										  # Enable VIA support
VIAL_ENABLE = no										# Enable VIAL support
BOOTMAGIC_ENABLE = no							  # Enable Bootmagic Lite
LTO_ENABLE = yes										# Enables Link Time Optimization

COMBO_ENABLE = yes									# Enables combos
LEADER_ENABLE = yes									# Enable Leader
MOUSEKEY_ENABLE = yes								# Mouse keys
EXTRAKEY_ENABLE = no         				# Audio control and System control
COMMAND_ENABLE = no									# Commands for debug and configuration
NKRO_ENABLE = yes										# Enable N-Key Rollover
BACKLIGHT_ENABLE = no       				# Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no	       				# Enable keyboard RGB underglow
SPLIT_KEYBOARD = yes								# Split keyboard
TAP_DANCE_ENABLE = yes							# Enable tap-dance
AUDIO_ENABLE = no										# Enable Audio
# Extra Stuff
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
RAW_ENABLE = no
MIDI_ENABLE = no
CONSOLE_ENABLE = no

SRC+= combos.c leader.c start.c
