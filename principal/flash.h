#ifndef FLASH_H
#define FLASH_H

void flash() {

  uint8_t beatA = beatsin8(17, 0, 255);
  if (samplepeak == 1) {// pas si génial la détection de peak mais ça rend correct quad même...
    //EVERY_N_MILLIS (1000) {// du coup version alternative avec un bête timer
    uint8_t ecart = map (sampleavg, 0, 50, 0, NUM_LEDS/2);   //plus c'est fort, plus l'arc en ciel est large
      fill_rainbow(leds + ecart, ecart, beatA, 8); // Use FastLED's fill_rainbow routine.
    //    fill_rainbow(leds[0], 10, beatA, 8);
    //    fill_rainbow(leds[11], 26, beatA, 8);
    //    fill_rainbow(leds[27], 45, beatA, 8);
  }

  EVERY_N_MILLIS (10) {  //Ok, c'est juste une idée mais je pense que ça peut rendre bien sur un truc un peu coloré de fondre au noir de façon saccadée..
    fadeToBlackBy(leds, NUM_LEDS, 10);
  }
}
#endif
