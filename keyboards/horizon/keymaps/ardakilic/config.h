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

#pragma once

// smooth scrolling calculation stuff
// #include <string.h>
// #include "lib/lib8tion/lib8tion.h"
// smooth scrolling caluclation stuff

#define USE_I2C

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

// LEFT LED pin is BO, Right LED pin id D5
#define MATRIX_ROW_PINS { D3, D2, B0, F4 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6, B5, B4, E6, D7, C6, D4, D5 }

// This is the original pinout, for reference
// #define MATRIX_ROW_PINS { D3, D2, D1, F4 }
// #define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6, B5, B4, E6, D7, C6, D4, D0 }


// Enable if you want to 
// #define PIMORONI_TRACKBALL_INVERT_X
// #define PIMORONI_TRACKBALL_INVERT_Y
// #define POINTING_DEVICE_ROTATION_90
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT

// trackball smoothing start
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/sofle/keymaps/foureight84/config.h
// #define POINTING_DEVICE_TASK_THROTTLE_MS 8
// Trackball smoothing


/* 

https://www.reddit.com/r/ErgoMechKeyboards/comments/qx7oqg/how_do_you_get_smoother_mouse_keys_with_qmkvia/
https://www.reddit.com/r/olkb/comments/72u8ou/qmk_mouse_keys_rock/
https://github.com/manna-harbour/miryoku_qmk/blob/bdb9fd81e8aa2afb3882f7c0f6ae2d3ba448ac93/users/manna-harbour_miryoku/config.h#L23-L33 
https://github.com/qmk/qmk_firmware/blob/master/keyboards/draculad/keymaps/pimoroni/keymap.c

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

*/