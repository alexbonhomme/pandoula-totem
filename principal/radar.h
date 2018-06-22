#ifndef RADAR_H
#define RADAR_H

byte bindex;
void radar() {
  uint8_t bright = sampleavg ;
  uint8_t color = 1;
  uint8_t shift = 10;
  uint8_t vit = 10;
  fadeToBlackBy(leds, NUM_LEDS, vit);

  EVERY_N_MILLISECONDS( 1000 / vit ) {

    if (bindex < 19) {
      showLed(bindex, 0, color, bright);
      showLed(bindex, 1, color + shift / 2, bright);
      showLed(bindex, 2, color + shift, bright);
      bindex++;
    }
    else bindex = 0;
  }
  addGlitter(sampleavg / 3);
  FastLED.show();

}
#endif
