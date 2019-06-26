#ifndef SUPPORT_H
#define SUPPORT_H

// Supporting general function -------------------------------------------------------------------------------------------
/*
void showfps() {                                                                // Show frames per seocond on the serial monitor.

// Local definitions

// Persistent local variables
  static uint32_t lastMillis = 0;
  
// Temporary local variables
  uint32_t currentMillis;


  currentMillis=millis();
  loops++;                                                                      // Keep on incrementing this each time it's called until (currentMillis - lastMillis) > 1000
  
  if(currentMillis - lastMillis >1000) {                                        // If 1 second has passed, then. . 
    Serial.println(loops);                                                      // Print the value of loops (which is loops per second).
    lastMillis = currentMillis;                                                 // Reset everything and start counting all over again. By Andrew Tuline.
    loops = 0;
  }
  
} // showfps()
*/


// Supporting visual functions ----------------------------------------------------------------------------------------------



void addGlitter(fract8 chanceOfGlitter) {                                      // Let's add some glitter
  
  if( random8() < chanceOfGlitter) {
    leds[random16(NUM_LEDS)] += CRGB::White;
  }

} // addGlitter()



void lineit() {                                                                 // Send the pixels one or the other direction down the line.
  
  if (thisdir == 0) {
    for (int i = NUM_LEDS-1; i >0 ; i-- ) leds[i] = leds[i-1];
  } else {
    for (int i = 0; i < NUM_LEDS-1 ; i++ ) leds[i] = leds[i+1];
  }
  
} // lineit()


void waveit() {                                                                 // Shifting pixels from the center to the left and right. Bidouillé pour coller vu qu'on est pas en linéaire.

  for (int i = 15; i > 8; i--) {                           // Move to the right la première ligne.
    leds[i] = leds[i - 1];
  }
  for (int i = 31; i > 24; i--) {                           // Move to the right la deuxième.
    leds[i] = leds[i - 1];
  }
  for (int i = 47; i > 40; i--) {                          // Move to the right la troisième.
    leds[i] = leds[i - 1];
  }


  for (int i = 0; i < 8; i++) {                                      // Move to the left1.
    leds[i] = leds[i + 1];
  }
  for (int i = 16; i < 24; i++) {                                     // Move to the left2.
    leds[i] = leds[i + 1];
  }
  for (int i = 32; i < 40; i++) {                                      // Move to the left3.
    leds[i] = leds[i + 1];
  }

} // waveit()

//rajouts


void showLed(int x, int y, unsigned int coord, unsigned int bright) {
  int pos = matrice[y][x];
  leds[pos] = ColorFromPalette(currentPalette, coord, bright);
}

void showColumn(int x, unsigned int coord, unsigned int bright) {
  showLed(x, 0, coord, bright);
  showLed(x, 1, coord, bright);
  showLed(x, 2, coord, bright);
}


void waveitligne() {
  
for (int j = 0; j < 16; j++) {
//  leds[matrice[1][j]]=leds[matrice[0][j]];
//  leds[matrice[2][j]]=leds[matrice[1][j]];
// }
for (int i = 1; i<3; i++){
  leds[matrice[i][j]]=leds[matrice[i-1][j]];
}}
  }
//waveitligne

#endif
