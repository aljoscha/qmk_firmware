/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

/* Combomap
 *
 * ,-----------------------------.      ,-----------------------------.
 * |     |    ESC    |     |     |      |     |    ESC    |    BSLH   |
 * |-----+-----+-----+-----+-----|      |-----------------------------|
 * |     |   BSPC   TAB    |     |      |    LES   COLN  GRT    |     |
 * |-----+-----+-----+--RMB+-LMB-+      |-----------------------------|
 * |     |   MINS   ENT    |     |      |    QUO   UNDR   |     |     |
 * `-----+-----+-----+-----+-----'      `-----------------------------'
 *  .-------------------------.           .-------------------------.
 *  |        |       |        |           |        |       |        |
 *  '-------------------------'           '-------------------------'
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+--------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
 * |------+-----+-----+-----+-----+      |-----+-----+-----+-----+--------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | SHFT/? |
 * `------+-----+-----+------+----'      `--------------------------------'
 *    .-------------------------.          .--------------------------.
 *    |TAB/ALT|ESC/META|SPC(SYM)|          |SPC(NUM)|ENT/META|BSPC/ALT|
 *    '-------------------------'          '--------------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_CTLA, KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_CTSC,
    KC_LSHZ, KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RLSH,

    MT(MOD_LALT, KC_TAB), MT(MOD_LGUI, KC_ESC), LT(SYMB, KC_SPC),     LT(NUMB, KC_SPC), MT(MOD_RGUI, KC_ENT), MT(MOD_LALT, KC_BSPC)
    ),

/* Keymap 1: Symbols layer
 * ,-----------------------------.      ,-----------------------------.
 * |  !  |  @  |  {  |  }  |  |  |      |  `  |  ~  |     |     |  \  |
 * |-----+-----+-----+-----+-----|      |-----------------------------|
 * |  #  |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |  '  |
 * |-----+-----+-----+-----+-----+      |-----------------------------|
 * |  %  |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |  _  |
 * `-----+-----+-----+-----+-----'      `-----------------------------'
 *          .-----------------.           .------------------.
 *          | MMB |  ;  |  =  |           |  =  |  ;  |  DEL |
 *          '-----------------'           '------------------'
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,          KC_GRV,  KC_TILD, _______, _______, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,          KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,          KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_UNDS,

    MT(MOD_LALT, CMB_TOG), MT(MOD_LGUI, KC_SCLN), KC_EQL,     KC_EQL, MT(MOD_RGUI, KC_SCLN), MT(MOD_LALT, KC_DEL)
    ),

/* Keymap 2: Pad/Function layer
 * ,------------------------------.      ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP |
 * |------+-----+-----+-----+-----+      |-----+-----+-----+-----+-------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *            .-----------------.           .-----------------.
 *            | F11 | F12|      |           |     | PLY | SKP |
 *            '-----------------'           '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,

    MT(MOD_LALT, KC_F11), MT(MOD_LGUI, KC_F12), _______,     _______, MT(MOD_RGUI, KC_MPLY), MT(MOD_LALT, KC_MNXT)
    )
};
