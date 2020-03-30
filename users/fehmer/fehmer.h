/*
 Christian Fehmer 2018-2019
*/
#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

#define LEADER_TIMEOUT 500
#define TAPPING_TERM 200

//define space cadet shift to send open and closed parenthesis
#define LSPO_KEYS KC_LSFT, KC_TRNS, KC_W
#define RSPC_KEYS KC_RSFT, KC_TRNS, KC_Q

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

//one shot modifier shortcuts
/*#define OSM_LALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_LAS OSM(MOD_LALT|MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RGUI OSM(MOD_RGUI)
*/
#define OSM_LALT KC_LALT
#define OSM_RALT KC_RALT
#define OSM_LCTL KC_LCTL
#define OSM_RCTL KC_RCTL
#define OSM_LAS KC_LALT|KC_LSFT
#define OSM_LGUI KC_LGUI
#define OSM_RGUI KC_RGUI
// tapdance names
typedef enum {
  TD_ESC_CAPS = 0,
  TD_TAB_ESC = 1,
} TAPDANCE;
