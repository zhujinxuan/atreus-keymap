/* Copyright 2020 Ian Sterling
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

// This is the personal keymap of Ian Sterling (@xyverz). It is based on the
// keymap by Chris Gerber (@gerbercj), with the addition of persistent layers
// like the Planck and Preonic keyboards by Jack Humbert.
// clang-format off

 #include QMK_KEYBOARD_H
 #include "keycodes/dual.h"
 #include "keycodes/combo.h"

 bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->event.key.row == 3) {
        return true;
    }
    return false;
 }

 /* void keyboard_post_init_user(void) { */
 /*     // Customise these values to desired behaviour */
 /*     debug_enable=true; */
 /*     debug_matrix=true; */
 /*     //debug_keyboard=true; */
 /*     //debug_mouse=true; */
 /* } */

 // Initial keymap for Xyverz's Keyboardio Atreus

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak Layer
    ,----------------------------------.              ,----------------------------------.
    |   '  |   ,  |   .  |   P  |   Y  |              |   F  |   G  |   C  |   R  |   V  |
    |------+------+------+------+------|              |------+------+------+------+------|
    |   A  |   O  |   E  |   U  |   I  |              |   D  |   H  |   T  |   N  |   S  |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |  ;   |   Q  |   J  |   K  |   X  |      | |     |   B  |   L  |   M  |   W  |   Z  |
    |------+------+------+------+------+------| |-----+------+------+------+------+------|
    |QK_RBT |  CTL |  ALT |G/TAB | S/ESC|      | |     | S/SPC|C/ENT | ALT  | GUI  |Adjust|
    `-----------------------------------------'`-----------------------------------------' */
  [_DVORAK] = LAYOUT(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,     KC_G,    KC_C,    KC_R,     KC_V,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,     KC_H,    KC_T,    KC_N,     KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, TT(_RAISE),  TT(_RAISE),    KC_B,     KC_L,    KC_M,    KC_W,     KC_Z,
    QK_RBT  ,OSMCTL,  OSMALT, GUI_T(KC_TAB), SFT_T(KC_ESC), TT(_LOWER), TT(_LOWER), SFT_T(KC_SPC),   CTL_T(KC_ENTER), OSMALT, OSMGUI,  OSMSFT
  ),

  /* LOWER Layer
    ,----------------------------------.              ,----------------------------------.
    |   !  |   @  |   #  |   $  |   %  |              |   =  |  7   |   8  |   9  | *    |
    |------+------+------+------+------|              |------+------+------+------+------|
    |   ^  | Left |  UP  | Right|   &  |              |   0  |  4   |   5  |   6  | BKSP |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |   +  |  -   | Down |  *   |  /    |      ||      |   +  |  1   |   2  |   3  | F12  |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      |      |      |      ||      | SFT  | CTL  |  ALT |   GUI|      |
    `-----------------------------------------'`-----------------------------------------'*/
  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_EQL,  KC_7, KC_8, KC_9, KC_ASTR,
    KC_CIRC, KC_LEFT, KC_UP,   KC_RGHT, KC_AMPR,                   KC_0, KC_4, KC_5, KC_6, KC_BSPC,
    KC_PLUS, KC_PMNS,KC_DOWN,  KC_ASTR, KC_PSLS, KC_ASTR, KC_ASTR, KC_PLUS,  KC_1, KC_2, KC_3, KC_F12,
    QK_RBT  , _______, _______, OSMGUI, OSMSFT,  TT(_LOWER), TT(_LOWER), OSMSFT,OSMCTL, _______, _______, TO(_ADJUST)
  ),

  /* RAISE Layer
    ,----------------------------------.              ,----------------------------------.
    |      |      | MUTE |      |      |              |   6  |  F7  |  F8  |  F9  |  F10 |
    |------+------+------+------+------|              |------+------+------+------+------|
    | CAPS |Bright|VOL + |      | Home |              | PgDn |  F4  |  F5  |  F6  | F11  |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |      | Dim  |VOL - |      | End  |      ||      | PgUp |  F1  |  F2  |  F3  | F12  |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      |      | Del  |      ||      | Ins  |      |      |  F0  |      |
    `-----------------------------------------'`-----------------------------------------'*/
  [_RAISE] = LAYOUT(
    _______, KC_2,    KC_MUTE, _______, _______,                   _______, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_CAPS, KC_BRIU, KC_VOLU, _______, KC_HOME,                   KC_PGUP, KC_F4, KC_F5, KC_F6, KC_F11,
    _______, KC_BRID, KC_VOLD, _______, KC_END,  _______, _______, KC_PGDN, KC_F1, KC_F2, KC_F3, KC_F12,
    QK_RBT , _______, _______, _______, KC_DEL,  _______, _______, KC_INS,_______,_______,_______,TO(_ADJUST)
  ),

  /* ADJUST Layer
    ,----------------------------------.              ,----------------------------------.
    |  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  |
    |------+------+------+------+------|              |------+------+------+------+------|
    |DVORAK| RAISE| LOWER|      |      |              |      | PrSc | ScRL | Paus | F11  |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |      |QWERTY|COLEMK|DVORAK|DVORMC|      ||      |      |      |      |      | F12  |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      |      |      |      ||      |      |      |      |      |      |
    `-----------------------------------------'`-----------------------------------------'*/
  [_ADJUST] = LAYOUT(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    T_DVORAK, T_LOWER, T_RAISE, _______, _______,                   _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12 ,
    QK_RBT , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
 };

 static uint16_t key_timer = 0;
 /* layer_state_t layer_state_set_user(layer_state_t state) { */
 /*   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
 /* } */
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 #ifdef CONSOLE_ENABLE

    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    if (timer_elapsed(key_timer) < 1000) {
        uprintf("time: %u\n", timer_elapsed(key_timer));
        // do something if less than 100ms have passed
    }
    key_timer = timer_read();
 #endif
  if (record->event.key.row == 3) {
      capOff();
  }
  switch (keycode) {
  case MC_REG:
      SEND_STRING("\"+");
      return false;
      break;
  }
  return true;
 }
