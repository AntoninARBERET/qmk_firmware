#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_french_osx_universal.h"
#include "keymap_french_win_universal.h"

typedef union {
  uint32_t raw;
  struct {
    bool     macos :1;
  };
} user_config_t;

user_config_t user_config;

enum preonic_layers {
  _AZERTY_MAC,
  _AZERTY_WIN,
  _LOWER_MAC,
  _LOWER_WIN,
  _RAISE_MAC,
  _RAISE_WIN,
  _ADJUST_MAC,
  _ADJUST_WIN
};

enum preonic_keycodes {
  AZERTY_MAC = SAFE_RANGE,
  AZERTY_WIN,
  LOWER_MAC,
  LOWER_WIN,
  RAISE_MAC,
  RAISE_WIN,
  ADJUST_MAC,
  ADJUST_WIN,
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

// MAC OS
[_AZERTY_MAC] = LAYOUT_preonic_grid( \
  KC_NUBS,   FRM_AMPR, FRM_LEAC, FRM_DQUO, FRM_QUOT, FRM_LPRN, FRM_LEGR, FRM_EXLM, FRM_LCCE, FRM_LAGR, FRM_RPRN, FRM_MINS, \
  KC_TAB,  FRM_A,    FRM_Z,    FRM_E,    FRM_R,    FRM_T,    FRM_Y,    FRM_U,    FRM_I,    FRM_O,    FRM_P,    KC_BSPC,  \
  KC_ESC,  FRM_Q,    FRM_S,    FRM_D,    FRM_F,    FRM_G,    FRM_H,    FRM_J,    FRM_K,    FRM_L,    FRM_M,    FRM_CIRC, \
  KC_LSFT, FRM_W,    FRM_X,    FRM_C,    FRM_V,    FRM_B,    FRM_N,    FRM_M,    FRM_COMM, FRM_SCLN,  FRM_COLN, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER_MAC,   KC_SPC,  KC_SPC,  RAISE_MAC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

// Windows & Linux
[_AZERTY_WIN] = LAYOUT_preonic_grid( \
  /*KC_NUBS*/FRW_W,   FRW_AMPR, FRW_LEAC, FRW_DQUO, FRW_QUOT, FRW_LPRN, FRW_LEGR, FRW_EXLM, FRW_LCCE, FRW_LAGR, FRW_RPRN, FRW_MINS, \
  KC_TAB,  FRW_A,    FRW_Z,    FRW_E,    FRW_R,    FRW_T,    FRW_Y,    FRW_U,    FRW_I,    FRW_O,    FRW_P,    KC_BSPC,  \
  KC_ESC,  FRW_Q,    FRW_S,    FRW_D,    FRW_F,    FRW_G,    FRW_H,    FRW_J,    FRW_K,    FRW_L,    FRW_M,    FRW_CIRC, \
  KC_LSFT, FRW_W,    FRW_X,    FRW_C,    FRW_V,    FRW_B,    FRW_N,    FRW_M,    FRW_COMM, FRW_SCLN,  FRW_COLN, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER_WIN,   KC_SPC,  KC_SPC,  RAISE_WIN,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
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

 // Mac OS
[_LOWER_MAC] = LAYOUT_preonic_grid( \
  FRM_TILD, FRM_EXLM, FRM_AT,   FRM_HASH, FRM_DLR,  FRM_PERC, FRM_CIRC, _______, _______, FRM_AMPR, FRM_PIPE, KC_BSPC, \
  FRM_TILD, _______, KC_UP,   FRM_LEAC, FRM_DLR,  FRM_PERC, FRM_CIRC, _______, _______, FRM_PLUS, FRM_RPRN, KC_DEL,  \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT,FRM_LPRN, _______, _______, FRM_RPRN, _______, FRM_ASTR, FRM_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______,_______,_______, FRM_EXLM, FRM_EQL, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

//Windows & Linux
[_LOWER_WIN] = LAYOUT_preonic_grid( \
  FRW_TILD, FRW_EXLM, FRW_AT,   FRW_HASH, FRW_DLR,  FRW_PERC, FRW_CIRC, _______, _______, FRW_AMPR, FRW_PIPE, KC_BSPC, \
  FRW_TILD, _______, KC_UP,   FRW_LEAC, FRW_DLR,  FRW_PERC, FRW_CIRC, _______, _______, FRW_PLUS, FRW_RPRN, KC_DEL,  \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT,FRW_LPRN, _______, _______, FRW_RPRN, _______, FRW_ASTR, FRW_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______,_______,_______, FRW_EXLM, FRW_EQL, _______, \
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

// Mac OS
[_RAISE_MAC] = LAYOUT_preonic_grid( \
  FRM_GRV,  FRM_1,    FRM_2,    FRM_3,    FRM_4,    FRM_5,    FRM_6,    FRM_7,    FRM_8,    FRM_9,    FRM_0,    KC_BSPC, \
  FRM_GRV, FRM_LAGR,  FRM_2,   FRM_LEGR,  FRM_4,    FRM_5,    FRM_6,    FRM_7,    FRM_8,    FRM_9,    FRM_0,    KC_DEL,  \
  KC_DEL, _______, _______, _______, FRM_LCBR, AZERTY_WIN, _______,   FRM_RCBR, FRM_EQL,  FRM_LBRC, FRM_RBRC, FRM_BSLS, \
  _______,_______, _______, _______, _______, _______, _______,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

 // Windows
[_RAISE_WIN] = LAYOUT_preonic_grid( \
  FRW_GRV,  FRW_1,    FRW_2,    FRW_3,    FRW_4,    FRW_5,    FRW_6,    FRW_7,    FRW_8,    FRW_9,    FRW_0,    KC_BSPC, \
  FRW_GRV, FRW_LAGR,  FRW_2,   FRW_LEGR,  FRW_4,    FRW_5,    FRW_6,    FRW_7,    FRW_8,    FRW_9,    FRW_0,    KC_DEL,  \
  KC_DEL, _______, _______, _______, FRW_LCBR, AZERTY_MAC, _______,   FRW_RCBR, FRW_EQL,  FRW_LBRC, FRW_RBRC, FRW_BSLS, \
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

 // Mac OS
[_ADJUST_MAC] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, AZERTY_WIN, KC_DEL,  \
  _______, _______, MU_MOD,  _______, FRM_LBRC,  AG_NORM, AG_SWAP, FRM_RBRC , _______, _______, _______,  _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

//Windows & Linux
[_ADJUST_WIN] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, AZERTY_MAC, KC_DEL,  \
  _______, _______, MU_MOD,  _______, FRW_LBRC,  AG_NORM, AG_SWAP, FRW_RBRC , _______, _______, _______,  _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
  uprintf("Before switch case KL: kc: %u\n", keycode);
  #endif
  switch (keycode) {
        case AZERTY_MAC:
          if (record->event.pressed) {
            #ifdef CONSOLE_ENABLE
            uprintf("Set mac layer KL: kc: %u\n", keycode);
            #endif
            set_single_persistent_default_layer(_AZERTY_MAC);
            user_config.macos = 1;
            eeconfig_update_user(user_config.raw);
          }
          return false;
          break;
        case LOWER_MAC:
          if (record->event.pressed) {
            layer_on(_LOWER_MAC);
            update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST_MAC);
          } else {
            layer_off(_LOWER_MAC);
            update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST_MAC);
          }
          return false;
          break;
        case RAISE_MAC:
          uprintf("RAISE_MAC pressed \n");
          if (record->event.pressed) {
            layer_on(_RAISE_MAC);
            update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST_MAC);
          } else {
            layer_off(_RAISE_MAC);
            update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST_MAC);
          }
          return false;
          break;
        case AZERTY_WIN:
          uprintf("AZERTY_WIN pressed\n");
          if (record->event.pressed) {
            #ifdef CONSOLE_ENABLE
            uprintf("Set win layer KL: kc: %u\n", keycode);
            #endif
            set_single_persistent_default_layer(_AZERTY_WIN);
            user_config.macos = 0;
            eeconfig_update_user(user_config.raw);
          }
          return false;
          break;
        case LOWER_WIN:
          if (record->event.pressed) {
            layer_on(_LOWER_WIN);
            update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
          } else {
            layer_off(_LOWER_WIN);
            update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
          }
          return false;
          break;
        case RAISE_WIN:
          if (record->event.pressed) {
            layer_on(_RAISE_WIN);
            update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
          } else {
            layer_off(_RAISE_WIN);
            update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
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
    if (IS_LAYER_ON(_RAISE_MAC) || IS_LAYER_ON(_RAISE_WIN)) {
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
                if(user_config.macos){
                  layer_on(_ADJUST_MAC);
                }
                else{
                  layer_on(_ADJUST_WIN);
                }
            } else {
              if(user_config.macos){
                layer_off(_ADJUST_MAC);
              }
              else{
                layer_off(_ADJUST_WIN);
              }
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
    case RAISE_MAC:
    case RAISE_WIN:
    case LOWER_MAC:
      return false;
    case LOWER_WIN:
      return false;
    default:
      return true;
  }
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  // Debug
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
