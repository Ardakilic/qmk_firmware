/* Copyright 2019 eswai
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


enum thelayers {
  _QWERTY,
  _FN
};



// KC_NUBS (\|) is equivalent to ["é] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to [<>|] key in Turkish keyboards.
// KC_SCLN is Turkish s [şŞ] key
// KC_QUOT is Turkish i [iİ] key
// KC_COMM is Turkish o [öÖ] key
// KC_DOT is Turkish c [çÇ] key

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-------------------------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ş  |   İ  | Enter|  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Ö  |   Ç  |   /  | Shift|  Up  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |  FN  | Win  | Alt  | SPC  | SPC  | Space| Space| SPC  | SPC  | Ctrl | Left | Down | Right|
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,   KC_W,    KC_E,   KC_R,     KC_T,     KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TAB,  KC_A,   KC_S,    KC_D,   KC_F,     KC_G,     KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  KC_BSLS,
    KC_LSFT, KC_Z,   KC_X,    KC_C,   KC_V,     KC_B,     KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,
    KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Numpad Layer
  * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
  * ,-------------------------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |   7  |   8  |   9  |   -  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | Enter|   4  |   5  |   6  |   +  |   *  |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | Enter|   1  |   2  |   3  |   +  |   /  |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |             |   0  |   0  |   .  |   ,  |   =  |
  * `-------------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PSLS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_P0, KC_SLSH, KC_PDOT, KC_PEQL
  )

};