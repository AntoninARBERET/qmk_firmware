/* Copyright 2015-2016 Jack Humbert
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

#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ² │ & │ é │ " │ ' │ ( │ - │ è │ _ │ ç │ à │ ) │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ * │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define FRW_SUP2 KC_GRV  // ²
#define FRW_AMPR KC_1    // &
#define FRW_LEAC KC_2    // é
#define FRW_DQUO KC_3    // "
#define FRW_QUOT KC_4    // '
#define FRW_LPRN KC_5    // (
#define FRW_MINS KC_6    // -
#define FRW_LEGR KC_7    // è
#define FRW_UNDS KC_8    // _
#define FRW_LCCE KC_9    // ç
#define FRW_LAGR KC_0    // à
#define FRW_RPRN KC_MINS // )
#define FRW_EQL  KC_EQL  // =
// Row 2
#define FRW_A    KC_Q    // A
#define FRW_Z    KC_W    // Z
#define FRW_E    KC_E    // E
#define FRW_R    KC_R    // R
#define FRW_T    KC_T    // T
#define FRW_Y    KC_Y    // Y
#define FRW_U    KC_U    // U
#define FRW_I    KC_I    // I
#define FRW_O    KC_O    // O
#define FRW_P    KC_P    // P
#define FRW_CIRC KC_LBRC // ^ (dead)
#define FRW_DLR  KC_RBRC // $
// Row 3
#define FRW_Q    KC_A    // Q
#define FRW_S    KC_S    // S
#define FRW_D    KC_D    // D
#define FRW_F    KC_F    // F
#define FRW_G    KC_G    // G
#define FRW_H    KC_H    // H
#define FRW_J    KC_J    // J
#define FRW_K    KC_K    // K
#define FRW_L    KC_L    // L
#define FRW_M    KC_SCLN // M
#define FRW_UGRV KC_QUOT // ù
#define FRW_ASTR KC_NUHS // *
// Row 4
#define FRW_LABK KC_NUBS // <
#define FRW_W    KC_Z    // W
#define FRW_X    KC_X    // X
#define FRW_C    KC_C    // C
#define FRW_V    KC_V    // V
#define FRW_B    KC_B    // B
#define FRW_N    KC_N    // N
#define FRW_COMM KC_M    // ,
#define FRW_SCLN KC_COMM // ;
#define FRW_COLN KC_DOT  // :
#define FRW_EXLM KC_SLSH // !

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ¨ │ £ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ % │ µ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │   │   │   │   │   │   │ ? │ . │ / │ § │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define FRW_1    S(FRW_AMPR) // 1
#define FRW_2    S(FRW_LEAC) // 2
#define FRW_3    S(FRW_DQUO) // 3
#define FRW_4    S(FRW_QUOT) // 4
#define FRW_5    S(FRW_LPRN) // 5
#define FRW_6    S(FRW_MINS) // 6
#define FRW_7    S(FRW_LEGR) // 7
#define FRW_8    S(FRW_UNDS) // 8
#define FRW_9    S(FRW_LCCE) // 9
#define FRW_0    S(FRW_LAGR) // 0
#define FRW_DEG  S(FRW_RPRN) // °
#define FRW_PLUS S(FRW_EQL)  // +
// Row 2
#define FRW_DIAE S(FRW_CIRC) // ¨ (dead)
#define FRW_PND  S(FRW_DLR)  // £
// Row 3
#define FRW_PERC S(FRW_UGRV) // %
#define FRW_MICR S(FRW_ASTR) // µ
// Row 4
#define FRW_RABK S(FRW_LABK) // >
#define FRW_QUES S(FRW_COMM) // ?
#define FRW_DOT  S(FRW_SCLN) // .
#define FRW_SLSH S(FRW_COLN) // /
#define FRW_SECT S(FRW_EXLM) // §

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │ ~ │ # │ { │ [ │ | │ ` │ \ │   │ @ │ ] │ } │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │   │ ¤ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define FRW_TILD ALGR(FRW_LEAC) // ~ (dead)
#define FRW_HASH ALGR(FRW_DQUO) // #
#define FRW_LCBR ALGR(FRW_QUOT) // {
#define FRW_LBRC ALGR(FRW_LPRN) // [
#define FRW_PIPE ALGR(FRW_MINS) // |
#define FRW_GRV  ALGR(FRW_LEGR) // ` (dead)
#define FRW_BSLS ALGR(FRW_UNDS) // (backslash)
#define FRW_AT   ALGR(FRW_LAGR) // @
#define FRW_RBRC ALGR(FRW_RPRN) // ]
#define FRW_RCBR ALGR(FRW_EQL)  // }
// Row 2
#define FRW_EURO ALGR(KC_E)   // €
#define FRW_CURR ALGR(FRW_DLR) // ¤


// DEPRECATED
#define FRW_AMP   FRW_AMPR
#define FRW_APOS  FRW_QUOT
#define FRW_LESS  FRW_LABK
#define FRW_OVRR  FRW_DEG
#define FRW_UMLT  FRW_DIAE
#define FRW_MU    FRW_MICR
#define FRW_GRTR  FRW_RABK
#define FRW_CCIRC FRW_CIRC
#define FRW_BULT  FRW_CURR
