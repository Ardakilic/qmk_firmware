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


#ifdef AUDIO_ENABLE
  #define RICK_ROLL Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_D5), HD_NOTE(_D5), W__NOTE(_C5), S__NOTE(_REST), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_C5), HD_NOTE(_C5), W__NOTE(_BF4), S__NOTE(_REST), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), W__NOTE(_BF4), H__NOTE(_C5), H__NOTE(_A4), H__NOTE(_A4), H__NOTE(_G4), H__NOTE(_F4), H__NOTE(_F4), W__NOTE(_C5), W__NOTE(_BF4)
  #undef STARTUP_SONG
  #define STARTUP_SONG SONG(RICK_ROLL)
#endif
