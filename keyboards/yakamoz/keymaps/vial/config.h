#pragma once

#define VIAL_KEYBOARD_UID {0x59, 0x41, 0x4B, 0x41, 0x4D, 0x4F, 0x5A, 0x31}
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define WS2812_DI_PIN GP1


#ifdef OLED_ENABLE

/* OLED DRIVER CONFIG */
#define OLED_DISPLAY_64X128
#define OLED_IC OLED_IC_SH1107
/* Lowering the pre charge period fixes coil whining for the used display modules. */
#define OLED_PRE_CHARGE_PERIOD 0x22
#define OLED_VCOM_DETECT 0x35
#define OLED_TIMEOUT 15000

#endif // OLED_ENABLE

/* Indicator LEDs */
#define LED_CAPS_LOCK_PIN GP25
#define LED_PIN_ON_STATE 1
