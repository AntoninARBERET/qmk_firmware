/* Copyright 2016 Sébastien Pérochon
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
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ @ │ & │ é │ " │ ' │ ( │ § │ è │ ! │ ç │ à │ ) │ - │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ ` │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ = │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define FRM_AT   KC_NUBS  // @
#define FRM_AMPR KC_1    // &
#define FRM_LEAC KC_2    // é
#define FRM_DQUO KC_3    // "
#define FRM_QUOT KC_4    // '
#define FRM_LPRN KC_5    // (
#define FRM_SECT KC_6    // §
#define FRM_LEGR KC_7    // è
#define FRM_EXLM KC_8    // !
#define FRM_LCCE KC_9    // ç
#define FRM_LAGR KC_0    // à
#define FRM_RPRN KC_MINS // )
#define FRM_MINS KC_EQL  // -
// Row 2
#define FRM_A    KC_Q    // A
#define FRM_Z    KC_W    // Z
#define FRM_E    KC_E    // E
#define FRM_R    KC_R    // R
#define FRM_T    KC_T    // T
#define FRM_Y    KC_Y    // Y
#define FRM_U    KC_U    // U
#define FRM_I    KC_I    // I
#define FRM_O    KC_O    // O
#define FRM_P    KC_P    // P
#define FRM_CIRC KC_LBRC // ^
#define FRM_DLR  KC_RBRC // $
// Row 3
#define FRM_Q    KC_A    // Q
#define FRM_S    KC_S    // S
#define FRM_D    KC_D    // D
#define FRM_F    KC_F    // F
#define FRM_G    KC_G    // G
#define FRM_H    KC_H    // H
#define FRM_J    KC_J    // J
#define FRM_K    KC_K    // K
#define FRM_L    KC_L    // L
#define FRM_M    KC_SCLN // M
#define FRM_LUGR KC_QUOT // ù
#define FRM_GRV  KC_NUHS // `
// Row 4
#define FRM_LABK KC_GRV // <
#define FRM_W    KC_Z    // W
#define FRM_X    KC_X    // X
#define FRM_C    KC_C    // C
#define FRM_V    KC_V    // V
#define FRM_B    KC_B    // B
#define FRM_N    KC_N    // N
#define FRM_COMM KC_M    // ,
#define FRM_SCLN KC_COMM // ;
#define FRM_COLN KC_DOT  // :
#define FRM_EQL  KC_SLSH // =

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ # │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ _ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ¨ │ * │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │   │   │   │   │   │   │   │   │   │   │ % │ £ │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ > │   │   │   │   │   │   │ ? │ . │ / │ + │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define FRM_HASH S(FRM_AT)   // #
#define FRM_1    S(FRM_AMPR) // 1
#define FRM_2    S(FRM_LEAC) // 2
#define FRM_3    S(FRM_DQUO) // 3
#define FRM_4    S(FRM_QUOT) // 4
#define FRM_5    S(FRM_LPRN) // 5
#define FRM_6    S(FRM_SECT) // 6
#define FRM_7    S(FRM_LEGR) // 7
#define FRM_8    S(FRM_EXLM) // 8
#define FRM_9    S(FRM_LCCE) // 9
#define FRM_0    S(FRM_LAGR) // 0
#define FRM_DEG  S(FRM_RPRN) // °
#define FRM_UNDS S(FRM_MINS) // _
// Row 2
#define FRM_DIAE S(FRM_CIRC) // ¨ (dead)
#define FRM_ASTR S(FRM_DLR)  // *
// Row 3
#define FRM_PERC S(FRM_LUGR) // %
#define FRM_PND  S(FRM_GRV)  // £
// Row 4
#define FRM_RABK S(FRM_LABK) // >
#define FRM_QUES S(FRM_COMM) // ?
#define FRM_DOT  S(FRM_SCLN) // .
#define FRM_SLSH S(FRM_COLN) // /
#define FRM_PLUS S(FRM_EQL)  // +

/* Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ • │  │ ë │ “ │ ‘ │ { │ ¶ │ « │ ¡ │ Ç │ Ø │ } │ — │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ Æ │ Â │ Ê │ ® │ † │ Ú │ º │ î │ Œ │ π │ Ô │ € │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ ‡ │ Ò │ ∂ │ ƒ │ ﬁ │ Ì │ Ï │ È │ ¬ │ µ │ Ù │   │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≤ │ ‹ │ ≈ │ © │ ◊ │ ß │ ~ │ ∞ │ … │ ÷ │ ≠ │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define FRM_BULT A(FRM_AT)   // •
#define FRM_APPL A(FRM_AMPR) //  (Apple logo)
#define FRM_LEDI A(FRM_LEAC) // ë
#define FRM_LDQU A(FRM_DQUO) // “
#define FRM_LSQU A(FRM_QUOT) // ‘
#define FRM_LCBR A(FRM_LPRN) // {
#define FRM_PILC A(FRM_SECT) // ¶
#define FRM_LDAQ A(FRM_LEGR) // «
#define FRM_IEXL A(FRM_EXLM) // ¡
#define FRM_CCCE A(FRM_LCCE) // Ç
#define FRM_OSTR A(FRM_LAGR) // Ø
#define FRM_RCBR A(FRM_RPRN) // }
#define FRM_MDSH A(FRM_MINS) // —
// Row 2
#define FRM_AE   A(FRM_A)    // Æ
#define FRM_CACI A(FRM_Z)    // Â
#define FRM_ECIR A(FRM_E)    // Ê
#define FRM_REGD A(FRM_R)    // ®
#define FRM_DAGG A(FRM_T)    // †
#define FRM_CUAC A(FRM_Y)    // Ú
#define FRM_MORD A(FRM_U)    // º
#define FRM_LICI A(FRM_I)    // î
#define FRM_OE   A(FRM_O)    // Œ
#define FRM_PI   A(FRM_P)    // π
#define FRM_OCIR A(FRM_CIRC) // Ô
#define FRM_EURO A(FRM_DLR)  // €
// Row 3
#define FRM_DDAG A(FRM_Q)    // ‡
#define FRM_COGR A(FRM_S)    // Ò
#define FRM_PDIF A(FRM_D)    // ∂
#define FRM_FHK  A(FRM_F)    // ƒ
#define FRM_FI   A(FRM_G)    // ﬁ
#define FRM_CIGR A(FRM_H)    // Ì
#define FRM_CIDI A(FRM_J)    // Ï
#define FRM_CEGR A(FRM_K)    // È
#define FRM_NOT  A(FRM_L)    // ¬
#define FRM_MICR A(FRM_M)    // µ
#define FRM_CUGR A(FRM_LUGR) // Ù
// Row 4
#define FRM_LTEQ A(FRM_LABK) // ≤
#define FRM_LSAQ A(FRM_W)    // ‹
#define FRM_AEQL A(FRM_X)    // ≈
#define FRM_COPY A(FRM_C)    // ©
#define FRM_LOZN A(FRM_V)    // ◊
#define FRM_SS   A(FRM_B)    // ß
#define FRM_TILD A(FRM_N)    // ~ (dead)
#define FRM_INFN A(FRM_COMM) // ∞
#define FRM_ELLP A(FRM_SCLN) // …
#define FRM_DIV  A(FRM_COLN) // ÷
#define FRM_NEQL A(FRM_EQL)  // ≠

/* Shift+Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ Ÿ │ ´ │ „ │   │   │ [ │ å │ » │ Û │ Á │   │ ] │ – │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │   │ Å │   │ ‚ │ ™ │   │ ª │ ï │   │ ∏ │   │ ¥ │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ Ω │ ∑ │ ∆ │ · │ ﬂ │ Î │ Í │ Ë │ | │ Ó │ ‰ │   │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≥ │ › │ ⁄ │ ¢ │ √ │ ∫ │ ı │ ¿ │   │ \ │ ± │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define FRM_CYDI S(A(FRM_AT))   // Ÿ
#define FRM_ACUT S(A(FRM_AMPR)) // ´ (dead)
#define FRM_DLQU S(A(FRM_LEAC)) // „
#define FRM_LBRC S(A(FRM_LPRN)) // [
#define FRM_LARI S(A(FRM_SECT)) // å
#define FRM_RDAQ S(A(FRM_LEGR)) // »
#define FRM_CUCI S(A(FRM_EXLM)) // Û
#define FRM_CAAC S(A(FRM_LCCE)) // Á
#define FRM_RBRC S(A(FRM_RPRN)) // ]
#define FRM_NDSH S(A(FRM_MINS)) // –
// Row 2
#define FRM_CARI S(A(FRM_Z))    // Å
#define FRM_SLQU S(A(FRM_R))    // ‚
#define FRM_TM   S(A(FRM_T))    // ™
#define FRM_FORD S(A(FRM_U))    // ª
#define FRM_LIDI S(A(FRM_I))    // ï
#define FRM_NARP S(A(FRM_P))    // ∏
#define FRM_YEN  S(A(FRM_DLR))  // ¥
// Row 3
#define FRM_OMEG S(A(FRM_Q))    // Ω
#define FRM_NARS S(A(FRM_S))    // ∑
#define FRM_INCR S(A(FRM_D))    // ∆
#define FRM_MDDT S(A(FRM_F))    // ·
#define FRM_FL   S(A(FRM_G))    // ﬂ
#define FRM_CICI S(A(FRM_H))    // Î
#define FRM_CIAC S(A(FRM_J))    // Í
#define FRM_CEDI S(A(FRM_K))    // Ë
#define FRM_PIPE S(A(FRM_L))    // |
#define FRM_COAC S(A(FRM_M))    // Ó
#define FRM_PERM S(A(FRM_LUGR)) // ‰
// Row 4
#define FRM_GTEQ S(A(FRM_LABK)) // ≥
#define FRM_RSAQ S(A(FRM_W))    // ›
#define FRM_FRSL S(A(FRM_X))    // ⁄
#define FRM_CENT S(A(FRM_C))    // ¢
#define FRM_SQRT S(A(FRM_V))    // √
#define FRM_INTG S(A(FRM_B))    // ∫
#define FRM_DLSI S(A(FRM_N))    // ı
#define FRM_IQUE S(A(FRM_COMM)) // ¿
#define FRM_BSLS S(A(FRM_COLN)) // (backslash)
#define FRM_PLMN S(A(FRM_EQL))  // ±

// DEPRECATED
#define FRM_AMP  FRM_AMPR
#define FRM_EACU FRM_LEAC
#define FRM_APOS FRM_QUOT
#define FRM_EGRV FRM_LEGR
#define FRM_CCED FRM_LCCE
#define FRM_AGRV FRM_LAGR
#define FRM_UGRV FRM_LUGR
#define FRM_LESS FRM_LABK
#define FRM_UMLT FRM_DIAE
#define FRM_GRTR FRM_RABK
