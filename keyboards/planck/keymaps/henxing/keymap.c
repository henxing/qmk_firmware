/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |  Tab | GUI  | Shift| Bksp | Ctrl |  Alt |Space |Raise |  -   |   '  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP(
  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_NO,   KC_NO,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,
  KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    KC_NO,   KC_NO,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN,
  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,
  KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, LOWER, KC_MINS, KC_QUOT, KC_ENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |  up  |   {  |   }  |      |      | pgup |   7  |   8  |   9  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  | left | down | right|   $  |      |      | pgdn |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |   ]  |   (  |   )  |   &  |      |      |   `  |   1  |   2  |   3  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | lower|  ins | super| shift| bksp | ctrl | alt  |space |  fn  |   .  |   0  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP(
  KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR,
  KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  KC_TRNS, KC_TRNS, KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS,
  KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_TRNS, KC_TRNS, KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS,
  RAISE,   KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | ins  | home |  up  |  end | pgup |      |      |  up  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  del | left | down | right| pgdn |      |      | down |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |volup |      |      |reset |      |      |      |  F1  |  F2  |  F3  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |voldn | super| shift| bksp | ctrl | alt  |space |  L0  | prtsc|scroll| pause|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP(
  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS, KC_TRNS, KC_UP,   KC_F7,  KC_F8,   KC_F9,   KC_F10,
  KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN, KC_TRNS, KC_TRNS, KC_DOWN, KC_F4,  KC_F5,   KC_F6,   KC_F11,
  KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_F12,
  KC_TRNS, KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  QWERTY, KC_PSCR, KC_SLCK, KC_PAUS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      // Toggle LOWER layer on when key pressed and off when released
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RAISE);
      }
      return false;
      break;
  }
  return true;
}
