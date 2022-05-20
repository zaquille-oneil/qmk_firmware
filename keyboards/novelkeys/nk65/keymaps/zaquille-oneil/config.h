#undef RGB_BACKLIGHT_LAYER_1_INDICATOR
#undef RGB_BACKLIGHT_LAYER_2_INDICATOR
#undef RGB_BACKLIGHT_LAYER_3_INDICATOR

// ./keyboards/wilba_tech/wt_rgb_backlight.c:1661
#define RGB_BACKLIGHT_LAYER_1_INDICATOR { .color = { .h = 100, .s = 255 }, .index = 57-1 } //green
#define RGB_BACKLIGHT_LAYER_2_INDICATOR { .color = { .h = 150, .s = 255 }, .index = 57-1 } //blue
#define RGB_BACKLIGHT_LAYER_3_INDICATOR { .color = { .h = 0, .s = 0 }, .index = 57-1 }