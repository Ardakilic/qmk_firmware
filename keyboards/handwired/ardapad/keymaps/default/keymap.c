/* Copyright 2019 Arda Kilicdagi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Notes:
// TT() activates by 2 tap, defined with "TAPPING_TOGGLE" line added at "config.h"

#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FUNC 1

// This is for macros
enum custom_keycodes {
  LOCKSCREEN = SAFE_RANGE,
  CACHE,
  RANDOMLAUGH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
        KC_A,  KC_S,  KC_D, KC_F, TT(_FUNC), \
        KC_Z,  KC_X, KC_C, KC_V, KC_B  \
    ),
    [_FUNC] = LAYOUT(
        KC_MPLY,  KC__VOLDOWN, KC__VOLUP, KC_MUTE, TT(_FUNC), \
        LOCKSCREEN,  CACHE, RANDOMLAUGH, KC_8, RESET  \
    ),
};


// Do something on layer toggle
// I'm toggling backlight so I can understand which layer I'm currently on
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _MAIN:
      backlight_set(3);
      break;
    case _FUNC:
      backlight_set(0);
      break;
  }
  return state;
}

// Random string stuff
static int lower = (int) KC_A;
static int upper = (int) KC_Z;
uint16_t random_keycode(void) {
  return lower + (rand() % (upper - lower + 1));
};
// Random string stuff end

// Macros!
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCKSCREEN:
      if (record->event.pressed) {
        // when keycode LOCKSCREEN is pressed, run the macOS lock sequence
        register_code(KC_LCTRL);
        register_code(KC_LSFT);
        tap_code(KC_POWER);
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTRL);
      } else {
        // when keycode LOCKSCREEN is released
      }
      break;

    case CACHE:
      if (record->event.pressed) {
        // when keycode cache is pressed, run the macOS cache sequence

        // SOME FANCY MACRO WHICH I CANNOT OPEN SOURCE, SORRY
        // BASICALLY IT OPENS AN APP AND RUNS SOME COMMANDS
        // NOTHING DIFFERENT THAN LOCKSCREEN MACRO
        // ONLY THING NOT USED ANYWHERE IS
        // _delay_ms(miliseconds);
        // WHICH ADDS DELAY BETWEEN TWO STEPS
      } else {
        // when keycode CACHE is released
      }
      break;

    case RANDOMLAUGH:
      if (record->event.pressed) {
        // when keycode LOCKSCREEN is pressed
        for(int i=0;i<=10;i++) {
            tap_code(random_keycode());
        }
        tap_code(KC_ENT);
      } else {
        // when keycode RANDOMLAUGH is released
      }
      break;

  }
  return true;
};