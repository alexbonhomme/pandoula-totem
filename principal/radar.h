#ifndef RADAR_H
#define RADAR_H

void radar() {
  currentMillis = millis(); 
  uint8_t bright = 64;// map(sampleavg, 0, 20, 40, 128);
  fadeToBlackBy(leds, NUM_LEDS, 45);
  if (index < 19) {
    if (currentMillis-oldMillis>=1000) {
    oldMillis+=1000;
    index++;
    }
    
  } else {
    index = 0;
  }
  for (int j = 0; j < 5; j++) {
    int color = map (j, 0, 5, 1, 255);
    showColumn(index+j, 1, map(j, 0, 5, 128, 12));
   
  }


FastLED.show();
}

#endif
