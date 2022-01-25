/* Copyright 2022 Arda Kilicdagi
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


enum lumberjack_layers {
  _QWERTY,
  _LOWER,
  // _RAISE,
  _ADJUST,
  // _SPACE,
  // _SODA,
  _NUMPAD,
  _MAC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  "   |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |NpdEsc|  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  Ş   |  İ   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |SftCps|  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  Ö   |  Ç   |  .   |SftEnt|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |Adj|<>| Win  | Alt  |Lowr|,| Spc* | | Spc* | AltGR| Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_NONUS_BSLASH,KC_1,KC_2,KC_3,KC_4,KC_5,           /*|*/   KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,                    /*|*/   KC_Y,KC_U,KC_I,KC_O,KC_P,KC_DEL,
    LT(_NUMPAD, KC_ESC),KC_A,KC_S,KC_D,KC_F,KC_G,       /*|*/   KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
    LSFT_T(KC_CAPS),KC_Z,KC_X,KC_C,KC_V,KC_B,           /*|*/   KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_SFTENT,
    KC_LCTL,LT(_ADJUST,KC_GRV),KC_LGUI,KC_LALT,LT(_LOWER,KC_BSLS),KC_SPC, /*|*/ KC_SPC,KC_RALT,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT
),


/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |      |      |  "\" |  "|" |  *   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  | |      |   #  |   "  |  "¨" | "~"  |  "=" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      | |      |   ?  |  "`" |  Ğ   |  Ü   |  _   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      | "$"  |  "{" |  "}" |  <   |  ">" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      | Entr | | BkSp |      |  "[" |  "]" |  '   |  "   |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,              /*|*/   _______,_______,BACKSLASH,VERTICAL_PIPE,KC_MINS,KC_EQL,
    _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,             /*|*/   _______,NUMBER_SIGN,KC_NUBS,RALT(KC_LBRC),RALT(KC_RBRC),LSFT(KC_0),
    _______,KC_F11,KC_F12,_______,_______,_______,      /*|*/   _______,KC_UNDS,BACKTICK,KC_LBRC,KC_RBRC,KC_PLUS,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,DOLLAR_SIGN,CURLY_OPEN,CURLY_CLOSE,KC_GRV,LSFT(KC_GRV),
    _______,_______,_______,_______,_______,KC_ENT,     /*|*/   KC_BSPC,_______,SQUARE_OPEN,SQUARE_CLOSE,LSFT(KC_2),KC_NONUS_BSLASH
),


/* Numpad & Mouse
 * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |      |      |M-clic|      |      | |      | NLCK |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | ACL0 |L-clck|  Up  |R-clck|Scrl U| |      |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | ACL1 | Left | Down |Right |Scrl D| |      |   4  |   5  |   6  |   +  |  ,   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | ACL2 | VOLU | PREV |PAUSE | NEXT | |      |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | VOLD | MUTE | Bksp | Del  | |Enter |Space |   0  |   .  |Enter |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_5x12(
    KC_GRV,_______,_______,KC_BTN3,_______,_______,     /*|*/   _______,KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,KC_BSPC,
    _______,KC_ACL0,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,    /*|*/   _______,KC_P7,KC_P8,KC_P9,KC_PPLS,KC_PEQL,
    _______,KC_ACL1,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,    /*|*/   _______,KC_P4,KC_P5,KC_P6,KC_PPLS,KC_PDOT,
    _______,KC_ACL2,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,    /*|*/   _______,KC_P1,KC_P2,KC_P3,KC_PENT,_______,
    _______,_______,KC_VOLD,KC_MUTE,KC_BSPC,KC_DEL,     /*|*/   KC_PENT,KC_SPC,KC_P0,KC_SLSH,KC_PENT,_______
),

/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |EepRST| Reset|      |      |      |      | | macOS|      |      |      |      |LckOSX|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
    EEP_RST,RESET,_______,_______,_______,_______,      /*|*/   TG(_MAC),_______,_______,_______,_______,LOCKSCREEN,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______
),

/* MAC
 * This layout toggles Win/CMD and Left Alt keys's positions for Win and Mac compatibility
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | Alt  | CMD  |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_MAC] = LAYOUT_ortho_5x12(
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,KC_LALT,KC_LGUI,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______
)


};
