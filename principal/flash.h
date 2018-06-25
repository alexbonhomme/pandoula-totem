#ifndef FLASH_H
#define FLASH_H

void flash() {
  uint8_t beatA = beatsin8(17, 0, 255);
  //if (samplepeak == 1) {// dur à tester avec le micro qui déconne...
  EVERY_N_MILLIS (1000) {// du coup version alternative avec un bête timer
    fill_rainbow(leds + random8(0,NUM_LEDS/2), random8(0,NUM_LEDS/2), beatA, 8);  // Use FastLED's fill_rainbow routine.
//    fill_rainbow(leds[0], 10, beatA, 8);
//    fill_rainbow(leds[11], 26, beatA, 8);
//    fill_rainbow(leds[27], 45, beatA, 8);
  }

  EVERY_N_MILLIS (350) {  //Ok, c'est juste une idée mais je pense que ça peut rendre bien sur un truc un peu coloré de fondre au noir de façon saccadée..
    fadeToBlackBy(leds, NUM_LEDS, 100);
  }
}
#endif
