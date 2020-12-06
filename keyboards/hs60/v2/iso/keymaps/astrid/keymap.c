/*
Astrid Brezina 2020
*/
#include QMK_KEYBOARD_H

enum _layers {
  _QWERTY,
  _FN,
  _ALTGR,
  _ADJUST,
};

#define FNL MO(_FN)
#define AGRL MO(_ALTGR)
#define ADJL MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap BASE: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  Ü|  ]|  R  |
   * |-----------------------------------------------------------|
   * |FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä| # | R |
   * |-----------------------------------------------------------|
   * |Shft| <>|  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------|
   */
 [_QWERTY] = LAYOUT_60_iso(
    KC_GESC,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
    KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,
    FNL,         KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS, KC_ENT,
    KC_LSFT,     KC_NUBS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,     KC_LGUI,  KC_LALT,                        KC_SPC,                                 AGRL,     KC_RGUI,  FNL,     KC_RCTL
  ),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ^°| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|    DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |MUT|V-D|V-U| UP|PSC| SC|BRK|RESET|   |
   * |-----------------------------------------------------------|
   * |      |CT1|   |   |   |   |PGU|LFT|DWN|RGT|APP|INS|        |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   |   |   |PGD|   |HOM|END|   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |     |   |
   * `-----------------------------------------------------------'
   */
  [_FN] = LAYOUT_60_iso(
    KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______,  _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_UP,   KC_PSCR,  KC_SLCK, KC_PAUS, RESET,
    _______,  C(KC_1), _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP,  KC_INS,  _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, KC_PGDN, _______, KC_HOME,  KC_END,  _______, _______,
    _______,  _______, _______,                   _______,                                      ADJL,    _______, _______, _______
  ),

  /* Keymap _ALTGR: alt-gr Layer
   * ,-----------------------------------------------------------.
   * |   | ¹ | ² | ³ | ¼ | ½ | ¬ | { | [ | ] | } | \ | ¸ |       |
   * |-----------------------------------------------------------|
   * |     | @ |   | € |   |   |   |   | < | > |   |   | ~ |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   | { | } |   |   |   |    |
   * |-----------------------------------------------------------|
   * |   |PIPE|   |   |   |   |   |   |   | [ | ] |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |     |    |   |
   * `-----------------------------------------------------------'
   */
  [_ALTGR] = LAYOUT_60_iso(
    XXXXXXX, ALGR(KC_1),    ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5), ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0), ALGR(KC_MINS), ALGR(KC_EQL), XXXXXXX,
    XXXXXXX, ALGR(KC_Q),    XXXXXXX,    ALGR(KC_E), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NUBS,    S(KC_NUBS), XXXXXXX,    XXXXXXX,       ALGR(KC_RBRC),
    XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    ALGR(KC_7), ALGR(KC_0), XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,
    XXXXXXX, ALGR(KC_NUBS), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    ALGR(KC_8), ALGR(KC_9), XXXXXXX,       XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,                                                             _______,    XXXXXXX,       ADJL,         XXXXXXX
  ),

    /* Keymap _ADJUST: adjust Layer

   */
  [_ADJUST] = LAYOUT_60_iso(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,                      _______,    XXXXXXX,       XXXXXXX, XXXXXXX
  ),

};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}