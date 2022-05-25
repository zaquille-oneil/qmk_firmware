#undef RGB_BACKLIGHT_LAYER_1_INDICATOR
#undef RGB_BACKLIGHT_LAYER_2_INDICATOR
#undef RGB_BACKLIGHT_LAYER_3_INDICATOR

// ./keyboards/wilba_tech/wt_rgb_backlight.c:1661
#define RGB_BACKLIGHT_LAYER_1_INDICATOR { .color = { .h = 168, .s = 255 }, .index = 1+64-1 } // 
#define RGB_BACKLIGHT_LAYER_2_INDICATOR { .color = { .h =  199, .s = 255 }, .index = 1+64-1 } // 
#define RGB_BACKLIGHT_LAYER_3_INDICATOR { .color = { .h =  96, .s = 207 }, .index = 1+64-1 } // 
// I've overridden the logic for LAYER_3 indicator to light up for layer 0 instead.

// pink: .h = 240, .s = 100
// peach: .h = 10, .s = 220
// light teal: .h = 80, .s = 220
// aqua = 100, 255
// orange = 35, 255
// red = 0, 255
// blue = 168, 255
// indigo = 176, 255
// playstation teal = 87, 255
// violet = 199
// modo light teal = 96, 207
// modo light pink = 0, 199