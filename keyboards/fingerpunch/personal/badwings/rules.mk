MCU = RP2040
BOOTLOADER = rp2040

# LTO_ENABLE 					= yes

CONSOLE_ENABLE			= no
COMMAND_ENABLE  		= no
NKRO_ENABLE					= no
BACKLIGHT_ENABLE		= no
RGBLIGHT_ENABLE			= no
AUDIO_ENABLE				= no
UNICODE_ENABLE			= no
MAGIC_ENABLE				= no

BOOTMAGIC_ENABLE		= yes
MOUSEKEY_ENABLE			= yes
EXTRAKEY_ENABLE			= yes

SRC += keyboards/fingerpunch/fp_matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite

ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
   OPT_DEFS += -DCIRQUE_ENABLE
endif

DEFERRED_EXEC_ENABLE = yes
SRC +=  keyboards/fingerpunch/fp.c \
        keyboards/fingerpunch/fp_haptic.c \
        keyboards/fingerpunch/fp_keyhandler.c \
        keyboards/fingerpunch/fp_pointing.c \
        keyboards/fingerpunch/fp_rgblight.c \
        keyboards/fingerpunch/fp_rgb_matrix.c
