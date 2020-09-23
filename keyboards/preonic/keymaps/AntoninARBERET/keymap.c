#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_french_osx.h"

enum preonic_layers {
  _AZERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  AZERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* AZERTY
 * ,-----------------------------------------------------------------------------------.
 * |   @  |   &  |   é  |   "  |   '  |   (  |   è  |   !  |   ç  |   à  |   )  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bkspc|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  ^   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   W  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   ;  |   :  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_AZERTY] = LAYOUT_preonic_grid( \
  KC_NUBS,   FR_AMPR, FR_LEAC, FR_DQUO, FR_QUOT, FR_LPRN, FR_LEGR, FR_EXLM, FR_LCCE, FR_LAGR, FR_RPRN, FR_MINS, \
  KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    KC_BSPC,  \
  KC_ESC,  FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_CIRC, \
  KC_LSFT, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_M,    FR_COMM, FR_SCLN,  FR_COLN, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |      |      |   &  |   |  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |      |  up  |   é  |   $  |   %  |   ^  |      |      |   +  |   -  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | left | down |right |   (  |      |      |   )  |      |   *  |   /  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   !  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  FR_TILD, FR_EXLM, FR_AT,   FR_HASH, FR_DLR,  FR_PERC, FR_CIRC, _______, _______, FR_AMPR, FR_PIPE, KC_BSPC, \
  FR_TILD, _______, KC_UP,   FR_LEAC, FR_DLR,  FR_PERC, FR_CIRC, _______, _______, FR_PLUS, FR_RPRN, KC_DEL,  \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT,FR_LPRN, _______, _______, FR_RPRN, _______, FR_ASTR, FR_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______,_______,_______, FR_EXLM, FR_EQL, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   à  |   2  |   è  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |   {  |      |      |   }  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |   @  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  FR_GRV,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    KC_BSPC, \
  FR_GRV, FR_LAGR,  FR_2,   FR_LEGR,  FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    KC_DEL,  \
  KC_DEL, _______, _______, _______, FR_LCBR, _______, _______,   FR_RCBR, FR_EQL,  FR_LBRC, FR_RBRC, FR_BSLS, \
  _______,_______, _______, _______, _______, _______, _______,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |   [  |AGnorm|AGswap|   ]  |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|Aud on|AudOff|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  _______, FR_LBRC,  AG_NORM, AG_SWAP, FR_RBRC , _______, _______, AZERTY,  _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case AZERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_AZERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
