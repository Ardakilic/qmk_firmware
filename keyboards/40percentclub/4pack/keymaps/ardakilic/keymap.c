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
#include QMK_KEYBOARD_H

enum custom_keycodes {
  MACRO1 = SAFE_RANGE,
  MACRO2,
};
// Random string stuff
static int lower = (int) KC_A;
static int upper = (int) KC_Z;
uint16_t random_keycode(void) {
  return lower + (rand() % (upper - lower + 1));
};
// Random string stuff end


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(LSFT(KC_POWER)), KC_VOLD, KC_VOLU, LT(1, KC_MPLY)
    ),
    [1] = LAYOUT(
        MACRO1, MACRO2, LT(2, RESET), _______
    ),
    [2] = LAYOUT(
        EEPROM_RESET, RESET, _______, _______
    ),
};


void matrix_init_user(void) { }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO1:
      if (record->event.pressed) {
        SEND_STRING("git checkout master");
        tap_code(KC_ENT);
        SEND_STRING("git fetch origin");
        tap_code(KC_ENT);
        SEND_STRING("git merge origin/develop");
        tap_code(KC_ENT);
        SEND_STRING("git push origin master");
        tap_code(KC_ENT);
      } else {
        // when keycode MACRO1 is released
      }
      break;
    case MACRO2:
      if (record->event.pressed) {
        // when keycode RANDOMLAUGH is pressed
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
