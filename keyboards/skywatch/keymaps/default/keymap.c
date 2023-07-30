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
#include "keymap_turkish_q.h"


enum skywatch_layer {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _FNL,
    _FNR,
    _ARROW,
    _ADJUST
};


enum custom_keycodes {
  BALL_HUI = SAFE_RANGE, //cycles hue
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};


#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FNL    MO(_FNL)
#define FNR    MO(_FNR)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)


#define FNR_SPC     LT(FNR, KC_SPC)
#define FNL_ENT     LT(FNL, KC_TAB)
#define ARROW_T LT(ARROW, KC_T)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// COLEMAK
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  W   │  F   │  P   │  G   │                │  J   │  L   │  U   │  Y   ├──────╮
//  │   Q  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ BSPC │
//  ├──────┤  R   │  S   │NAV T │  D   │                │  H   │  N   │  E   │  I   ├──────┤
//  │   A  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  O   │
//  ├──────┤CTL X │SFT C │  V   │  B   │                │  K   │  M   │SFT , │CTL . ├──────┤
//  │ALT Z ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ALT / │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 

  [_COLEMAK] = LAYOUT(
    TR_Q,          TR_W,          TR_F,          TR_P,     TR_G,               TR_J,  TR_L,  TR_U,             TR_Y,            KC_BSPC,  
    TR_A,          TR_R,          TR_S,          ARROW_T,  TR_D,               TR_H,  TR_N,  TR_E,             TR_IDOT,         TR_O,      
    LALT_T(TR_Z),  LCTL_T(TR_X),  LSFT_T(TR_C),  TR_V,     TR_B,               TR_K,  TR_M,  RSFT_T(TR_COMM),  RCTL_T(TR_DOT),  LALT_T(KC_PSLS),   
                                LOWER,    FNL_ENT, KC_BTN1,  BALL_SCR,  FNR_SPC,   RAISE
  ),

// COLEMAK DH
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  W   │  F   │  P   │  B   │                │  J   │  L   │  U   │  Y   ├──────╮
//  │   Q  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ BSPC │
//  ├──────┤  R   │  S   │NAV T │  G   │                │  M   │  N   │  E   │  I   ├──────┤
//  │   A  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  O   │
//  ├──────┤CTL X │SFT C │  D   │  V   │                │  K   │  H   │SFT , │CTL . ├──────┤
//  │ALT Z ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ALT / │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 

                    

  [_QWERTY] = LAYOUT(
    TR_Q,  TR_W,  TR_E,  TR_R,  TR_T,              TR_Y,  TR_U,  TR_IDOT,  TR_O,    TR_P,    
    TR_A,  TR_S,  TR_D,  TR_F,  TR_G,              TR_H,  TR_J,  TR_K,     TR_L,    TR_SCLN, 
    TR_Z,  TR_X,  TR_C,  TR_V,  TR_B,              TR_N,  TR_M,  TR_COMM,  TR_DOT,  TR_SLSH,  
            LOWER,    FNL_ENT, KC_BTN1,  KC_BTN2,  FNR_SPC,   RAISE

  ),
  
// LOWER
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │  (   │  )   │  =   │  &   ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  |   │
//  ├──────┤      │      │      │      │                │  {   │  }   │  _   │  $   ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  '   │
//  ├──────┤      │      │      │      │                │  [   │  ]   │  <   │  >   ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤  \   │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ ENTER  ├──────╯
//                                     ╰───────┴────────╯ 


  [_LOWER] = LAYOUT(
  _______,  _______,   _______,  _______,   _______,              TR_LPRN,  TR_RPRN,   TR_EQL,   TR_AMPR,  TR_PIPE, 
  _______,  _______,   _______,  _______,   _______,              TR_LCBR,  TR_RCBR,   TR_UNDS,  TR_DLR,   TR_QUOT,
  _______,  _______,   _______,  _______,   _______,              TR_LBRC,  TR_RBRC,   TR_LABK,  TR_RABK,  TR_BSLS,
                              LOWER,    FNL_ENT, KC_BTN1,  KC_BTN2, KC_ENT,   RAISE
                                                         

  ),

 
// RAISE
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤  1   │  2   │  3   │  +   │                │ F10  │  F1  │  F2  │  F3  ├──────╮
//  │  -   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ DEL  │
//  ├──────┤  4   │  5   │  6   │  "   │                │ F11  │  F4  │  F5  │  F6  ├──────┤
//  │  *   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤  7   │  8   │  9   │  0   │                │ F12  │  F7  │  F8  │  F9  ├──────┤
//  │  %   ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤  DEL  │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 
                  
   

  [_RAISE] = LAYOUT(
    TR_MINS,  TR_1,  TR_2,  TR_3,  TR_PLUS,              KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_DEL, 
    TR_ASTR,  TR_4,  TR_5,  TR_6,  TR_DQUO,              KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, 
    TR_PERC,  TR_7,  TR_8,  TR_9,  TR_0,                 KC_F12,  KC_7,    KC_F8,   KC_9,    _______, 
               LOWER,    KC_BSPC, KC_BTN1,  KC_BTN2,  FNR_SPC,   RAISE

  ),

 
// FNR 
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │  €   │  £   │  Ğ   │                │      │      │      │      ├──────╮
//  │ ESC  ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤  @   │  Ş   │  ₺   │  `   │                │      │      │      │      ├──────┤
//  │  !   ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤      │  Ç   │      │  #   │                │      │      │      │      ├──────┤
//  │ CAPS ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯


  [_FNR] = LAYOUT(
    KC_ESC,  _______,  TR_EURO,  TR_PND,  TR_GBRV,              _______,  _______,  _______,  _______,  _______, 
    TR_EXLM,  TR_AT,    TR_SCED,  TR_LIRA,  TR_GRV,               _______,  _______,  _______,  _______,  _______, 
    KC_CAPS,  _______,  TR_CCED,  _______,  TR_HASH,              _______,  _______,  _______,  _______,  _______, 
                         LOWER,    FNL_ENT, KC_BTN1,  KC_BTN2,  FNR_SPC,   RAISE
  ),

// FNL
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │      │      │  Ü   │      ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤  :   │
//  ├──────┤      │      │      │      │                │      │      │  I   │  I   ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤   Ö  │
//  ├──────┤      │      │      │      │                │      │      │  ^   │  ~   ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤   ?  │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 


  [_FNL] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  TR_UDIA,   _______,  TR_COLN, 
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  S(TR_I),  TR_I,      TR_ODIA, 
    _______,  _______,  _______,  _______,  _______,              _______,  _______,  TR_CIRC,  TR_TILD,   TR_QUES,  
                          LOWER,    FNL_ENT, KC_BTN1,  KC_BTN2,  KC_ENT,   RAISE
  ),

// ARROW
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤      │      │      │      │                │C_PREV│ PGUP │  UP  │ MUTE ├──────╮
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ T-PLY│
//  ├──────┤      │      │      │      │                │ HOME │ LEFT │ DOWN │ RGHT ├──────┤
//  │      ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤ END  │
//  ├──────┤      │      │      │      │                │C_NEXT│PGDOWN│      │VLDOWN├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤ VLUP │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯


  [_ARROW] = LAYOUT(
    _______,  _______,   _______,  _______,   _______,              KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,  
    _______,  _______,   _______,  _______,   _______,              KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,   
    _______,  _______,   _______,  _______,   _______,              KC_MNXT,   KC_PGDN,    _______,    KC_VOLD,     KC_VOLU,  
                              LOWER,    FNL_ENT, KC_BTN1,  KC_BTN2,  KC_ENT,   RAISE

  ),


// ADJUST
//         ╭──────┬──────┬──────┬──────╮                ╭──────┬──────┬──────┬──────╮
//  ╭──────┤ SAT+ │ HUE+ │ ANI+ │ TOG  │                │      │      │      │      ├──────╮
//  │ BRI+ ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤ SAT- │ HUE- │ ANI- │      │                │      │      │      │      ├──────┤
//  │ BRI- ├──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┤      │
//  ├──────┤      │      │      │      │                │REBOOT│ BOOT │EE_CLR│      ├──────┤
//  │      ├──────┴──────┼──────┼──────╯                ╰──────┼──────┼──────┴──────┤      │
//  ╰──────╯             │  ALT ├──────╮                ╭──────┤ WIN  │             ╰──────╯
//                       ╰──────┤LOWER ├───────┬────────┤RAISE ├──────╯
//                              ╰──────┤ SPACE │ SPACE  ├──────╯
//                                     ╰───────┴────────╯ 


  [_ADJUST] = LAYOUT(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,    RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD,   XXXXXXX,            BALL_HUI, BALL_WHT, BALL_DEC, XXXXXXX,     XXXXXXX,     
    XXXXXXX,   KC_BTN3, KC_BTN2,  KC_BTN1,    BALL_SCR,           QK_RBT,   QK_BOOT,   EE_CLR,  XXXXXXX,     XXXXXXX,     
                              KC_LALT,   LOWER,    FNL_ENT,  FNR_SPC,   RAISE,   KC_RGUI
  ),
};




layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}





// logo
#define ACH_LOGO { \
        0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x20, \
        0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0x20, \
        0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0x20, \
        0x00 \
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}


bool render_status(void) {
    static const char PROGMEM atreus_logo[] = ACH_LOGO;
    oled_write_P(atreus_logo, false);

    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("COLEMAK\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("LOWER\n"), false);
            break;            
        case 3:
            oled_write_P(PSTR("RAISE\n"), false);
            break;            
        case 4:
            oled_write_P(PSTR("LEFT SPC\n"), false);
            break;            
        case 5:
            oled_write_P(PSTR("RIGHT SPC \n"), false);
            break;            
        case 6:
            oled_write_P(PSTR("NAVIGATION\n"), false);
            break;            
        case 7:
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



enum combos {
  ESC,
  DEL,
  LGUI,
  RGUI,
  ENT,
  CAPS,
};


const uint16_t PROGMEM c_esc[] = {TR_W, TR_F, COMBO_END};
const uint16_t PROGMEM c_del[] = {TR_U, TR_Y, COMBO_END};
const uint16_t PROGMEM c_lcmd[] = {TR_R, TR_S, COMBO_END};
const uint16_t PROGMEM c_rcmd[] = {TR_E, TR_IDOT, COMBO_END};
const uint16_t PROGMEM c_enter[] = {TR_N, TR_E, COMBO_END};
const uint16_t PROGMEM c_caps[] = {TR_V, TR_B, COMBO_END};


combo_t key_combos[] = {
  [ESC]  = COMBO(c_esc, KC_ESC),
  [DEL]  = COMBO(c_del, KC_DEL),
  [LGUI] = COMBO(c_lcmd, KC_LGUI),
  [RGUI] = COMBO(c_rcmd, KC_LGUI),
  [ENT]  = COMBO(c_enter, KC_ENT),
  [CAPS] = COMBO(c_caps, KC_CAPS),
};