#include QMK_KEYBOARD_H
#include "fehmer.h"


enum ibm_layers {
  _QWERTY,
  _FN,
};

#define FNL OSL(_FN)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* IBM XT keyboard layout
     * ,-------.  ,--------------------------------------------------------------------------.
     * | F1| F2|  |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  ß| BS|  BS  |NumLck |ScrLck |
     * |-------|  |--------------------------------------------------------------------------|
     * | F3| F4|  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  ü|  + |   |  7|  8|  9|  -|
     * |-------|  |------------------------------------------------------|Ent|---------------|
     * | F5| F6|  | Alt  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ö|  '|  `|   |  4|  5|  6|   |
     * |-------|  |----------------------------------------------------------------------|   |
     * | F7| F8|  |Shif|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift|PrS|  1|  2|  3|  +|
     * |-------|  |----------------------------------------------------------------------|   |
     * | F9|F10|  |  Ctrl |               Space                  | AltGr |   0   |   .   |   |
     * `-------'  `--------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_xt(
    KC_F1,  KC_F2,        TD(TD_ESC_CAPS), KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_BSPC, KC_BSPC,     KC_NLCK,      RESET,
    KC_F3,  KC_F4,        LT(_FN,KC_TAB) , KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,        KC_P7,  KC_P8,  KC_P9,  KC_PMNS,
    KC_F5,  KC_F6,        OSM_LALT,        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_GRV, KC_ENT, KC_P4,  KC_P5,  KC_P6,
    KC_F7,  KC_F8,        KC_LSPO,         KC_BSLS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSPC,KC_PSCR,KC_P1,  KC_P2,  KC_P3,  KC_PPLS,
    KC_F9, LGUI_T(KC_F10),OSM_LCTL,                              KC_SPC,                                       KC_RALT,          KC_P0,          KC_PDOT
    ),

    /* IBM XT keyboard function layer
     * ,-------.  ,--------------------------------------------------------------------------.
     * |   |   |  |   |   |   |   |   |   |   |   |   |   |   |   |   |      |       | RESET |
     * |-------|  |--------------------------------------------------------------------------|
     * |   |   |  |     |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |
     * |-------|  |------------------------------------------------------|   |---------------|
     * |   |   |  |      |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-------|  |----------------------------------------------------------------------|   |
     * |   |   |  |    |   |   |   |   |   |   |   |   |   |   |   |     |   |   |   |   |   |
     * |-------|  |----------------------------------------------------------------------|   |
     * |   |   |  |       |                                      |       |       |       |   |
     * `-------'  `--------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_xt(
    _______,  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  RESET,
    _______,  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,
    _______,  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,
    _______,  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
    _______,  _______,    _______,                                    _______,                                       _______,          _______,          _______
    ),

};
