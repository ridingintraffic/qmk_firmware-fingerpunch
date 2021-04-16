# MCU name
MCU = atmega32u4


EXTRAFLAGS += -flto
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
UNICODE_ENABLE = no        # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes        # Use shared split_common code

OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes 

OLED_DRIVER_ENABLE = yes
