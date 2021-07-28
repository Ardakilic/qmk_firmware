/* Copyright 2021 Arda Kilicdagi
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


enum ergotravel_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE,
  _SODA,
  _NUMPAD
};

// KC_NONUS_BSLASH (\|) is equivalent to ["é] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to [<>|] key in Turkish keyboards.
// KC_SCLN is Turkish s [şŞ] key
// KC_QUOT is Turkish i [iİ] key
// KC_COMM is Turkish o [öÖ] key
// KC_DOT is Turkish c [çÇ] key

// Custom shortcuts specific to Turkish layout
#define CURLY_OPEN RALT(KC_7)
#define CURLY_CLOSE RALT(KC_0)
#define SQUARE_OPEN RALT(KC_8)
#define SQUARE_CLOSE RALT(KC_9)
#define DOLLAR_SIGN RALT(KC_4)
#define BACKSLASH RALT(KC_MINS)
#define VERTICAL_PIPE RALT(KC_EQL)
#define BACKTICK RALT(KC_BSLS)
#define TILDE RALT(KC_RBRC)
#define NUMBER_SIGN RALT(KC_3)
#define AT_SIGN RALT(KC_Q)
#define LOCKSCREEN LCTL(LSFT(KC_POWER)) // Screen Lock shortcut for OSX

/* 
// Unicode Turkish characters, in case it's needed
enum {
    TR_C, // ç
    TR_C_L, // Ç
    TR_I, // ı
    TR_I_L, // İ
    TR_G, // ğ
    TR_G_L, // Ğ
    TR_S, // ş
    TR_S_L, // Ş
    TR_U, // ü
    TR_U_L, // Ü
    TR_O, // ö
    TR_O_L, // Ö
};
// clang-format off
const uint32_t PROGMEM unicode_map[] = {
    [TR_C] = 0x00c7,
    [TR_C_L] = 0x00e7,
    [TR_I] = 0x0130,
    [TR_I_L] = 0x0131,
    [TR_G] = 0x011e,
    [TR_G_L] = 0x011f,
    [TR_S] = 0x015e,
    [TR_S_L] = 0x015f,
    [TR_U] = 0x00dc,
    [TR_U_L] = 0x00fc,
    [TR_O] = 0x00d6,
    [TR_O_L] = 0x00f6,
};
// clang-format on
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |  <   |       | "'"  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |NPdEsc|   A  |   S  |   D  |   F  |   G  | "@"  |       | "$"  |   H  |   J  |   K  |   L  |   Ş  |  İ   |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |SftCps|   Z  |   X  |   C  |   V  |   B  |Enter |       |Space*|   N  |   M  |   Ö  |   Ç  |   .  |SftEtr|
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * ||Ctrl |Sda|<>| Alt  |  OS  |  Lower|,  | Space* |       |Enter   |  "|Raise  | Left | Down |  Up  |Right |
 * `------------------------------------------------'       `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_TAB, KC_Q,KC_W, KC_E, KC_R, KC_T, KC_GRV,                   /*|*/         KC_AT, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    LT(_NUMPAD, KC_ESC),KC_A,KC_S,KC_D,KC_F,KC_G,AT_SIGN,           /*|*/         DOLLAR_SIGN, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    LSFT_T(KC_CAPS),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_ENT,                /*|*/         LT(_SPACE, KC_SPC), KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
    KC_LCTL, LT(_SODA, KC_GRV), KC_LALT, KC_LGUI, LT(_LOWER, KC_BSLS),LT(_SPACE, KC_SPC),    /*|*/      KC_ENT, LT(_RAISE, KC_NONUS_BSLASH), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
  ),

/* Lower
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |   >  |   !  |   '  |   ^  |   +  |   %  | Home |       | PgUp |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | End  |       | Pgdn |      |   ?  |   _  |  Ğ   |  Ü   |  -   |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Del  |       | Bksp |      |  "$" |  "{" |  "}" |  <   |  ">" |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |RGBMod|      |      |      |           |   Bksp |       | Del    |           |  "[" |  "]" |  '   |  "   |
 * `------------------------------------------------'       `------------------------------------------------'
 */

  [_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME,    /*|*/        KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,    KC_END ,    /*|*/        KC_PGDN, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_EQL,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,     /*|*/        KC_BSPC, _______,DOLLAR_SIGN, CURLY_OPEN, CURLY_CLOSE, KC_GRV, LSFT(KC_GRV),
    RGB_MOD, _______, _______, _______, _______, KC_BSPC,             /*|*/        KC_DEL, _______, SQUARE_OPEN, SQUARE_CLOSE, LSFT(KC_2), KC_NONUS_BSLASH 
  ),


/* Raise
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |  <>| |   1  |   2  |   3  |   4  |   5  | Vol+ |       | Play |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |  Del |      |      |      |      |      | Vol- |       | Next | Prev |   *  |   -  | "\"  | "|"  |  ,   |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Mute |       | Stop |      |   #  |   "  | "~"  | "`"  |  <>| |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |           |        |       | Bksp   |           |      |      |      |      |
 * `------------------------------------------------'       `------------------------------------------------'
 */



  [_RAISE] = LAYOUT(
    KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_VOLU,                   /*|*/       KC_MPLY, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_DEL, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, _______,  KC_VOLD,    /*|*/       KC_MNXT, KC_MPRV, KC_MINS, KC_EQL, BACKSLASH, VERTICAL_PIPE, KC_BSLS,
    _______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, _______,  KC_MUTE,  /*|*/       KC_MSTP, _______, NUMBER_SIGN, KC_NUBS, TILDE, BACKTICK, KC_GRV,
    _______, RGB_TOG, BL_STEP, _______, _______, _______,             /*|*/           KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

/* Soda
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |      |      |  Up  |      |Brght▲|      |      |       |      |      |      |  Up  |      |      |LCKOSX|
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      | Left | Down | Right|Brght▼|      |      |       |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |       |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |           |        |       |        |           |      |      |      |      |
 * `------------------------------------------------'       `------------------------------------------------'
 */
  [_SODA] = LAYOUT(
    _______, _______, KC_UP, _______, KC_BRMU, _______, _______,      /*|*/       _______, _______, _______, KC_UP, _______, _______, LOCKSCREEN,
    _______, KC_LEFT, KC_DOWN, KC_RGHT,KC_BRMD, _______, _______,     /*|*/       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    /*|*/       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,             /*|*/                _______, _______, _______, _______, _______, _______
  ),

/* Space
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |      |CMD+1 |CMD+2 |CMD+3 |CMD+4 |CMD+5 |      |       |      |CMD+6 |CMD+7 |CMD+8 |CMD+9 |CMD+0 |LCKOSX|
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |       |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |       |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |           |        |       |        |           |      |      |      |      |
 * `------------------------------------------------'       `------------------------------------------------'
 */
  [_SPACE] = LAYOUT(
    _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), _______,   /*|*/       _______, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8),  LGUI(KC_9), LGUI(KC_0), LOCKSCREEN,
    _______, _______, _______, _______, _______, _______, _______,                  /*|*/       _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                  /*|*/       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                           /*|*/                _______, _______, _______, _______, _______, _______
  ),

/* Numpad
 * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
 * ,------------------------------------------------.       ,------------------------------------------------.
 * |      |      |      |      |      |      |      |       |      |  DEL |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |       |      | Enter|   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |       |      | Enter|   1  |   2  |   3  |   +  |   /  |
 * |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 * |      |      |      |      |           |        |       |        |     0     |   0  |   .  |   ,  |   =  |
 * `------------------------------------------------'       `------------------------------------------------'
 */
  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,    /*|*/       _______, KC_DEL, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______,    /*|*/       _______, KC_PENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
    _______, _______, _______, _______, _______, _______, _______,    /*|*/       _______, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PSLS,
    _______, _______, _______, _______, _______, _______,             /*|*/       _______, KC_P0, KC_P0, KC_SLSH, KC_PDOT, KC_PEQL
  ),

  [_ADJUST] = LAYOUT(
     _______, _______,  _______, _______, _______, _______, _______,  /*|*/       _______,  _______, _______, _______, _______, EEP_RST, RESET,
     _______, _______,  _______, _______, _______, _______, _______,  /*|*/       _______,  _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______, _______, _______,  /*|*/       _______,  _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,            /*|*/                 _______, _______, _______, _______, _______, _______
  )
};



// Enable the adjust layer when both lower and 
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}