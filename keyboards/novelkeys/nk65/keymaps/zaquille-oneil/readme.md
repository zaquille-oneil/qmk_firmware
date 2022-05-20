zaquille-oneil's layout for NK65. VIA support disabled. Ignore picture
=========================================================

![Layout image](https://i.imgur.com/DL0CjJO.png)

remapped the LED's on the right side of the keyboard to be:
 - Layer 0: no lights
 - Layer 1: 1st blue light
 - Layer 2: 2nd purple light
 - Layer 3: 3rd red light

also added logic to light up the bottom left key RGB LED to a color depending on the layer:
 - Layer 0: none
 - Layer 1: { .color = { .h = 100, .s = 255 }, .index = 57-1 } // aqua
 - Layer 2: { .color = { .h = 150, .s = 255 }, .index = 57-1 } // blue
 - Layer 3: { .color = { .h = 0,   .s = 0   }, .index = 57-1 } // pink

Default layer is normal ANSI 65%
