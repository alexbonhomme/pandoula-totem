#ifndef LIGNE
#define LIGNE

unsigned char x, y, z;

void ligne() {


  uint8_t color = 1;
  uint8_t bright = 48;

  fadeToBlackBy(leds, NUM_LEDS, bpm / 10);
  EVERY_N_MILLIS (200) {
    if (random8(1) < 1) {
      x=x+1;
    }
    else {y=y+1;
      showLed(x , y, color, bright);
    }
  }

#endif
