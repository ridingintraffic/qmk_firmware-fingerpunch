# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
#RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
#ENCODER_ENABLE = yes

# If you don't have pimoroni trackball
#OLED_DRIVER_ENABLE = yes # this can be yes or no depending on if you have an OLED
MOUSEKEY_ENABLE = yes        # Mouse keys

# If you have pimoroni trackball
#OLED_DRIVER_ENABLE = yes # this must be yes since it uses the I2C for pimoroni
#PIMORONI_TRACKBALL_ENABLE = yes
# unfortunately, these two take up a lot of space, so you may need to disable macros :'(
#EXTRAFLAGS     += -flto
#MOUSEKEY_ENABLE = no