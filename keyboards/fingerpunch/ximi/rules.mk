# MCU name
MCU = RP2040
BOOTLOADER = rp2040

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
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_DRIVER_ENABLE = no    # this can be yes or no depending on if you have an OLED
EXTRAFLAGS     += -flto     # macros enable or disable
MOUSEKEY_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

# CIRQUE_ENABLE = no
# PMW3360_ENABLE = no

# ifeq ($(strip $(CIRQUE_ENABLE)), yes)
#    POINTING_DEVICE_ENABLE = yes
#    POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
# endif

# ifeq ($(strip $(PMW3360_ENABLE)), yes)
#     POINTING_DEVICE_ENABLE := yes
#     POINTING_DEVICE_DRIVER = pmw3360
#     QUANTUM_LIB_SRC += spi_master.c
# endif


SRC += matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite