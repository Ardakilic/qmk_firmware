#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H "./lib/glcdfont.c"
#    define OLED_TIMEOUT 30000
#endif // OLED_ENABLE

/* Indicator LEDs */
#define LED_CAPS_LOCK_PIN GP25
#define LED_PIN_ON_STATE 1

#define POINTING_DEVICE_ROTATION_270
