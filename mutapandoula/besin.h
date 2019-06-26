#ifndef BESIN_H
#define BESIN_H

void besin() {                                           // Add a Perlin noise soundbar. This looks really cool.
                                                         // Shows you don't need a crap ton of code for a cool effect.
// Local definitions

// Persistent local variables

// Temporary local variables
//for (int i=0; i<16; i++){
//    leds[matrice[0][i]] = ColorFromPalette(currentPalette, millis(), sampleavg, NOBLEND);
//                                                                     
//
//}
  leds[8] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);
  leds[7] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);
  leds[24] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);
  leds[23] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);
  leds[40] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);
  leds[39] = ColorFromPalette(currentPalette, millis(), sampleavg-20, NOBLEND);

  waveit();
//
//EVERY_N_MILLIS(100){
//  waveitligne();                                              // Move the pixels to the left/right, but not too fast.
//}
  fadeToBlackBy(leds, NUM_LEDS, 40);                      // Fade the center, while waveit moves everything out to the edges.      

} // besin()

#endif
