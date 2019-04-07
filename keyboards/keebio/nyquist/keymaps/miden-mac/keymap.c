#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 * | Esc      | 1   | 2   | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 0    | Bksp   |
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 * | Tab      | Q   | W   | E     | R     | T     | Y     | U     | I     | O     | P    | NONE   |
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 * | LCmd/Esc | A   | S   | D     | F     | G     | H     | J     | K     | L     | ;    | Enter  |
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 * | LShift   | Z   | X   | C     | V     | B     | N     | M     | ,     | .     | /    | RShift |
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 * | LCtl     | Cmd | Alt | Raise | Lower | Space | Space | Space | Lower | Raise | Menu | RCtl   |
 * |----------|-----|-----|-------|-------|-------|-------|-------|-------|-------|------|--------|
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,         KC_1,    KC_2,    KC_3,  KC_4,  KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC, \
  KC_TAB,         KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    XXXXXXX, \
  LCMD_T(KC_ESC), KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_ENT,  \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
  KC_LCTL,        KC_LCMD, KC_LALT, RAISE, LOWER, KC_SPC, KC_SPC, KC_SPC, LOWER,   RAISE,  KC_MENU, KC_RCTL  \
),


/* Lower
 *
 * Extended symbols, Vim navigation, and common hotkeys
 *
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 * | `   | F1    | F2    | F3    | F4        | F5  | F6    | F7   | F8     | F9    | - | = |
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 * | F10 | F11   | F12   | Wh D  |           |     | Wh Up |      |        |       | [ | ] |
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 * |     |       |       |       | Cmd-F     |     | Left  | Down | Up     | Right |   | ' |
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 * |     | Cmd-Z | Cmd-X | Cmd-C | Cmd-V     |     |       |      |        |       | \ |   |
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 * |     |       |       |       | Qwerty(T) |     |       |      | Qwerty |       |   |   |
 * |-----|-------|-------|-------|-----------|-----|-------|------|--------|-------|---|---|
 */

[_LOWER] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_MINUS, KC_EQL,  \
  KC_F10,  KC_F11,  KC_F12,  KC_WH_D, _______,     _______, KC_WH_U, _______, _______, _______,  KC_LBRC,  KC_RBRC, \
  _______, _______, _______, _______, G(KC_F),     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,  KC_QUOT, \
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V),     _______, _______, _______, _______, _______,  KC_BSLS,  _______, \
  _______, _______, _______, _______, OSL(QWERTY), _______, _______, _______, QWERTY,  _______,  _______,  _______ \
),

/* Raise
 *
 * Extended commands, Page navigation, and function keys
 *
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 * |      | F1  | F2  | F3        | F4 | F5 | F6    | F7    | F8    | F9     | NONE | Del  |
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 * | F10  | F11 | F12 |           |    |    | ScrLk | Pause | NumLk | Ins    |      | NONE |
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 * | Caps |     |     |           |    |    | Home  | PgDwn | PgUp  | End    |      |      |
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 * |      |     |     |           |    |    |       |       |       |        |      |      |
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 * |      |     |     | Qwerty(T) |    |    |       |       |       | Qwerty |      |      |
 * |------|-----|-----|-----------|----|----|-------|-------|-------|--------|------|------|
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,       KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   XXXXXXX, KC_DEL,  \
  KC_F10,  KC_F11,  KC_F12,  _______,     _______, _______, KC_SLCK, KC_PAUS, KC_NLCK, KC_INS,  _______, XXXXXXX, \
  KC_CAPS, _______, _______, _______,     _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
  _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, OSL(QWERTY), _______, _______, _______, _______, _______, QWERTY,  _______, _______  \
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

