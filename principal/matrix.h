#ifndef MATRIX_H
#define MATRIX_H

void matrix() {                                                                 // A 'Matrix' like display using sampleavg for brightness. Also add glitter based on peaks (and not sampleavg).

  // Persistent local variables
  static uint8_t thishue = 0;

  timeval = 40;                                                                 // Our EVERY_N_MILLIS_I timer value.

//  leds[matrice[0][0]] = ColorFromPalette(currentPalette, thishue++, sampleavg, LINEARBLEND);
//  leds[matrice[1][0]] = ColorFromPalette(currentPalette, thishue++, sampleavg, LINEARBLEND);
//  leds[matrice[2][0]] = ColorFromPalette(currentPalette, thishue++, sampleavg, LINEARBLEND);
  
  showColumn(1, thishue++, sampleavg);

  //for (int i = NUM_LEDS-1; i >0 ; i-- ) leds[i] = leds[i-1];
  
  for (int i = 18; i > 0; i--) {
    leds[matrice[0][i]] = leds[matrice[0][i-1]];
    leds[matrice[1][i]] = leds[matrice[1][i-1]];
    leds[matrice[2][i]] = leds[matrice[2][i-1]];
  }
  
 // addGlitter(sampleavg/2);                                                    // Add glitter based on sampleavg. By Andrew Tuline.

} // matrix()

#endif
