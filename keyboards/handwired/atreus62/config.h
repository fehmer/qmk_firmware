/*
Copyright 2020 Christian Fehmer <github2020@fehmer.info>
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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6062
#define DEVICE_VER 0x0001
#define MANUFACTURER fehmer
#define PRODUCT Atreus62
#define DESCRIPTION Handwired Atreus with number row

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { B2, B3, B7, F4, F6, F5 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, C6, C7, D6, D7, B4, B5, B6, F7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 10
#define DEBOUNCING_DELAY 5

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#endif