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

// This is the personal keymap of Ian Sterling (@xyverz). It is based on the keymap by
// Chris Gerber (@gerbercj), with the addition of persistent layers like the Planck and
// Preonic keyboards by Jack Humbert.

#include QMK_KEYBOARD_H
#include "keycodes/dual.h"
#include "keycodes/combo.h"

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->event.key.row == 3) {
        return true;
    }
    return false;
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    if (record->event.key.row == 3) {
        return false;
    }
    return true;
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
	|   A  |   O  |   E  |   U  |   I  |              |   D  |   H  |   T  |   N  | CTL/S|
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|  ;   |   Q  |   J  |   K  |   X  | RAI/`|| RAI/\|   B  |   L  |   M  |   W  | ALT/Z|
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|RESET |  CTL |  ALT |   -  |  ESC | TAB  || ENTER|  Spc |  /   | SFT  | GUI  |Adjust|
	`-----------------------------------------'`-----------------------------------------' */
  [_DVORAK] = LAYOUT(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,     KC_G,    KC_C,    KC_R,     KC_V,
    CTLA,    KC_O,    LOWE,    KC_U,    KC_I,                      KC_D,    KC_H,    LOWT,    KC_N,     KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   RAIGRV,  RAIPIP,   KC_B,     KC_L,    KC_M,    KC_W,     KC_Z,
    RESET  ,  OSMCTL,  OSMALT, GUI_T(KC_TAB), SFT_T(KC_ESC), KC_MINS, KC_SLSH, SFT_T(KC_SPC),   KC_ENTER, OSMSFT, OSMGUI,  TO(_ADJUST)
  ),

  /* LOWER Layer
	,----------------------------------.              ,----------------------------------.
	|   !  |   @  |   #  |   $  |   %  |              |   =  |  7   |   8  |   9  | *    |
	|------+------+------+------+------|              |------+------+------+------+------|
	|   ^  | Left |  UP  | Right|   &  |              |   +  |  4   |   5  |   6  | BKSP |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	| COPY |PASTE | Down |   )  |   ]  |  *   ||  *   |   "  |  1   |   2  |   3  |      |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |   (  | [    | CTL  ||  ALT | SFT  | GUI  |   .  |   0  |      |
	`-----------------------------------------'`-----------------------------------------'*/
  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_EQL,  KC_7, KC_8, KC_9, KC_ASTR,
    KC_CIRC, KC_LEFT, KC_UP,   KC_RGHT, KC_AMPR,                   KC_0, KC_4, KC_5, KC_6, KC_BSPC,
    KC_COPY, KC_PASTE,KC_DOWN, KC_RPRN, KC_RBRC, KC_ASTR, KC_ASTR, MC_REG,  KC_1, KC_2, KC_3, KC_F12,
    RESET  , _______, _______, OSMCTL, OSMALT,  OSMCTL,  OSMALT, OSMSFT,OSMGUI,KC_DOT,KC_0, TO(_ADJUST)
  ),

  /* RAISE Layer
	,----------------------------------.              ,----------------------------------.
	|   1  |   2  |   3  |   4  |   5  |              |   6  |  F7  |  F8  |  F9  |   0  |
	|------+------+------+------+------|              |------+------+------+------+------|
	| CAPS |Bright|VOL + |      | Home |              | PgDn |  F4  |  F5  |  F6  | F11  |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|      | Dim  |VOL - | Right| End  |MacLck||      | PgUp |  F1  |  F2  |  F3  | F12  |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      | Del  |      ||      | Ins  |      |      |  F0  |      |
	`-----------------------------------------'`-----------------------------------------'*/
  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_MUTE,     T_DVORAK, _______,                   _______, KC_F7, KC_F8, KC_F9,_______,
    KC_CAPS, KC_BRIU, KC__VOLUP,   T_LOWER, KC_HOME,                   KC_PGUP, KC_F4, KC_F5, KC_F6, KC_F11,
    _______, KC_BRID, KC__VOLDOWN, T_RAISE, KC_END,  _______, _______, KC_PGDN, KC_F1, KC_F2, KC_F3, KC_F12,
    RESET  , _______, _______,     _______, KC_DEL,  _______, _______, KC_INS,_______,_______,KC_F10,TO(_ADJUST)
  ),

  /* ADJUST Layer
	,----------------------------------.              ,----------------------------------.
	|  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  |
	|------+------+------+------+------|              |------+------+------+------+------|
	|  F11 |      |      |      |      |              |      | PrSc | ScLk | Paus | F12  |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|      |QWERTY|COLEMK|DVORAK|DVORMC|      ||      |      |      |      |      |      |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      | RESET|
	`-----------------------------------------'`-----------------------------------------'*/
  [_ADJUST] = LAYOUT(
    T_LOWER, T_RAISE, _______, _______, _______,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 ,
    KC_F11,  _______, _______, _______, _______,                   _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_F12 ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RESET  , _______, _______, _______,T_DVORAK, _______, _______, _______, _______, _______, _______, _______
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
