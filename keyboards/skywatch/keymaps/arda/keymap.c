/* Copyright 2023 Arda Kilicdagi
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

enum skywatch_layers {
    _QWERTY,
    _ADJUST,
    _LOWER,
    _SPACE,
    _ENT,
    _RAISE,
    _BSPC,
};

enum macos_keycodes {
  KC_SPOTLIGHT = SAFE_RANGE,
  KC_DICTATION,
  KC_DO_NOT_DISTURB,
  KC_LOCK_SCREEN,

  NEW_SAFE_RANGE_1,
};

// pimoroni trackball keycodes
#ifdef POINTING_DEVICE_ENABLE
enum trackball_keycodes {
  BALL_HUI = NEW_SAFE_RANGE_1,  //cycles hue
  BALL_WHT,                     //cycles white
  BALL_DEC,                     //decreased color
  BALL_SCR,                     //scrolls
  BALL_NCL,                     //left click
  BALL_RCL,                     //right click
  BALL_MCL,                     //middle click
};
#endif
// END pimoroni trackball keycodes

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
#define LOCKSCREEN LCTL(LSFT(KC_PWR)) // Screen Lock shortcut for OSX
#define AT_SIGN RALT(KC_Q)

// Layer Keys
#define LAYER_ADJUST LT(_TAB, KC_TAB)
#define LAYER_LOWER LT(_LOWER, KC_BSLS)
#define LAYER_SPACE LT(_SPACE, KC_SPC)
#define LAYER_ENTER LT(_ENT, KC_ENT)
#define LAYER_RAISE LT(_RAISE, KC_NONUS_BACKSLASH)
#define LAYER_BACKSPACE LT(_BSPC, KC_BSPC)
// END Layer Keys

// Tap-hold keys
#define TH_LSFT_Z LSFT_T(KC_Z)
#define TH_RSFT_DOT RSFT_T(KC_SLSH)
// END Tap-hold keys

// Combo keys
// Can be used with modifier and layer toggle keys
// https://github.com/qmk/qmk_firmware/pull/8591#issuecomment-976019486
enum combos {
  C_ESC,
  C_BSP_1,
  C_BSP_2,
  C_TURKISH_I_1,
  C_TURKISH_I_2,
  C_DEL,
  C_LCMD_1,
  C_RCMD,
  C_TAB_1,
  C_TAB_2,
  C_TAB_3,
  C_LCTL,
  C_RCTL,
  C_LALT,
  C_RALT_1,
  C_RALT_2,
  C_LEFT_LAYER_ENTER,
  C_ADJUST_LAYER,
};

const uint16_t PROGMEM c_esc_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM c_bsp_combo_1[] = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM c_bsp_combo_2[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_turkish_i_combo_1[] = {KC_SCLN, TH_RSFT_DOT, COMBO_END};
const uint16_t PROGMEM c_turkish_i_combo_2[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_del_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_lcmd_combo_1[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM c_rcmd_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_tab_combo_1[] = {KC_A, TH_LSFT_Z, COMBO_END};
const uint16_t PROGMEM c_tab_combo_2[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_tab_combo_3[] = {LAYER_SPACE, LAYER_ENTER, COMBO_END};
const uint16_t PROGMEM c_lctl_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_rctl_combo[] = {KC_COMM, KC_DOT, COMBO_END}; // Ö-Ç
const uint16_t PROGMEM c_lalt_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_ralt_combo_1[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_ralt_combo_2[] = {LAYER_RAISE, LAYER_BACKSPACE, COMBO_END};

const uint16_t PROGMEM c_left_layer_enter_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM c_adjust_layer_combo[] = {KC_LGUI, LAYER_LOWER, COMBO_END};

combo_t key_combos[] = {
    [C_ESC] = COMBO(c_esc_combo, KC_ESC),
    [C_BSP_1] = COMBO(c_bsp_combo_1, KC_BSPC),
    [C_BSP_2] = COMBO(c_bsp_combo_2, KC_BSPC),
    [C_TURKISH_I_1] = COMBO(c_turkish_i_combo_1, KC_QUOT),
    [C_TURKISH_I_2] = COMBO(c_turkish_i_combo_2, KC_QUOT),
    [C_DEL] = COMBO(c_del_combo, KC_DEL),
    [C_LCMD_1] = COMBO(c_lcmd_combo_1, KC_LGUI),
    [C_RCMD] = COMBO(c_rcmd_combo, KC_LGUI),
    [C_TAB_1] = COMBO(c_tab_combo_1, KC_TAB),
    [C_TAB_2] = COMBO(c_tab_combo_2, KC_TAB),
    [C_TAB_3] = COMBO(c_tab_combo_3, KC_TAB),
    [C_LCTL] = COMBO(c_lctl_combo, KC_LCTL),
    [C_RCTL] = COMBO(c_rctl_combo, KC_RCTL),
    [C_LALT] = COMBO(c_lalt_combo, KC_LALT),
    [C_RALT_1] = COMBO(c_ralt_combo_1, KC_RALT),
    [C_RALT_2] = COMBO(c_ralt_combo_2, KC_RALT),
    
    [C_LEFT_LAYER_ENTER] = COMBO(c_left_layer_enter_combo, MO(_ENT)),
    [C_ADJUST_LAYER] = COMBO(c_adjust_layer_combo, MO(_ADJUST)),
};
// END Combo keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// QWERTY
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭───[TAB] W [ESC]  E │  R   │  T   │                │  Y   │  U  [İ] I [DEL] O [BKSP]──╮
//  │   Q  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  P   │
//  ├─-ESC─┤  S [CMD]  D │ F [_ENT]  G │                │  H   │  J   │  K [CMD] L  ├─BKSP─┤
//  │   A  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  Ş   │
//  ├──TAB─┤  X [CTL] C [ALT] V │  B   │                │  N   │ M [ALT] Ö [CTL] Ç  ├──İ-──┤
//  │LSFT/Z├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤RSFT/.│
//  ╰──────╯             │ CMD  ├──────╮                ╭──────┤BKSP/*│             ╰──────╯
//                       ╰──[_ADJ]LWR/,├───────┬────────┤RSE/"[ROPT}──╯
//                              ╰──────┤SPACE/*│ ENT/*  ├──────╯
//                                     ╰─────[TAB]──────╯ 

  [_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P,      
    KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_SCLN, 
    TH_LSFT_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, KC_COMM, KC_DOT, TH_RSFT_DOT,
       KC_LGUI, LAYER_LOWER, LAYER_SPACE, LAYER_ENTER, LAYER_RAISE, LAYER_BACKSPACE
  ),


// AUST layer, for configuration
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤ SAT+ │ HUE+ │ ANI+ │ TOG  │                │      │      │      │      ├──────╮
//  │ BRI+ ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤LCKOSX│
//  ├──────┤ SAT- │ HUE- │ ANI- │      │                │BllHui│BllWht│BllDec│      ├──────┤
//  │ BRI- ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤      │      │      │BllScr│                │REBOOT│ BOOT │EE_CLR│DEBUG ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │      ├──────╮                ╭──────┤      │             ╰──────╯
//                       ╰──────┤      ├───────┬────────┤      ├──────╯
//                              ╰──────┤       │        ├──────╯
//                                     ╰───────┴────────╯ 

  [_ADJUST] = LAYOUT(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,    RGB_TOG,            _______,  _______,  _______,  _______, LOCKSCREEN,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD,   _______,            BALL_HUI, BALL_WHT, BALL_DEC, _______, _______,     
    _______,   KC_BTN3, KC_BTN2,  KC_BTN1,    BALL_SCR,           QK_RBT,   QK_BOOT,   EE_CLR,  DB_TOGG, _______,     
                              _______,   _______,    _______,  _______,   _______,   _______
  ),


// Lower layer
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      |      │  '   │  "   │                │ "("  │ ")"  │  ?   │ "_"  ├──────╮
//  │  @   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ BKSP │
//  ├──────┤      │ "/"  │ "\"  | "|"  │                │ "{"  │ "}"  │  Ğ   │  Ü   ├──────┤
//  │ScrSht├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  İ   │
//  ├──────┤      |      │ "<"  │  ">" │                │ "["  │ "]"  │ "$"  │  "#" ├──────┤
//  │CPSLCK├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ "-"  │
//  ╰──────╯             │      ├──────╮                ╭──────┤  ">" │             ╰──────╯
//                       ╰──────┤      ├───────┬────────┤  "<" ├──────╯
//                              ╰──────┤       │ ENTER  ├──────╯
//                                     ╰───────┴────────╯ 
[_LOWER] = LAYOUT(
    AT_SIGN, _______, _______, LSFT(KC_2), KC_NONUS_BACKSLASH,      KC_ASTR, KC_LPRN, KC_UNDS, KC_PLUS, KC_BSPC,      
    LGUI(LSFT(KC_4)), _______, _______, BACKSLASH, VERTICAL_PIPE,            CURLY_OPEN, CURLY_CLOSE, KC_LBRC, KC_RBRC, KC_QUOT, 
    KC_CAPS, _______, _______, KC_GRV, LSFT(KC_GRV),                SQUARE_OPEN, SQUARE_CLOSE, DOLLAR_SIGN, NUMBER_SIGN, KC_EQL,
                                _______, _______, _______, KC_ENT, KC_GRV, LSFT(KC_GRV)
  ),

// Space: Navigation + Shift + Numbers
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  '   |  ^   │  +   │  %   │                │  &   │  /   │  (   │  )   ├──────╮
//  │  !   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  =   │
//  ├──────┤MSNCTL│SPTLGT│DICTTN|LNCHPD│                │ LEFT │ DOWN │  UP  │ RIGHT├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ BKSP │
//  ├──────┤      |      │ DND  │LCKOSX│                │LFTCLK│RGTCLK│SCRLCK│MDLCLK├──────┤
//  │ LSFT ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │      ├──────╮                ╭──────┤      │             ╰──────╯
//                       ╰──────┤ LGUI ├───────┬────────┤      ├──────╯
//                              ╰──────┤       │        ├──────╯
//                                     ╰───────┴────────╯ 
[_SPACE] = LAYOUT(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,      
    _______, KC_MISSION_CONTROL, KC_SPOTLIGHT, KC_DICTATION, KC_LAUNCHPAD,                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, 
    KC_LSFT, _______, _______, KC_DO_NOT_DISTURB, KC_LOCK_SCREEN,                 KC_MS_BTN1, KC_MS_BTN2, BALL_SCR, BALL_MCL, _______,
                                    _______, KC_LGUI, _______, _______, _______, _______
  ),

// Enter: Functions + Media Layer
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  F9  | F10  │ F11  │ F12  │                │C_PREV│ PGUP │  UP  │ MUTE ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ T-PLY│
//  ├──────┤  F5  │  F6  │  F7  |  F8  │                │ HOME │ LEFT │ DOWN │ RGHT ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ END  │
//  ├──────┤  F1  |  F2  │  F3  │  F4  │                │C_NEXT│PGDOWN│      │VLDOWN├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ VLUP │
//  ╰──────╯             │      ├──────╮                ╭──────┤      │             ╰──────╯
//                       ╰──────┤      ├───────┬────────┤ BKSP ├──────╯
//                              ╰──────┤ ENTER │        ├──────╯
//                                     ╰───────┴────────╯

  [_ENT] = LAYOUT(
    _______, KC_F9, KC_F10, KC_F11, KC_F12,             KC_MPRV, KC_PGUP, KC_UP, KC_MUTE, KC_MPLY,
    _______, KC_F5, KC_F6, KC_F7, KC_F8,                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, 
    _______, KC_F1, KC_F2, KC_F3, KC_F4,                KC_MNXT, KC_PGDN, _______, KC_VOLD, KC_VOLU,
                        _______, _______, KC_ENT, _______, KC_BSPC, _______
  ),

// RAISE layer
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  2   |  3   │  4   │  5   │                │  6   │  7   │  8   │  9   ├──────╮
//  │  1   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  0   │
//  ├──────┤      │      │      |      │                │  *   │ "-"  │ "\"  │ "|"  ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  ,   │
//  ├──────┤      |      │      │      │                │  #   │  "   │ "~"  │ "`"  ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ <>|  │
//  ╰──────╯             │      ├──────╮                ╭──────┤ BKSP │             ╰──────╯
//                       ╰──────┤      ├───────┬────────┤      ├──────╯
//                              ╰──────┤       │  ENT   ├──────╯
//                                     ╰───────┴────────╯ 
[_RAISE] = LAYOUT(
    KC_1, KC_2,   KC_3,   KC_4,   KC_5,                             KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     
    _______, _______, _______, _______, _______,                    KC_MINS, KC_EQL, BACKSLASH, VERTICAL_PIPE, KC_BSLS,
    _______, _______, _______, _______, _______,                    NUMBER_SIGN, KC_NUBS, TILDE, BACKTICK, KC_GRV,
                                _______, _______, _______, KC_ENT, _______, KC_BSPC
  ),



// Backspace layer
//  * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      |      │      │      │                │  /   │  7   │  8   │  9   ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  -   │
//  ├──────┤      │      │      |      │                │  ,   │  4   │  5   │  6   ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  +   │
//  ├──────┤      |      │      │ ENT  │                │  .   │  1   │  2   │  3   ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤  =   │
//  ╰──────╯             │      ├──────╮                ╭──────┤      │             ╰──────╯
//                       ╰──────┤      ├───────┬────────┤   O  ├──────╯
//                              ╰──────┤  SPC  │  BKSP  ├──────╯
//                                     ╰───────┴────────╯ 
[_BSPC] = LAYOUT(
    _______, _______, _______, _______, _______,                    KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,      
    _______, _______, _______, _______, _______,                    KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PPLS, 
    _______, _______, _______, _______, _______,                    KC_SLSH, KC_P1, KC_P2, KC_P3, KC_PEQL,
                                    _______, _______, KC_SPC, KC_BSPC, KC_P0, _______
  ),

};


// logo
#define ACH_LOGO { \
        0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x20, \
        0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0x20, \
        0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0x20, \
        0x00 \
}


// OLED Functions
#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool render_status(void) {
    static const char PROGMEM skywatch_logo[] = ACH_LOGO;
    oled_write_P(skywatch_logo, false);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("SPACE\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("ENTER\n"), false);
            break; 
        case 5:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case 6:
            oled_write_P(PSTR("BKSPC\n"), false);
            break;                                                      
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("¯\\_(ツ)_/¯"), false);
            // oled_write_ln_P(PSTR("Undefined"), false);

    }
 
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("\rCaps: ON  ") : PSTR("\rCaps: OFF  "), false);

    return false;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } 
    return false;
}
#endif
// END OLED functions


// Trackball
#ifdef POINTING_DEVICE_ENABLE
uint8_t white = 0;
uint8_t red = 255;
uint8_t green = 0;
uint8_t blue = 0;

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.y = 0; 
    }
    return mouse_report;
}

void ball_increase_hue(void){
      if(red!=255&&green!=255&&blue!=255){
        red =255;
      }
      if (red==255&&green<255&&blue==0){
       green += 15;
      } else if(green==255&&blue==0&&red>0){
        red-=15;
      } else if(red==0&&blue<255&&green==255){
        blue+=15;
      } else if(blue==255&&green>0&&red==0){
        green -= 15;
      } else if(green == 0&&blue==255&&red<255){
        red +=15;
      } else if(green ==0&&blue>0&&red==255){
        blue -=15;
      }
      pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void decrease_color(void){
  if (green>0){
    green-=15;
  }
  if (red>0){
    red-=15;
  }
  if (blue>0){
    blue-=15;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void cycle_white(void){
  if (white<255){
    white +=15;
  } else{
    white=0;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode){
    case  BALL_HUI:
      if(record->event.pressed){
        ball_increase_hue();
      }
      break;

    case BALL_WHT:
      if(record-> event.pressed){
        cycle_white();
      }
      break;

    case BALL_DEC:
    if(record-> event.pressed){
        decrease_color();
      }
      break;

    case BALL_SCR:
    if(record->event.pressed){
      set_scrolling = true;
    } else{
      set_scrolling = false;
    }
    break;

    case BALL_NCL:
      record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
      break;
    case BALL_RCL:
        record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
        break;
    case BALL_MCL:
        record->event.pressed?register_code(KC_BTN3):unregister_code(KC_BTN3);
        break;

    // macOS custom keycodes,
    case KC_SPOTLIGHT:
      if (record->event.pressed) {
        host_consumer_send(0x221);
      } else {
        host_consumer_send(0);
      }
      return false;
      break;
    case KC_DICTATION:
      if (record->event.pressed) {
        host_consumer_send(0xCF);
      } else {
        host_consumer_send(0);
      }
      return false;
      break;
    case KC_DO_NOT_DISTURB:
      if (record->event.pressed) {
        host_system_send(0x9B);
      } else {
        host_system_send(0);
      }
      return false;
      break;
    case KC_LOCK_SCREEN:
      if (record->event.pressed) {
        host_consumer_send(0x19E);
      } else {
        host_consumer_send(0);
      }
      return false;
      break;
    // END macOS custom keycodes


    }
  return true;
}
#endif
// END Trackball