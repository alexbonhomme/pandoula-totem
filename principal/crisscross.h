#ifndef CRISS_CROSS_H
#define CRISS_CROSS_H

unsigned char x, y, z;
uint8_t v2, v3;

void crisscross() {

  uint8_t color = 1;
  uint8_t bright = 48;

  fadeToBlackBy(leds, NUM_LEDS, bpm/10);

if (peak=true) {
  y=abs8(18-y);
  x=abs8(
}

  EVERY_N_MILLIS(50) {
    if (y < 19) {
      showLed(y , 1, color, bright);
      y++;
    }
    else {
      y = 0;
         }
  }


  EVERY_N_MILLIS(60) {
    if (x < 19) {
      showLed(abs8(19-x) , 0, color + 5, bright);
      x++;
    }
    else {
      x = 0;
      v2 = random8(10, 200);
    }
  }


  EVERY_N_MILLIS(70) {
    if (z < 19) {
      showLed(z , 2, color + 10, bright);
      z++;
    }
    else {
      z = 0;
      v3 = random8(40, 200);
    }
  }
  addGlitter(sampleavg/30);   

}
#endif
