/*
 Christian Fehmer 2018-2019
*/
#include "fehmer.h"

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_TAB_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
};