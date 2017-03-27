#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

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
[_QW] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,   KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,   KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL,  KC_LALT, KC_SPC,  MO(_RS),  KC_MINS, KC_QUOT, KC_ENT  }
},

/*
 *  !       @     up     {    }        ||     pgup    7     8     9    *
 *  #     left   down  right  $        ||     pgdn    4     5     6    +
 *  [       ]      (     )    &        ||       `     1     2     3    \
 * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
[_RS] = { /* [> RAISE <] */
  {KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR},
  {KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  KC_NO,   KC_NO,   KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS},
  {KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_NO,   KC_NO,   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS},
  {TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL}
},

/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 *       volup             reset      ||             F1    F2    F3   F12
 *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
 */
[_LW] = { /* [> LOWER <] */
  {KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,   KC_NO,   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10},
  {KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN, KC_NO,   KC_NO,   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11},
  {KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, RESET,   KC_NO,   KC_NO,   KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12},
  {KC_TRNS, KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  DF(_QW), KC_PSCR, KC_SLCK, KC_PAUS}
}};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};
