#ifndef LIGNE_H
#define LIGNE_H

uint8_t x1, y1, z1;

void ligne() {

  uint8_t r = random8(3);
  uint8_t color = 1;
  uint8_t bright = sampleavg+20;

  EVERY_N_MILLIS(50) fadeToBlackBy(leds, NUM_LEDS, 3);
  
  timeval = 1 ;
  if (r == 0)    x1 = x1 + 1;
  if (r == 1)    y1 = y1 + 1;
  if (r == 2)    x1 = x1 - 1;
  if (r == 3)    y1 = y1 - 1;
  showLed(y1 * 18 / 255 , x1 * 3 / 255, color, bright);
}
#endif
