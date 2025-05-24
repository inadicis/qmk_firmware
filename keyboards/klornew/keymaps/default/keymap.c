#include <stdint.h>
#include QMK_KEYBOARD_H
#include "klornew.h"

enum layer_names {
    _BASE_QWERTZ,
    _SYMBOLS,
    _NUMBERS,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    // LOWER,
    // RAISE,
    // ADJUST,
    // OS_SWAP,
    // MAKE_H,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
   ┌───────────────────────────────────────────────────────────┐
   │ b a s e QWERTZ                                            │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │Ctrl/Esc │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    `    │    Z    │ Shift/X │ Opt/C   │ Cmd/V   │    B    ││ PlayPau││ NextTra││    N    │    M    │  Alt/,  │ Shift/. │OSM Shift│Caps Word│
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │ Meh     │ L2/Space│ L1/Tab  │  Enter  ││   TG(3) │  Bspc   │ OSL(1)  │  Hyper  │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */
    //

   [_BASE_QWERTZ] = LAYOUT_polydactyl(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D,  KC_F,    KC_G,                          KC_H,      KC_J,     KC_K,    KC_L,     KC_SEMICOLON,  KC_QUOTE,
KC_GRAVE,  KC_Z, MT(MOD_LSFT, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LGUI,KC_V),     KC_B,     KC_MPLY,   KC_MNXT,  KC_N,     MT(MOD_LGUI, KC_M),     MT(MOD_LALT, KC_COMMA), MT(MOD_LSFT, KC_DOT),   OSM(MOD_LSFT), CW_TOGG,
  KC_MEH, LT(2, KC_SPACE), LT(1, KC_TAB), KC_ENTER,                         TG(3), KC_BSPC, OSL(1), KC_HYPR
 ),

    // TODO:  hg combo : escape
    // TODO: jf combo: enter
    // TODO: dk combo: tab
  // TODO: base layer colemak
  // TODO: Mod Tap (@öäß, cedille, euro, etc.)
/*
   ┌───────────────────────────────────────────────────────────┐
   │ s y m b o l s                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    @    │    #    │    [    │    ]    │    |    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    &    │    _    │    ^    │    *    │    %    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    ▼    │    $    │    +    │    {    │    }    │    /    ├─╯                ╰─┤   left  │   down  │   up    │  right  │    :    │    "    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    =    │    <    │    >    │    (    │    )    │    \    ││   ▼    ││    ▼   ││    ~    │  Cmd/-  │ Opt/?   │    !    │  Ctrl/= │    ▼    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │         │    ▼    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

    // TODO: home row mod for layer symbols left
   [_SYMBOLS] = LAYOUT_polydactyl(
              KC_AT,    KC_HASH,  KC_LBRC,  KC_RBRC,  KC_PIPE,                        KC_AMPR,  KC_UNDS,  KC_CIRC,  KC_ASTR,  KC_PERCENT,
    _______,  KC_DLR,   KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_SLASH,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_COLON, KC_DQT,
    KC_EQUAL, KC_LT,    KC_GT,  MT(MOD_LALT, KC_LPRN), MT(MOD_LGUI, KC_RPRN),  KC_BSLS,   _______,   _______,  KC_TILD, MT(MOD_LGUI, KC_MINUS),MT(MOD_LALT, KC_QUES),KC_EXLM,MT(MOD_LCTL, KC_EQUAL),  _______,
                          _______, _______,  _______,   _______,   _______,  _______,   _______,  _______
  ),
/*
   ┌───────────────────────────────────────────────────────────┐
   │ n u m b e r s                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │  mute   │  play/p │ volume- │ volume+ │  next   │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    %    │   F9    │   F10   │   F11   │   F12   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    ▼    │    1    │    2    │    3    │    4    │    5    ├─╯                ╰─┤    6    │    7    │    8    │    9    │    0    │    ▼    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    ▼    │    ▼    │    ▼    │    <    │    >    │    =    ││ L click││ R click││    -    │   F1    │   F2    │   F3    │   F4    │    ▼    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    │     ▼   ││    ▼    │    ▼    │    ▼    │    ▼    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_NUMBERS] = LAYOUT_polydactyl(
              KC_AUDIO_MUTE,LALT(LCTL(LSFT(KC_P))),KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LALT(LCTL(LSFT(KC_G))),                        KC_PERCENT, KC_F9,    KC_F10,   KC_F11,   KC_F12,
    _______,  KC_1, KC_2, KC_3, KC_4, KC_5,                     KC_6, KC_7, KC_8, KC_9, KC_0,  _______,
    _______,  _______, _______, KC_LT, KC_GT, KC_EQUAL, KC_MS_BTN1,KC_MS_BTN2, KC_PMNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,  _______,
                             _______, _______, _______, _______,  _______,  _______,  _______,  _______
  )
};
// TODO: better use of home row right side of number layer
// maybe < > on left rigt h l?
//

#if defined(ENCODER_MAP_ENABLE)
// TODO: change 2 to NUM_DIRECTIONS if it is defined
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE_QWERTZ] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)  },
    // [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLD, KV_VOLU),           ENCODER_CCW_CW(KC_SCRL, KC_PAUSE)  }, // Volume and Brightness
    [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_BRIU, KC_BRID)  }, // Volume and Brightness
    // [_NUMBERS] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),           ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)  },
    [_NUMBERS] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN),           ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT)  },
    // [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
// TODO: mouse cursor speed -> constant speed http://qmk.local/features/mouse_keys
#endif

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0;

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return;
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return;
    }
#endif //DYNAMIC_MACRO_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE_QWERTZ:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

// KLOR OLED CODE  vvvv
// TODO: incrementally add and test klor oled code
//
// void render_os_lock_status(void) {
//     static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
//     static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
//     static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
//     static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
//     static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
//     static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
//     static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
//     static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
//     static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
//     static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
//     static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
//     static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
//     static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
//     #ifdef AUDIO_ENABLE
//       static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
//       static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
//     #endif
//     #ifdef HAPTIC_ENABLE
//       static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
//     #endif
//
// // os mode status ────────────────────────────────────────┐
//
//     oled_write_ln_P(sep_v, false);
//
//     if (keymap_config.swap_lctl_lgui) {
//         oled_write_P(os_m_1, false); // ──── MAC
//     } else {
//         oled_write_P(os_w_1, false); // ──── WIN
//     }
//
//     oled_write_P(sep_h1, false);
//     oled_write_P(face_1, false);
//
//     if (keymap_config.swap_lctl_lgui) {
//         oled_write_P(os_m_2, false); // ──── MAC
//     } else {
//         oled_write_P(os_w_2, false); // ──── WIN
//     }
//
//     oled_write_P(sep_h1, false);
//     oled_write_P(face_2, false);
//     oled_write_ln_P(sep_v, false);
//
//
// // lock key layer status ─────────────────────────────────┐
//
//     led_t led_usb_state = host_keyboard_led_state();
//
//     if (led_usb_state.num_lock) {
//         oled_write_P(n_lock, false); // ──── NUMLOCK
//     } else {
//         oled_write_P(b_lock, false);
//     }
//     if (led_usb_state.caps_lock) {
//         oled_write_P(c_lock, false); // ─── CAPSLOCK
//     } else {
//         oled_write_P(b_lock, false);
//     }
//     if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
//         oled_write_P(s_lock, false);
//     } else {
//         oled_write_P(b_lock, false);
//     }
//
// // hardware feature status ──────────────────────────────┐
//
//     oled_write_P(sep_h2, false);
//
//     #ifndef AUDIO_ENABLE
//         oled_write_P(b_lock, false);
//     #endif
//     #ifndef HAPTIC_ENABLE
//         oled_write_P(b_lock, false);
//     #endif
//
//     #ifdef AUDIO_ENABLE // ────────────────── AUDIO
//         if (is_audio_on()) {
//           oled_write_P(aud_en, false);
//         } else {
//           oled_write_P(aud_di, false);
//         }
//     #endif // AUDIO ENABLE
//
//      #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
//         oled_write_P(hap_en, false);
//      #endif // HAPTIC ENABLE
// }
//
//
// // layer status ──────────────────────────────────────────┐
//
// int layerstate = 0;
//
// layer_state_t layer_state_set_kb(layer_state_t state) {
//       switch (get_highest_layer(layer_state | default_layer_state)) {
//             case 0:
//                 strcpy ( layer_state_str, "BASE COLEMAK");
//                 break;
//             case 1:
//                 strcpy ( layer_state_str, "BASE QWERTY");
//                 break;
//             case 2:
//                 strcpy ( layer_state_str, "LOWER");
//                 break;
//             case 3:
//                 strcpy ( layer_state_str, "RAISE");
//                 break;
//             case 4:
//                 strcpy ( layer_state_str, "ADJUST");
//                 break;
//             default:
//                 strcpy ( layer_state_str, "XXXXXX");
//         }
//       if (dmacro_num < 1) {
//           strcpy ( o_text, layer_state_str );
//     }
//   //return state;
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
//
//
// // ┌───────────────────────────────────────────────────────────┐
// // │ w r i t e   t o   o l e d                                 │
// // └───────────────────────────────────────────────────────────┘
//
// bool oled_task_kb(void) {
//     if (!oled_task_user()) {
//         return false;
//     }
//     if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE
//
//         // layer status ──────────────────────────────────────────────────┐
//         #ifdef DYNAMIC_MACRO_ENABLE
//             if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
//             if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
//             if(dmacro_num == 3){ oled_write_P(play_ico, false); }
//         #endif //DYNAMIC_MACRO_ENABLE
//
//         oled_write_ln(o_text, false);
//         render_os_lock_status();
//
//     } else {  // ─────────────────────────────────────────── SECONDARY SIDE
//
//         // KLOR face ─────────────────────────────────────────────────────┐
//
//         static const char PROGMEM klor_face[] = {
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
//             0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0,
//             0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//         };
//         oled_write_raw_P(klor_face, sizeof(klor_face));
//     }
//     return false;
// }
#endif // OLED_ENABLE

