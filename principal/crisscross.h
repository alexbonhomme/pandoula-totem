#ifndef CRISS_CROSS_H
#define CRISS_CROSS_H

unsigned char x, y, z;
uint8_t v2, v3, v4 ;

void crisscross() {
  timeval = 12;   //accélère un peu la rotation...
  uint8_t bright = 64;//sampleavg + 20 ;
  v3 = v2 * 18 / 255;
  v4 = (v2+128) * 18 / 255;
  EVERY_N_MILLIS(5){
    fadeToBlackBy(leds, NUM_LEDS, 1);
  }
  showColumn(v3, 1, bright);
  showColumn(v4, 128, bright);
  v2++;



  addGlitter(sampleavg/30);   

}
#endif
