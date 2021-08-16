#include QMK_KEYBOARD_H
// #include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Keymap 0: (Base Layer) Default Layer
    [0] = LAYOUT(
                        KC_HOME, KC_END, KC_DEL,
                        MO(1), KC_UP, KC_ENTER,
        KC_AUDIO_MUTE,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Keymap 1: (Function Layer) RGB control Layer
    [1] = LAYOUT(
                        RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_REVERSE,
                        KC_TRANSPARENT, KC_NO, KC_NO,
        KC_TRANSPARENT, KC_NO, KC_NO, KC_NO
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("Hello World!\n"), false);  // Renders a static text
    oled_scroll_left();  // Turns on scrolling
}
#endif

// debugging
// void keyboard_post_init_user(void) {
//     // Customise these values to desired behaviour
//     debug_enable = true;
//     debug_matrix = true;
//     // debug_keyboard=true;
//     // debug_mouse=true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//     return true;
// }