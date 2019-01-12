/*
 Christian Fehmer 2018
*/
#include QMK_KEYBOARD_H

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0  // Default layer
#define FN   1  // Function layer

// Special Actions and Media Keys
#define MUTE KC_MUTE  // Mute sound
#define VOLU KC_VOLU  // Volume increase
#define VOLD KC_VOLD  // Volume decrease
#define M_UP KS_MS_UP // Mouse UP

#define INSE KC_INS   // Insert here
#define HOME KC_HOME  // Go to beginning of line
#define ENDI KC_END   // go to end of line
#define PSCR KC_PSCR  // Print Screen
#define SLCK KC_SLCK  // go to end of line
#define PGDN KC_PGDN  // go to end of line
#define PGUP KC_PGUP  // go to end of line
#define PLPS KC_MPLY  // Play/Pause
#define PAUS KC_PAUS  // Pause button
#define MNXT KC_MNXT  // next track
#define MPRV KC_MPRV  // prev track
#define MSTP KC_MSTP  // stop playing
#define MSEL KC_MSEL  // Select media (Start playing it)
#define MAIL KC_MAIL  // Open default mail app
#define CALC KC_CALC  // Open default calculator app
#define MYCM KC_MYCM  // Open default file manager

#define _______ KC_TRNS
#define XXXXX    KC_NO

enum {
  TD_ESC_CAPS = 0,
};


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

  [BASE] = LAYOUT_60_iso(
    TD(TD_ESC_CAPS),          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,     KC_BSPC,
    KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,
    MO(FN),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS,    KC_ENT,
    KC_LSPO,KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
    KC_LCTL,   KC_LGUI, KC_LALT,                   KC_SPC,                                            KC_RALT, KC_RGUI, MO(FN), KC_RCTL
  ),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ^°| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|    DEL|
   * |-----------------------------------------------------------|
   * |     |MB1|MSU|MB2|MWU|   |MUT|V-D|V-U| UP|PSC| SC|BRK|     |
   * |-----------------------------------------------------------|
   * |RESET |MSL|MSD|MSR|MWD|   |   |PGU|LFT|DWN|RGT|APP|INS|    |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |PGD|HOM|END|   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [FN] = LAYOUT_60_iso(
    KC_GRAVE,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______,           KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, MUTE   , VOLD   , VOLU   , KC_UP  , KC_PSCR, KC_SLCK, KC_PAUS,
    RESET  ,           KC_MS_L  , KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP, KC_INS , _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_HOME, KC_END, _______, _______,
    _______,  _______, _______,                   _______,                                          _______, _______, _______, _______
  ),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};


enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
