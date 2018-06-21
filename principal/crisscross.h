#ifndef CRISS_CROSS
#define CRISS_CROSS

unsigned char x, y, z;
uint8_t v1=40, v2=40, v3=40;

void crisscross() {

  uint8_t color = 1;
  uint8_t bright = 48;

  fadeToBlackBy(leds, NUM_LEDS, bpm/10);


  EVERY_N_MILLIS(v1) {
    if (y < 19) {
      showLed(y , 1, color, bright);
      y++;
    }
    else {
      y = 0;
      v1 = random8(40, 200);
    }
  }


  EVERY_N_MILLIS(v2) {
    if (x < 19) {
      showLed(abs(19-x) , 0, color + 5, bright);
      x++;
    }
    else {
      x = 0;
      v2 = random8(10, 200);
    }
  }


  EVERY_N_MILLIS(v3) {
    if (z < 19) {
      showLed(z , 2, color + 10, bright);
      z++;
    }
    else {
      z = 0;
      v3 = random8(40, 200);
    }
  }
  //
  //    EVERY_N_MILLIS(60) {
  //    if (w < 3) {
  //      showLed(random8(19) , w, color, bright);
  //      w++;
  //    }
  //    else w = 0;
  //  }


  //
  //EVERY_N_MILLISECONDS( 30000 / vitesse ) {
  //      if (index < 3) {
  //        showLine(index, color*10, bright);
  //        index++;
  //      }
  //      else index = 0;
  //    }
  //
  FastLED.show();

}
#endif
