#ifndef SUPPORT_H
#define SUPPORT_H

// Supporting general function -------------------------------------------------------------------------------------------

void showfps() {                                                                // Show rames per seocond on the serial monitor.

  // Temporary local variable
  uint32_t currentMillis;

  // Persistent local variable
  static uint32_t lastMillis = 0;

  currentMillis = millis();
  loops++;                                                                      // Keep on incrementing this each time it's called until (currentMillis - lastMillis) > 1000

  if (currentMillis - lastMillis > 1000) {                                      // If 1 second has passed, then. .
    Serial.println(loops);                                                      // Print the value of loops (which is loops per second).
    lastMillis = currentMillis;                                                 // Reset everything and start counting all over again. By Andrew Tuline.
    loops = 0;
  }

} // showfps()



// Supporting visual functions ----------------------------------------------------------------------------------------------

void lineit() {                                                                 // Send the pixels one or the other direction down the line.

  if (thisdir == 0) {
    for (int i = NUM_LEDS - 1; i > 0 ; i-- ) leds[i] = leds[i - 1];
  } else {
    for (int i = 0; i < NUM_LEDS - 1 ; i++ ) leds[i] = leds[i + 1];
  }

} // waveit()



void waveit() {                                                                 // Shifting pixels from the center to the left and right. Bidouillé pour coller vu qu'on est pas en linéaire.

  for (int i = 10; i > 5; i--) {                           // Move to the right la première ligne.
    leds[i] = leds[i - 1];
  }
  for (int i = 26; i > 18; i--) {                           // Move to the right la deuxième.
    leds[i] = leds[i - 1];
  }
  for (int i = 45; i > 36; i--) {                          // Move to the right la troisième.
    leds[i] = leds[i - 1];
  }


  for (int i = 0; i < 5; i++) {                                      // Move to the left1.
    leds[i] = leds[i + 1];
  }
  for (int i = 11; i < 18; i++) {                                     // Move to the left2.
    leds[i] = leds[i + 1];
  }
  for (int i = 27; i < 36; i++) {                                      // Move to the left3.
    leds[i] = leds[i + 1];
  }

} // waveit()

void waveitligne() {
  for (int j = 0; j < 19; j++) {
    for (int i = 0; i <3; i++) {
      leds[matrice[i][j]] = leds[matrice[i + 1][j]];
    }
  }
}//waveitligne



void addGlitter( fract8 chanceOfGlitter) {                                      // Let's add some glitter, thanks to Mark

  if ( random8() < chanceOfGlitter) {
    leds[random16(NUM_LEDS)] += CRGB::White;
  }

} // addGlitter()

// rajouts Thomate
void showLeds(unsigned int coord, unsigned int bright) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, coord, bright);
  }
}

void showLed(int x, int y, unsigned int coord, unsigned int bright) {
  int pos = matrice[y][x];
  leds[pos] = ColorFromPalette(currentPalette, coord, bright);
}

void showColumn(int x, unsigned int coord, unsigned int bright) {
  showLed(x, 0, coord, bright);
  showLed(x, 1, coord, bright);
  showLed(x, 2, coord, bright);
}

//Test Thomas
void showLine(int y, unsigned int coord, unsigned int bright) {
  for (int j = 0; j < 19; j++) {
    showLed(j, y, coord, bright);
  }
}







#endif

