/* Copyright 2015-2017 Jack Humbert
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
#include "fehmer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl|ShftAlt| Gui  | Alt  |Lower |    Space    |Raise |AltGr | Gui  |  Fn  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
TD(TD_ESC_CAPS), KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSPC,
LT(_FN, KC_TAB), KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_RBRC, KC_NUHS,
    KC_LSFT,     KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, RSFT_T(KC_ENT),
    OSM_LCTL,    OSM_LAS, OSM_LGUI, OSM_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   OSM_RALT, OSM_RGUI, FNL,     OSM_RCTL
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ^   |  F7  |  F8  |  F9  |  F12 |      |      |   7  |   8  |   9  |   =  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F4  |  F5  |  F6  |  F11 |      |      |   4  |   5  |   6  |      |  Ins |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F10 |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   ,  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, _______,     KC_7,    KC_8,    KC_9,   KC_RPRN,    _______,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______,     KC_4,    KC_5,    KC_6,   _______,    KC_INS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, _______,     KC_1,    KC_2,    KC_3,   _______,    _______,
    _______, _______, _______, _______, _______, _______, _______,     KC_0,    KC_COMM, KC_DOT, _______,    _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   °  |   !  |   "  |   §  |   $  |   %  |   &  |   /  |   (  |   )  |   ?  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  |   ´  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   |  |      |      |      |      |      |      |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   <  |   >  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    S(KC_GRV), KC_EXLM,       KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN,    S(KC_MINS), _______,
    _______,   _______,       _______, _______, _______, _______, _______, _______, ALGR(KC_7), ALGR(KC_0), KC_EQL,  ALGR(KC_MINS),
    _______,   ALGR(KC_NUBS), _______, _______, _______, _______, _______, _______, ALGR(KC_8), ALGR(KC_9), _______, _______,
    _______,   _______,       _______, _______, _______, _______, _______, _______, KC_NUBS,    S(KC_NUBS), _______, _______
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  up  |      |   ü  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | CTL-1|      |      |      |      | PgUp | Left | Down | Right|   ö  |  ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | PgDn |      | Home | End  |   ß  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Print|Scroll|Pause |      |             |      | Play | Vol- |      | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______ ,  KC_LBRC, KC_DEL,
    _______, C(KC_1), _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_PGDN, _______ ,KC_HOME, KC_END,    KC_MINS, _______,
    _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, KC_MPLY, KC_VOLD ,  _______, KC_VOLU
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______,  _______, _______, _______ ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}