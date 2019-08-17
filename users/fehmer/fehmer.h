/*
 Christian Fehmer 2018-2019
*/
#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

#define LEADER_TIMEOUT 500
#define TAPPING_TERM 200

//define space cadet shift to send open and closed parenthesis
#define LSPO_KEY KC_8
#define RSPC_KEY KC_9

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

//one shot modifier shortcuts
#define OSM_LALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_LAS OSM(MOD_LALT|MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RGUI OSM(MOD_RGUI)

// tapdance names
typedef enum {
  TD_ESC_CAPS = 0,
  TD_TAB_ESC = 1,
} TAPDANCE;
