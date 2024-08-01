#include <stdint.h>
#include QMK_KEYBOARD_H
#include "klorina.h"

// #define GRAVE_MODS                                                             \
//   (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI) | \
//    MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))

enum layer_names {
    _BASE_QWERTZ,
    _BASE_COLEMAK,
    _SYMBOLS,
    _NUMBERS,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    // LOWER,
    // RAISE,
    // ADJUST,
    OS_SWAP,
    // MAKE_H,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐
#define GUI_F MT(MOD_LGUI, KC_F)
#define GUI_RB MT(MOD_LGUI, KC_RBRC)
#define GUI_6 MT(MOD_LGUI, KC_LBRC)
#define ALT_D MT(MOD_LALT, KC_D)
#define ALT_LB MT(MOD_LALT, KC_LBRC)
#define ALT_5 MT(MOD_LALT, KC_RBRC)
// #define CTL_S MT(MOD_LCTL, KC_S)
// #define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

// #define SHT_N MT(MOD_RSFT, KC_N)
// #define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_K MT(MOD_LALT, KC_K)
#define ALT_UP MT(MOD_LALT, KC_UP)
#define ALT_F6 MT(MOD_LALT, KC_F6)
#define GUI_J MT(MOD_LGUI, KC_J)
#define GUI_DO MT(MOD_LGUI, KC_DOWN)
#define GUI_F5 MT(MOD_LGUI, KC_F5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
   ┌───────────────────────────────────────────────────────────┐
   │ b a s e QWERTZ                                                  │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Z    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   Tab   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │    :    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   Meh   │    Y    │    X    │    C    │    V    │    B    ││ PlayPau││ NextTra││    N    │    M    │    ,    │    .    │    _    │  Hyper  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   Esc   │  BackSp │  Space  │  Shift  ││  Cntrl  │  Enter  │L SYMBOLS│  Repeat │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_BASE_QWERTZ] = LAYOUT_polydactyl(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Z,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_TAB,   KC_A,     KC_S,     ALT_D,    GUI_F,    KC_G,                          KC_H,     GUI_J,    ALT_K,    KC_L,     KC_SEMICOLON,  KC_COLON,
OSM(MOD_MEH), KC_Y,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MPLY,   KC_MNXT,  KC_N,     KC_M,     KC_COMMA, KC_DOT,   KC_COMM,  OSM(MOD_HYPR),
                                  KC_ESC, KC_BSPC, KC_SPACE, OSM(MOD_LSFT),OSM(MOD_RCTL), KC_ENTER, TO(_SYMBOLS), QK_REP
 ),
  // TODO: base layer colemak
  // TODO: Mod Tap (@öäßc etc.)
  // TODO: all ???
/*
   ┌───────────────────────────────────────────────────────────┐
   │ s y m b o l s                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    "    │    #    │    [    │    ]    │    |    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    &    │    =    │    +    │    *    │    %    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   Tab   │    '    │    $    │    {    │    }    │    /    ├─╯                ╰─┤   left  │   down  │   up    │  right  │    ?    │    ▼    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   Meh   │    `    │    ^    │    (    │    )    │    \    ││   (    ││    )   ││    ~    │    -    │    <    │    >    │    !    │  Hyper  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │ L BASE  │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │L NUMBERS│    ▼    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_SYMBOLS] = LAYOUT_polydactyl(
              KC_DQT,   KC_HASH,  KC_LBRC,  KC_RBRC,  KC_PIPE,                        KC_AMPR,  KC_PEQL,  KC_PLUS,  KC_ASTR,  KC_PERCENT,
    _______,  KC_QUOTE, KC_DLR,   ALT_LB,   GUI_RB,   KC_KP_SLASH,                    KC_LEFT,  GUI_DO,   ALT_UP,   KC_RIGHT, KC_QUES,  _______,
    _______,  KC_GRAVE, KC_CIRC,  KC_LPRN,  KC_RPRN,  KC_BSLS,   _______,   _______,  KC_TILD,  KC_PMNS,  KC_LT,    KC_GT,    KC_EXLM,  _______,
                          TO(_BASE_QWERTZ), _______,  _______,   _______,   _______,  _______,  TG(_NUMBERS), _______
  )
/*
   ┌───────────────────────────────────────────────────────────┐
   │ n u m b e r s                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    .    │    7    │    8    │    9    │    *    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    %    │   F9    │   F10   │   F11   │   F12   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    ???  │    ,    │    4    │  ALT/5  │  GUI/6  │    /    ├─╯                ╰─┤    +    │   F5    │   F6    │   F7    │   F8    │   ???   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   Meh   │    0    │    1    │    2    │    3    │    =    ││ L click││ R click││    -    │   F1    │   F2    │   F3    │   F4    │  Hyper  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │ L BASE  │    ▼    │    ▼    │     ▼   ││    ▼    │    ▼    │L SYMBOLS│    ▼    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */
   [_NUMBERS] = LAYOUT_polydactyl(
              KC_DOT,   KC_7,     KC_8,     KC_9,     KC_AST,                        KC_PERCENT, KC_F9,    KC_F10,   KC_F11,   KC_F12,
    _______,  KC_COMMA, KC_4,     ALT_5,    GUI_6,    KC_KP_SLASH,                    KC_PLUS,  GUI_F5,    ALT_F6,   KC_F7,    KC_F8,    _______,
    _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_EQUAL, KC_MS_BTN1,KC_MS_BTN2, KC_PMNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
                                  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______
  )
};

// #if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE_QWERTZ] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)  },
    // [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLD, KV_VOLU),           ENCODER_CCW_CW(KC_SCRL, KC_PAUSE)  }, // Volume and Brightness
    [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLD, KV_VOLU),           ENCODER_CCW_CW(KC_BRIU, KC_BRID)  }, // Volume and Brightness
    // [_NUMBERS] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),           ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)  },
    [_NUMBERS] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN),           ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT)  },
    // [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
// TODO: mouse cursor speed -> constant speed http://qmk.local/features/mouse_keys
// #endif

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


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }


// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            #ifdef KEYBOARD_klor_kb2040
              SEND_STRING ("qmk compile -kb klor/2040 -km default");
            #else
              SEND_STRING ("qmk compile -kb klor -km default");
            #endif
            tap_code(KC_ENTER);
          }
          break;

// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

      case KC_MPLY:
        if (record->event.pressed) {
          #ifdef HAPTIC_ENABLE
                  DRV_pulse(sharp_click);
          #endif // HAPTIC_ENABL
        }
        break;
    }
    return true;
}

