#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_french_osx_universal.h"
#include "keymap_french_win_universal.h"
#include <time.h>

bool cncr_mode = false;
bool rand_init = false;


const uint16_t alpha_codes[26] = {
  FRM_A,    FRM_Z,    FRM_E,    FRM_R,      FRM_T,    FRM_Y,    FRM_U,      FRM_I,    FRM_O,    FRM_P,  \
  FRM_Q,    FRM_S,    FRM_D,    FRM_F,      FRM_G,    FRM_H,    FRM_J,      FRM_K,    FRM_L,    FRM_M, \
  FRM_W,    FRM_X,    FRM_C,    FRM_V,      FRM_B,    FRM_N, \
};

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
  BACKLIT,
  CN_MODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* AZERTY
 * ,-----------------------------------------------------------------------------------.
 * |   @  |   &  |   é  |   "  |   '  |   (  |   è  |   !  |   ç  |   à  |   )  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bkspc|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  ^   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |  up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Brite|  GUI | Alt  |Lower |    Space    |Raise |Alt Gr| left | down | right|
 * `-----------------------------------------------------------------------------------'
 */

// MAC OS
[_AZERTY_MAC] = LAYOUT_preonic_grid( \
  KC_NUBS,  FRM_AMPR, FRM_LEAC, FRM_DQUO, FRM_QUOT,   FRM_LPRN, FRM_SECT, FRM_LEGR,   FRM_EXLM, FRM_LCCE, FRM_LAGR, FRM_MINS, \
  KC_TAB,   FRM_A,    FRM_Z,    FRM_E,    FRM_R,      FRM_T,    FRM_Y,    FRM_U,      FRM_I,    FRM_O,    FRM_P,    KC_BSPC,  \
  KC_ESC,   FRM_Q,    FRM_S,    FRM_D,    FRM_F,      FRM_G,    FRM_H,    FRM_J,      FRM_K,    FRM_L,    FRM_M,    FRM_CIRC, \
  KC_LSFT,  FRM_W,    FRM_X,    FRM_C,    FRM_V,      FRM_B,    FRM_N,    FRM_COMM,   FRM_SCLN, FRM_COLN, KC_UP,    KC_ENT,  \
  KC_LCTL,  BACKLIT,  KC_LALT,  KC_LGUI,  LOWER_MAC,  KC_SPC,   KC_SPC,   RAISE_MAC,  KC_LGUI,  KC_LEFT,  KC_DOWN,  KC_RIGHT  \
),

// Windows & Linux
[_AZERTY_WIN] = LAYOUT_preonic_grid( \
  FRW_SUP2, FRM_AMPR, FRM_LEAC, FRM_DQUO, FRM_QUOT,   FRM_LPRN, FRM_SECT, FRM_LEGR,   FRM_EXLM, FRM_LCCE, FRM_LAGR, FRM_MINS, \
  KC_TAB,   FRM_A,    FRM_Z,    FRM_E,    FRM_R,      FRM_T,    FRM_Y,    FRM_U,      FRM_I,    FRM_O,    FRM_P,    KC_BSPC,  \
  KC_ESC,   FRM_Q,    FRM_S,    FRM_D,    FRM_F,      FRM_G,    FRM_H,    FRM_J,      FRM_K,    FRM_L,    FRM_M,    FRW_CIRC, \
  KC_LSFT,  FRM_W,    FRM_X,    FRM_C,    FRM_V,      FRM_B,    FRM_N,    FRW_COMM,   FRW_SCLN, FRW_COLN, KC_UP,    KC_ENT,  \
  KC_LCTL,  BACKLIT,  KC_LGUI,  KC_LALT,  LOWER_WIN,  KC_SPC,   KC_SPC,   RAISE_WIN,  KC_ALGR,  KC_LEFT,  KC_DOWN,  KC_RIGHT  \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |   &  |   |  |      |      |   &  |   |  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  up  |   é  |   $  |   +  |   -  |      |      |   +  |   -  | Bcksp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | left | down |right |   (  |   *  |   /  |   )  |      |   *  |   /  |   %  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   <  |      |      |      |   =  |   !  |      |      |   /  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      | Alt  |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

 // Mac OS
[_LOWER_MAC] = LAYOUT_preonic_grid( \
  FRM_TILD, _______,  _______, _______,   _______,  FRM_AMPR, FRM_PIPE, _______,  _______, FRM_AMPR,  FRM_PIPE, KC_DEL, \
  _______ , _______,  KC_UP,   FRM_LEAC,  FRM_DLR,  FRM_PLUS, FRM_MINS, _______,  _______, FRM_PLUS,  FRM_MINS, KC_BSPC,  \
  KC_DEL,   KC_LEFT,  KC_DOWN, KC_RIGHT,  FRM_LPRN, FRM_ASTR, FRM_SLSH, FRM_RPRN, _______, FRM_ASTR,  FRM_SLSH, FRM_PERC, \
  _______,  FRM_LABK, _______, _______,   _______,  FRM_EQL,  FRM_EXLM,  _______,  _______, FRM_SLSH,  FRM_EQL,  _______, \
  KC_LCTL,  _______,  _______, KC_LALT,   _______,  _______,  _______,  _______,  KC_MNXT, KC_VOLD,   KC_VOLU,  KC_MPLY \
),

//Windows & Linux
[_LOWER_WIN] = LAYOUT_preonic_grid( \
  FRW_TILD, _______, _______,  _______, _______,  FRM_AMPR, ALGR(S(KC_L)),  _______,  _______,  FRM_AMPR, ALGR(S(KC_L)),  KC_DEL, \
  _______, _______, KC_UP,   FRW_LEAC, FRW_DLR,   FRM_PLUS, FRM_MINS,       _______,  _______,  FRM_PLUS, FRM_MINS,       KC_BSPC,  \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT,FRW_LPRN,   FRM_ASTR, FRM_SLSH,       FRW_RPRN, _______,  FRM_ASTR, FRM_SLSH,       FRM_PERC, \
  _______, KC_NUBS, _______, _______, _______,    FRM_EQL,  FRM_EXLM,       _______,  _______,  FRM_EXLM, FRM_EQL,        _______, \
  KC_LCTL, _______, _______, KC_LALT, _______,    _______,  _______,        _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,        KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |   &  |   |  |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   à  |      |   è  |      |   +  |   -  |      |      |      |      | Bcksp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |   {  |   *  |   /  |   }  |      |      |      |   %  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   >  |      |   ç  |      |   =  |   !  |      |      |   \  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      | Alt  |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

// Mac OS
[_RAISE_MAC] = LAYOUT_preonic_grid( \
  _______,  _______,  _______, _______,   _______,  FRM_AMPR, FRM_PIPE, _______,  _______,  _______,  _______,  KC_DEL, \
  _______,  FRM_LAGR, _______, FRM_LEGR,  _______,  FRM_PLUS, FRM_MINS, _______,  _______,  _______,  _______,  KC_BSPC,  \
  KC_DEL,   _______,  _______, _______,   FRM_LCBR, FRM_ASTR, FRM_SLSH, FRM_RCBR, _______,  _______,  _______,  FRM_PERC, \
  _______,  FRM_RABK, _______, FRM_LCCE,  _______,  FRM_EQL,  FRM_EXLM, _______,  _______,  FRM_BSLS,  _______, _______, \
  KC_LCTL,  _______,  _______, KC_LALT,   _______,  _______,  _______,  _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY  \
),

 // Windows
[_RAISE_WIN] = LAYOUT_preonic_grid( \
  _______,  _______,    _______,  _______,  _______,  FRM_AMPR, ALGR(S(KC_L)),  _______,  _______, FRW_9,   FRW_0,    KC_DEL, \
  _______,  FRW_LAGR,   _______,  FRW_LEGR, _______,  FRM_PLUS, FRM_MINS,       _______,  _______, _______, _______,  KC_BSPC,  \
  KC_DEL,   _______,    _______,  _______,  FRW_LCBR, FRM_ASTR, FRM_SLSH,       FRW_RCBR, _______, _______, FRM_FRSL, FRM_PERC, \
  _______,  S(KC_NUBS), _______,  FRM_LCCE, _______,  FRM_EQL,  FRM_EXLM,       _______,  _______, FRM_BSLS, _______, _______, \
  KC_LCTL,  _______,    _______,  KC_LALT,  _______,  _______,  _______,        _______,  KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY  \
    ), 

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Ms Up |      |      |  F16 |  F17 |L clic|R clic|up scr|  OS  | Print|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Ms lft|Ms dwn|Ms rgt|   [  |  F18 |  F19 |   ]  |      |dn scr| Reset| Debug|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |MuMod |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|Aud on|AudOff|AGnorm|AGswap| Cncr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |   Alt|      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

// Mac OS
[_ADJUST_MAC] = LAYOUT_preonic_grid( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,  \
  _______,  _______,  KC_MS_U,  _______,   _______, KC_F16,  KC_F17,  KC_BTN1,  KC_BTN2,  KC_WH_U,  AZERTY_WIN, KC_PSCR,  \
  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  FRM_LBRC, KC_F18,  KC_F19,  FRM_RBRC, _______,  KC_WH_D,  RESET,      DEBUG, \
  MU_MOD,   MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,   MI_OFF,  AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,    CN_MODE, \
  KC_LCTL,  _______,  _______,  KC_LALT,  _______,  _______, _______, _______,  _______,  _______,  _______,    KC_SLEP  \
), 

//Windows & Linux
[_ADJUST_WIN] = LAYOUT_preonic_grid( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,      KC_F12,  \
  _______,  _______,  KC_MS_U,  _______,  _______,  KC_F16,   KC_F17,   KC_BTN1,  KC_BTN2,  KC_WH_U, AZERTY_MAC,  KC_PSCR,  \
  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  FRW_LBRC, KC_F18,   KC_F19,   FRW_RBRC, _______,  KC_WH_D, RESET,       DEBUG, \
  MU_MOD,   MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,    MI_OFF,   AU_ON,    AU_OFF,   AG_NORM, AG_SWAP,     CN_MODE, \
  KC_LCTL,  _______,  _______,  KC_LALT,  _______,  _______,  _______,  _______,  _______,  _______, _______,     KC_SLEP  \
)


};


bool is_alpha(uint16_t keycode){
  int i;
  for(i = 0; i < 26; i++){
    if(alpha_codes[i] == keycode){
      return true;
    }
  }
  return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
  #endif
  switch (keycode) {
        case AZERTY_MAC:
          if (record->event.pressed) {
            #ifdef CONSOLE_ENABLE
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
          if (record->event.pressed) {
            #ifdef CONSOLE_ENABLE
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
        case CN_MODE:
          if (record->event.pressed) {
            cncr_mode = !cncr_mode;
          }
          break;
      }
    if(record->event.pressed && cncr_mode && is_alpha(keycode)){
      if(!rand_init){
        srand(117);
        rand_init = true;
      }
      if(rand()>RAND_MAX/2){
        register_code(KC_LSFT);
        tap_code(S(keycode));
        unregister_code(KC_LSFT);
        return false;
      }
      else{
        return true;
      }
    }else{
      return true;
    }
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
  debug_enable=false;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
