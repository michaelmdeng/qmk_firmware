#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define BMAC 1 // mac layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | BMAC |     |      |   6  |   7  |   8  |   9  |   0  | Bksp   |
 * |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |     |      |   Y  |   U  |   I  |   O  |   P  | NONE   |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * |LCtl/Esc|   A  |   S  |   D  |   F  |   G  |------|     |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |     |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
 *   |LCtl  | GUI  |  Alt | MDIA | SYMB |                                 |Space | SYMB | MDIA | Menu | RCtl |
 *   `----------------------------------'                                 `----------------------------------'
 *                                        ,-------------. ,-------------.
 *                                        | M1St | M1Pl | | M2St | M2Pl   |
 *                                 ,------|------|------| |------+--------+------.
 *                                 |      |      |      | |      |        |      |
 *                                 | Space| SYMB |------| |------| SYMB   |Space |
 *                                 |      |      | MStp | |      |        |      |
 *                                 `--------------------' `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,        KC_1,     KC_2,    KC_3,     KC_4,     KC_5,     TT(BMAC),
  KC_TAB,        KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,     _______,
  CTL_T(KC_ESC), KC_A,     KC_S,    KC_D,     KC_F,     KC_G,
  KC_LSFT,       KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     _______,
  KC_LCTL,       KC_LGUI,  KC_LALT, MO(MDIA), MO(SYMB),
                                                        _______, _______,
                                                                  _______,
                                              KC_SPC,   MO(SYMB), _______,
  // right hand
  _______,       KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC,
  _______,       KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     XXXXXXX,
                 KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_ENT,
  _______,       KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                           KC_SPC,  MO(SYMB), MO(MDIA), KC_MENU,  KC_RCTL,
  _______, _______,
  _______,
  _______,       MO(SYMB), KC_SPC
),

/* Keymap 0: Mac Basic Layer
 *
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |     |      |   6  |   7  |   8  |   9  |   0  | Bksp   |
 * |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |     |      |   Y  |   U  |   I  |   O  |   P  | NONE   |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * |LCtl/Esc|   A  |   S  |   D  |   F  |   G  |------|     |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |     |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
 *   |LCtl  | LCmd |  Alt | MDIA | SYMB |                                 |Space | SYMB | MDIA | Menu | RCtl |
 *   `----------------------------------'                                 `----------------------------------'
 *                                        ,-------------. ,-------------.
 *                                        | M1St | M1Pl | | M2St | M2Pl   |
 *                                 ,------|------|------| |------+--------+------.
 *                                 |      |      |      | |      |        |      |
 *                                 | Space| SYMB |------| |------| SYMB   |Space |
 *                                 |      |      | MStp | |      |        |      |
 *                                 `--------------------' `----------------------'
 */
[BMAC] = LAYOUT_ergodox(
  // left hand
  KC_ESC,        KC_1,     KC_2,    KC_3,     KC_4,     KC_5,     _______,
  KC_TAB,        KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,     _______,
  LCMD_T(KC_ESC),KC_A,     KC_S,    KC_D,     KC_F,     KC_G,
  KC_LSFT,       KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     _______,
  KC_LCTL,       KC_LCMD,  KC_LALT, MO(MDIA), MO(SYMB),
                                                        _______, _______,
                                                                  _______,
                                              KC_SPC,   MO(SYMB), _______,
  // right hand
  _______,       KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC,
  _______,       KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     XXXXXXX,
                 KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_ENT,
  _______,       KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                           KC_SPC,  MO(SYMB), MO(MDIA), KC_MENU,  KC_RCTL,
  _______, _______,
  _______,
  _______,       MO(SYMB), KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------. ,--------------------------------------------------.
 * | `       |  F1  |  F2  |  F3  |  F4  |  F5  |      | |      |  F6  |  F7  |  F8  |  F9  |   -  |   =    |
 * |---------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * | F10     |  F11 |  F12 | WhD  |      |      |      | |      | WhUp |      |      |      |   [  |   ]    |
 * |---------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |         |      |      |      | Find |      |------| |------| Left | Down |  Up  |Right |      |   '    |
 * |---------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |         | CtlZ | CtlX | CtlC | CtlV |      |      | |      |      |      |      |      |   \  |        |
 * `---------+------+------+------+------+-------------' `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                             |      |      |      |      |      |
 *   `-----------------------------------'                             `----------------------------------'
 *                                       ,-------------. ,-------------.
 *                                       |      |      | |      |      |
 *                                ,------|------|------| |------+------+------.
 *                                |      |      |      | |      |      |      |
 *                                |      |      |------| |------|      |      |
 *                                |      |      |      | |      |      |      |
 *                                `--------------------' `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    _______,
  KC_F10,  KC_F11,  KC_F12,  KC_WH_D, _______,  _______,  _______,
  _______, _______, _______, _______, KC_FIND,  _______,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  _______,  _______,
  _______, _______, _______, _______, _______,
                                                _______,  _______,
                                                          _______,
                                      _______,  _______,  _______,
  // right hand
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_MINUS, KC_EQL,
  _______, KC_WH_U, _______, _______, _______,  KC_LBRC,  KC_RBRC,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,  KC_QUOT,
  _______, _______, _______, _______, _______,  KC_BSLS,  _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------. ,--------------------------------------------------.
 * |        |      |      |      |      |      |      | |      |      |      |      |      | NONE |  Del   |
 * |--------+------+------+------+------+-------------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |ScrLk |Pause |NumLk | Ins  |      |  NONE  |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * | Caps   |      |      |      |      |      |------| |------| Home |PgDwn | PgUp | End  |      |  Play  |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------' `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   `----------------------------------'                             `----------------------------------'
 *                                      ,-------------. ,-------------.
 *                                      |      |      | |      |      |
 *                               ,------|------|------| |------+------+------.
 *                               |      |      |      | |      |      |      |
 *                               |      |      |------| |------|      |      |
 *                               |      |      |      | |      |      |      |
 *                               `--------------------' `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, XXXXXXX, KC_DEL,
  _______, _______, _______, _______, _______, _______, XXXXXXX,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
