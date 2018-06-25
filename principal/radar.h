#ifndef RADAR_H
#define RADAR_H

uint8_t in = 0;

void radar() {
  timeval = 12;   //accélère un peu la rotation...
  uint8_t bright = sampleavg + 20 ;
  uint8_t color = 1;
  uint8_t dex = in * 18 / 255;
  EVERY_N_MILLIS(50){
    fadeToBlackBy(leds, NUM_LEDS, 3);
  }
  showColumn(dex, color, bright);
  in++;

  addGlitter(sampleavg / 3);

}
#endif
