BOARD = GENERIC_RP_RP2040


OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_DRIVER_ENABLE= yes
OLED_TRANSPORT = i2c

OPT_DEFS += -DHAL_USE_I2C=TRUE

# Enable Trackball
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = yes
RGBLIGHT_ENABLE = yes # Enable keyboard RGB underglow