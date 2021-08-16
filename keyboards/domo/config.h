/*
  Copyright 2019 MayTD

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBBAB
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    May Do
#define PRODUCT         DoMo
#define DESCRIPTION     3x3 Macropad with a rotary encoder and oled display

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B3, B2, B6 }
#define MATRIX_COL_PINS { B1, E6, B4, B5 }
#define UNUSED_PINS

/* Rotary encoder */
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define TAP_CODE_DELAY 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Underlight configuration */
#define RGB_DI_PIN D3 
#define RGBLED_NUM 4
#define RGBLIGHT_ANIMATIONS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

