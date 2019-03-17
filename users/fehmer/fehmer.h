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


typedef enum {
  TD_ESC_CAPS = 0,
} TAPDANCE;


enum function_id {
    SHIFT_ESC,
};