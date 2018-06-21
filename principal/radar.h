#ifndef RADAR_H
#define RADAR_H

void radar() {

  uint8_t bright = 48;
  uint8_t color = 1;
  char index=0;
  fadeToBlackBy(leds, NUM_LEDS, bpm / 15);

  EVERY_N_MILLISECONDS( 10000 / bpm ) {
    if (index < 19) {
      showColumn(index, color, bright);
      index++;
    }
    else index = 0;
  }

  FastLED.show();

}
#endif
