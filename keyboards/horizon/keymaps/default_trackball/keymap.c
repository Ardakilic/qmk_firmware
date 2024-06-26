/* Copyright 2021 Steven Karrmann
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
  BALL_HUI = SAFE_RANGE, //cycles hue
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};

enum layer_names {
    _BASE,
    _SYMBOL,
    _FUNCTION
};


#ifdef PIMORONI_TRACKBALL_ENABLE

void run_trackball_cleanup(void) {
    // if (trackball_is_scrolling()) {
    //     trackball_set_rgbw(RGB_CYAN, 0x00);
    // } else if (trackball_get_precision() != 1.0) {
    //     trackball_set_rgbw(RGB_GREEN, 0x00);
    // } else {
    // trackball_set_rgbw(RGB_MAGENTA, 0x00);
    // }
}

void keyboard_post_init_keymap(void) {
    // trackball_set_precision(1.5);*i
    // trackball_set_rgbw(RGB_MAGENTA, 0x00);
}
// void shutdown_keymap(void) { trackball_set_rgbw(RGB_RED, 0x00); }

// static bool mouse_button_one, trackball_button_one;

void trackball_register_button(bool pressed, enum mouse_buttons button){
    report_mouse_t currentReport = pointing_device_get_report();
    if (pressed) {
        currentReport.buttons |= button;
    } else {
        currentReport.buttons &= ~button;
    }
    pointing_device_set_report(currentReport);
}
#endif

/*
// Smooth mouse scroll movement START
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/sofle/keymaps/foureight84/keymap.c
static uint32_t       last_mouse_activity = 0;
static report_mouse_t last_mouse_report   = {0};
static bool           is_scrolling        = false;

report_mouse_t smooth_mouse_movement(report_mouse_t mouse_report) {
    // Linear interpolation and ease-in-out
    static fract8 fract = 0.5;
    int8_t        x     = 0;
    int8_t        y     = 0;
    int8_t        h     = 0;
    int8_t        v     = 0;

    if (!is_scrolling) {
        x = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
        y = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
    } else {
        h = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
        v = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
    }

    // update the new smoothed report
    mouse_report.x = x;
    mouse_report.y = y;
    mouse_report.h = h;
    mouse_report.v = v;

    return mouse_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    if (has_mouse_report_changed(&last_mouse_report, &mouse_report)) {
        last_mouse_activity = timer_read32();
        memcpy(&last_mouse_report, &mouse_report, sizeof(mouse_report));
    }

    return smooth_mouse_movement(mouse_report);
}
// Smooth mousescroll  movement END
*/

// RGB LED on Trackball
void keyboard_post_init_user(void) {
    pimoroni_trackball_set_rgbw(0,0,0,80);
}



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
  }
  return true;
}




layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        pimoroni_trackball_set_rgbw(0,0,0,80);
        break;
    case _SYMBOL:
        pimoroni_trackball_set_rgbw(0,153,95,0);
        break;
    case _FUNCTION:
        pimoroni_trackball_set_rgbw(153,113,0,0);
        break;
    default: //  for any other layers, or the default layer
        pimoroni_trackball_set_rgbw(0,0,0,80);
        break;
    }
  return state;
}
// RGB Led on Trackball


// LAYERS
#define MO_SYMB MO(_SYMBOL)
#define MO_FUNC MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        KC_EQL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ESC , KC_ENT , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_APP , KC_DEL , KC_TAB , MO_SYMB, MO_FUNC, KC_SPC , KC_BSPC, KC_APP , KC_RGUI, KC_RALT, KC_RCTL
    ),
    [_SYMBOL] = LAYOUT(
        KC_TILD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
        KC_PLUS, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_HASH, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
        _______, KC_AT  , KC_LBRC, KC_RBRC, KC_BSLS, KC_PERC, _______, _______, KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   KC_SLCK, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   KC_CLCK, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, _______,
        BALL_SCR, BALL_HUI, BALL_WHT, BALL_DEC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};