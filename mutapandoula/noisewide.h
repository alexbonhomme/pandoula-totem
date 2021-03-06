#ifndef NOISEWIDE_H
#define NOISEWIDE_H

void noisewide() {

// Local definitions
  #define GRAVITY 5

// Persistent local variables
  static uint8_t topLED;
  static int gravityCounter = 0;

// Temporary local variables
//  uint8_t tempsamp = constrain(sampleavg/4,0,NUM_LEDS/2-1);                       // Keep the sample from overflowing.
  uint8_t tempsamp = constrain(sampleavg/12,0,8);                       // Keep the sample from overflowing.

  fadeToBlackBy(leds, NUM_LEDS, 160);
    
  for (int i=0; i<tempsamp; i++) {
    uint8_t index = inoise8(i*sampleavg+millis(), 5000+i*sampleavg); 

    leds[matrice[0][8-i]] = ColorFromPalette(currentPalette, index, sampleavg, currentBlending);       //on réessaie
    leds[matrice[0][8+i]] = ColorFromPalette(currentPalette, index, sampleavg, currentBlending);
    leds[matrice[1][8-i]] = ColorFromPalette(currentPalette, index, sampleavg-10, currentBlending);
    leds[matrice[1][8+i]] = ColorFromPalette(currentPalette, index, sampleavg-10, currentBlending);
    leds[matrice[2][8-i]] = ColorFromPalette(currentPalette, index, sampleavg-15, currentBlending);
    leds[matrice[2][8+i]] = ColorFromPalette(currentPalette, index, sampleavg-15, currentBlending);


    leds[NUM_LEDS/2-i] = ColorFromPalette(currentPalette, index, sampleavg, currentBlending);
    leds[NUM_LEDS/2+i] = ColorFromPalette(currentPalette, index, sampleavg, currentBlending);
  }

  if (tempsamp >= topLED)
    topLED = tempsamp;
  else if (gravityCounter % GRAVITY == 0)
    topLED--;

  if (topLED > 0) {
      leds[matrice[1][8-topLED]] = ColorFromPalette(currentPalette, millis(), 255, LINEARBLEND);                       // LED falls when the volume goes down.
      leds[matrice[1][8+topLED]] = ColorFromPalette(currentPalette, millis(), 255, LINEARBLEND); // LED falls when the volume goes down.

      //leds[topLED+NUM_LEDS/2] = ColorFromPalette(currentPalette, millis(), 255, LINEARBLEND); // LED falls when the volume goes down.

  }
  
  gravityCounter = (gravityCounter + 1) % GRAVITY;
    
} // noisewide()

#endif
