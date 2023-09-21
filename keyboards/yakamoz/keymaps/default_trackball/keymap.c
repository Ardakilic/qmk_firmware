/* Copyright 2023 ozkan
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


enum yakamoz_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};


enum trackball_keycodes {
  BALL_HUI = SAFE_RANGE, //cycles hue
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Caps | Ctrl | Alt  | GUI  |Lower |Space |Scroll|RgtClk|Space |Raise | Left | Down |  Up  |Right |
 * `-------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_yakamoz(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SCRL, KC_MS_BTN2, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Caps | Ctrl | Alt  | GUI  |Lower |Space |Scroll|RgtClk|Space |Raise | Left | Down |  Up  |Right |
 * `-------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_yakamoz(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SCRL, KC_MS_BTN2, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Caps | Ctrl | Alt  | GUI  |Lower |Space |Scroll|RgtClk|Space |Raise | Left | Down |  Up  |Right |
 * `-------------------------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_yakamoz(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SCRL, KC_MS_BTN2, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_yakamoz(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | DEL |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_yakamoz(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ----------------RGB CONTROL----------------
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |BRGTH+| SAT+ | HUE+ |RGBMOD|  RGB |             |      |      |      |Qwerty|Colemk|Dvorak|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |BRGTH-| SAT- | HUE- |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |B_HUI |B_WHT |B_DEC |             | BTN1 | BTN2 | BTN3 |B_SCR |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Reset|Debug |EE_Clr|      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_yakamoz(
    _______, RGB_VAI, RGB_SAI, RGB_HUI,  RGB_MOD, RGB_TOG,                   _______, _______, _______, _QWERTY, _COLEMAK,            _DVORAK,
    _______, RGB_VAD, RGB_SAD, RGB_HUD,  _______, _______,                   _______, _______, _______, _______, _______,             _______,
    _______, _______, _______, BALL_HUI, BALL_WHT, BALL_DEC,                 KC_BTN1, KC_BTN2, KC_BTN3, BALL_SCR, QK_MUSIC_MODE_NEXT, QK_AUDIO_VOICE_NEXT,
    _______, _______, _______, _______,  _______, _______, QK_BOOT, DB_TOGG, EE_CLR,   _______, _______, _______, QK_MUSIC_TOGGLE,    QK_AUDIO_TOGGLE
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE


oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}


// logo
#define ACH_LOGO { \
        0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x20, \
        0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0x20, \
        0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0x20, \
        0x00 \
}


bool render_status(void) {
    static const char PROGMEM atreus_logo[] = ACH_LOGO;
    oled_write_P(atreus_logo, false);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("COLEMAK\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("DVORAK\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("RAISE \n"), false);
            break;
        case 5:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
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
    case _QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case _COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case _DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

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
    }
  return true;
}

#endif
