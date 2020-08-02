#include QMK_KEYBOARD_H
#include "fehmer.h"

extern keymap_config_t keymap_config;
enum _layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP(
TD(TD_ESC_CAPS),      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,           KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_BSPC,
LT(_FN, KC_TAB),      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,           KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_DEL,
LT(_FN, KC_TAB),      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,           KC_H,        KC_J,        KC_K,        KC_L,        KC_RBRC,     KC_NUHS,
        KC_LSFT,      KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,           KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     RSFT_T(KC_ENT),
        OSM_LCTL,     OSM_LAS,     OSM_LGUI,    OSM_LALT,    LOWER,       KC_SPC,         KC_SPC,      RAISE,       OSM_RALT,    OSM_RGUI,    FNL,         OSM_RCTL,
                                                                          KC_ENTER,       KC_BSPC
),
[_LOWER] = KEYMAP(
        KC_GRV,       _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
        _______,      KC_F7,       KC_F8,       KC_F9,       KC_F12,      _______,        _______,     KC_7,        KC_8,        KC_9,        KC_RPRN,     _______,
        _______,      KC_F4,       KC_F5,       KC_F6,       KC_F11,      _______,        _______,     KC_4,        KC_5,        KC_6,        _______,     KC_INS,
        _______,      KC_F1,       KC_F2,       KC_F3,       KC_F10,      _______,        _______,     KC_1,        KC_2,        KC_3,        _______,     _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     KC_0,        KC_COMM,     KC_DOT,      _______,     _______,
                                                                          _______,        _______
),
[_RAISE] = KEYMAP(
      S(KC_GRV),      _______,     _______,     _______,     _______,     _______,        _______,     _______,     KC_NUBS,     S(KC_NUBS),  S(KC_MINS),  _______,
        _______,      KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,        KC_CIRC,     KC_AMPR,     KC_ASTR,     KC_LPRN,     S(KC_MINS),  _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     ALGR(KC_7),  ALGR(KC_0),  KC_EQL,      ALGR(KC_MINS),
        _______,    ALGR(KC_NUBS), _______,     _______,     _______,     _______,        _______,     _______,     ALGR(KC_8),  ALGR(KC_9),  _______,     _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     KC_NUBS,     S(KC_NUBS),  _______,    _______,
                                                                          _______,        _______
),
[_FN] = KEYMAP(
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     KC_DEL,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     KC_UP,       _______ ,    KC_LBRC,     _______,
        _______,      C(KC_1),     _______,     _______,     _______,     _______,        KC_PGUP,     KC_LEFT,     KC_DOWN,     KC_RIGHT,    KC_SCLN,     KC_QUOT,
        _______,      _______,     _______,     _______,     _______,     _______,        KC_PGDN,     _______ ,    KC_HOME,     KC_END,      KC_MINS,     _______,
        _______,      KC_PSCR,     KC_SLCK,     KC_PAUS,     _______,     _______,        _______,     _______,     KC_MPLY,     KC_VOLD,     _______,     KC_VOLU,
                                                                          _______,        KC_DEL
),
[_ADJUST] = KEYMAP(
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
        _______,      RESET,       DEBUG,       _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
        _______,      _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     _______,
                                                                          _______,        _______
)

};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state,     _LOWER,     _RAISE,     _ADJUST);
}
