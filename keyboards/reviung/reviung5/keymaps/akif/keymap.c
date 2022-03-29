/* Copyright 2021 gtips
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
#include QMK_KEYBOARD_H


enum macrolar {
    MAKRO1 = SAFE_RANGE,
    RANDOMLAUGH
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
};

#define LO_VD LT(_LOWER, KC_VOLD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_reviung5(
        LO_VD,         KC_MPRV,       KC_MPLY,       RANDOMLAUGH,       MAKRO1
    ),
    [_LOWER] = LAYOUT_reviung5(
        _______,       RGB_HUI,       RGB_MOD,       RGB_TOG,       KC_MUTE
    )
};



// Macros!

// Random string stuff
static int lower = (int) KC_A;
static int upper = (int) KC_Z;
uint16_t random_keycode(void) {
  return lower + (rand() % (upper - lower + 1));
};
// Random string stuff end

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAKRO1:
      if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("babanaber");
        } else {
            // when keycode QMKBEST is released
        }
      break;

    case RANDOMLAUGH:
      if (record->event.pressed) {
        // when keycode LOCKSCREEN is pressed
        for(int i=0;i<=16;i++) {
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