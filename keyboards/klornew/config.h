#pragma once


// ┌─────────────────────────────────────────────────┐
// │ k e y   m a t r i x                             │
// └─────────────────────────────────────────────────┘

#define MATRIX_ROW_PINS { C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define DEBOUNCE 5


// ┌─────────────────────────────────────────────────┐
// │ s p l i t   c o m m u n i c a t i o n           │
// └─────────────────────────────────────────────────┘

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_USB_DETECT


// ┌─────────────────────────────────────────────────┐
// │ e n c o d e r s                                 │
// └─────────────────────────────────────────────────┘

#define ENCODERS_PAD_A       { F5 }
#define ENCODERS_PAD_B       { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2


// ┌─────────────────────────────────────────────────┐
// │ o l e d s                                       │
// └─────────────────────────────────────────────────┘

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#define SPLIT_OLED_ENABLE
//#define OLED_FONT_H  "./lib/glcdfont.c"
#endif

