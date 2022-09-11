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