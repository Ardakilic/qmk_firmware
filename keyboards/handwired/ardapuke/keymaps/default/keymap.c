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

// Layer names
#define _MAIN 0
#define _FUNC 1

// This is for macros
enum custom_keycodes {
  LOCKSCREEN = SAFE_RANGE,
};


// Song name definitions. These are used when layers are switched.

float qwerty_song[][2] = SONG(QWERTY_SOUND);
float colemak_song[][2] = SONG(COLEMAK_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
        KC_A,  KC_S,  KC_D, KC_F, TT(_FUNC), \
        KC_Z,  KC_X, KC_C, KC_V, KC_B  \
    ),
    [_FUNC] = LAYOUT(
        KC_Q,  KC_W, KC_E, KC_R, TT(_FUNC), \
        KC_1,  KC_2, KC_3, KC_4, RESET  \
    ),
};


uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _MAIN:
      PLAY_SONG(qwerty_song);
      break;
    case _FUNC:
      PLAY_SONG(colemak_song);
      break;
  }
  return state;
}