// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// layer 0
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_X MT(MOD_LSFT, KC_X)
#define OPT_D MT(MOD_LALT, KC_D)
#define GUI_F MT(MOD_LGUI, KC_F)
#define GUI_M MT(MOD_LGUI, KC_M)
#define ALT_COM MT(MOD_LALT, KC_COMMA)
#define SFT_DOT MT(MOD_LSFT, KC_DOT)
#define L2_SPA LT(2, KC_SPACE)
// #define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define CTL_ENT MT(MOD_LCTL,KC_ENTER)
#define TAB_ALT MT(MOD_LALT,KC_TAB)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_HYPR OSM(MOD_HYPR)

// layer 1
#define LAUNCH LGUI(KC_SPACE)
#define TMUX LCTL(KC_SPACE)
#define GUI_MIN MT(MOD_LGUI, KC_MINUS)
#define GUI_V MT(MOD_LGUI, KC_V)
#define LOCK HYPR_T(KC_F12)

// layer 2
#define PLAY LALT(LCTL(LSFT(KC_P)))
#define VOL_DO KC_AUDIO_VOL_DOWN
#define VOL_UP KC_AUDIO_VOL_UP
#define NEXT LALT(LCTL(LSFT(KC_G)))
#define MUTE KC_AUDIO_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        LOCK,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DELETE,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TAB_ALT,
        OSM_SFT, KC_Z,    SFT_X,   KC_C,    GUI_V,    KC_B,                KC_N,    GUI_M,  KC_COMMA, SFT_DOT, KC_EQUAL, CW_TOGG,
                                     OSM_MEH, L2_SPA, CTL_ENT,       KC_BSPC,  OSL(1), OSM_HYPR
    ),
    [1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
        _______, KC_AT,  KC_HASH, KC_LBRC, KC_RBRC, KC_PIPE,              KC_AMPR, KC_UNDS, KC_CIRC, KC_ASTR, KC_PERCENT, _______,
        _______, KC_DLR, KC_PLUS, KC_LCBR, KC_RCBR, KC_SLASH,             QK_REP,  KC_QUOT, KC_DQT,  KC_GRV,  KC_COLON,   _______,
        _______, KC_QUES, KC_EXLM, KC_LPRN, KC_RPRN, KC_BSLS,             KC_TILD, GUI_MIN, KC_LT,   KC_GT,  _______,  LOCK,
                                      QK_REP, LAUNCH,  TMUX,        _______,  _______,   _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, MUTE,    PLAY,    VOL_DO,  VOL_UP,  NEXT,                KC_AMPR, KC_UNDS, KC_CIRC, KC_ASTR, KC_PERCENT, _______,
        _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_END, _______,
        _______,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,                KC_TILD, GUI_MIN, KC_QUES, KC_EXLM, _______,  QK_ALT_REPEAT_KEY,
                                      _______, _______,  QK_BOOT,        KC_DELETE,  CW_TOGG,   QK_REP
    ),
};

