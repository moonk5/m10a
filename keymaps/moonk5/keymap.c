#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

enum layers {
  _L0,
  _L1,
  _L2,
  _L3,
  _L4,
  _L5,
  _L6,
  _L7,
  _L8,
  _L9
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FN_ZERO LT(_L9, KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
     MPD           Firefox       Numpad        Layers
     +---+---+---+ +---+---+---+ +-----------+ +-----------+
     |PRV|PLY|NXT| |BAK|RFR|FWD| | 7 | 8 | 9 | |_L6|_L7|_L8|
     +---+---+---+ +---+---+---+ +---+---+---+ +---+---+---+
     |RWD|STP|FFD| |LTP|HOM|RTP| | 4 | 5 | 6 | |_L3|_L4|_L5|
     +---+---+---+ +---+---+---+ +---+---+---+ +---+---+---+
     |VLD|MTU|VLU| |PGD|END|PGU| | 1 | 2 | 3 | |_L0|_L1|_L2|
     +---+---+---+ +---+---+---+ +---+---+---+ +---+---+---+
     |#L0|  _L9  | |#L1|  _L9  | |#L2| _L9/0 | |#L9|       |
     +---+---+---+ +---+---+---+ +---+---+---+ +---+---+---+
     */

  [_L0] = {{KC_MPRV, KC_MPLY, KC_MNXT},
           {KC_MRWD, KC_MSTP, KC_MFFD},
           {KC_VOLD, KC_MUTE, KC_VOLU},
           {XXXXXXX, XXXXXXX, MO(_L9)}},
 
  [_L1] = {{LALT(KC_LEFT), LCTL(KC_R), LALT(KC_RIGHT)},
           {LCTL(KC_PGUP), KC_HOME, LCTL(KC_PGDN)},
           {KC_PGDN, KC_END, KC_PGUP},
           {XXXXXXX, XXXXXXX, MO(_L9)}},
  
  [_L2] = {{KC_7, KC_8, KC_9},
           {KC_4, KC_5, KC_6},
           {KC_1, KC_2, KC_3},
           {XXXXXXX, XXXXXXX, FN_ZERO}},
  
  [_L9] = {{DF(_L6), DF(_L7), DF(_L8)},
           {DF(_L3), DF(_L4), DF(_L5)},
           {DF(_L0), DF(_L1), DF(_L2)},
           {XXXXXXX, XXXXXXX, _______}}
};
