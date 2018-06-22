#ifndef LIGNE_H
#define LIGNE_H

unsigned char x1, y1, z1;

void ligne() {

  uint8_t r = random8(3);
  uint8_t color = 1;
  uint8_t bright = 48;

  fadeToBlackBy(leds, NUM_LEDS, 10);
  EVERY_N_MILLIS (30) {
    if (x1 > 0, x1<2, y1>0, y1 < 18) {
      if (r == 0)    x1 = x1 + 1;
      if (r == 1)    y1 = y1 + 1;
      if (r == 2)    x1 = x1 - 1;
      if (r == 3) y1 = y1 - 1;
      showLed(y1 , x1, color, bright);
    }
    else x1 = 0, y1 = 0;
    }
}
#endif
