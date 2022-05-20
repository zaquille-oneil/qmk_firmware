#include QMK_KEYBOARD_H
#include "drivers/led/issi/is31fl3733.h"

enum layer_names {
    _BASE,
    _F1,
    _F2,
    _F3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_65_ansi(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, TO(1), 
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, 
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN, 
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
      MO(1), KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[1] = LAYOUT_65_ansi(
      KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, TO(2), 
      KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_HOME, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    ),
	[2] = LAYOUT_65_ansi(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, S1_DEC, S1_INC, S2_DEC, S2_INC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, EF_DEC, EF_INC, H1_DEC, H1_INC, H2_DEC, H2_INC, BR_DEC, BR_INC, ES_DEC, ES_INC, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
	[3] = LAYOUT_65_ansi(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

// Sets the LEDs on the right-hand side of the keyboard
// ./keyboards/wilba_tech/wt_rgb_backlight.c:1661
layer_state_t layer_state_set_user(layer_state_t state) {
    IS31FL3733_set_color( 7+64-1, 0, 0, 0 );
    IS31FL3733_set_color( 6+64-1, 0, 0, 0 );
    
    switch (get_highest_layer(state)) {
      case _F1:
        IS31FL3733_set_color( 7+64-1, 0, 255, 0 );
        break;
      case _F2:
        IS31FL3733_set_color( 6+64-1, 255, 0, 255 );
        break;
      case _F3:
        IS31FL3733_set_color( 6+64-1, 0, 255, 0 );
        break;
      case _BASE:
      default:
        break;
    }

  return state;
}

// Overriding the definition in nk65.c so that caps lock doesn't change LEDs
bool led_update_user(led_t led_state)
{
    return false;
}

