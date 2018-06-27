#ifndef FNOISELIGNE_H
#define FNOISELIGNE_H

void fnoiseligne(){
  // Local definitions
  #define xscale 160
  #define yscale 160

// Persistent local variables
  static int16_t xdist;                                                         // A random number for our noise generator.
  static int16_t ydist;


  timeval = 40;                                                                 // Our EVERY_N_MILLIS_I timer value.
  
   if (sampleavg > 19) sampleavg = 19;                               // Clip the sampleavg to maximize at 19.
    for (int i= (19-sampleavg/2)/2; i<(19+sampleavg/2)/2; i++) {      // The louder the sound, the wider the soundbar.
    uint8_t index = inoise8(i*sampleavg+xdist, ydist+i*sampleavg);              // Get a value from the noise function. I'm using both x and y axis.
    showLed(i, 2, index, sampleavg);                                             //version fausse 2D 
    //leds[i] = ColorFromPalette(currentPalette, index, sampleavg, LINEARBLEND);  // With that value, look up the 8 bit colour palette value and assign it to the current LED.
  }                                                                             // Effect is a NOISE bar the width of sampleavg. Very fun. By Andrew Tuline.

  xdist=xdist+beatsin8(5,0,3);                                                  // Moving forward in the NOISE field, but with a sine motion.
  ydist=ydist+beatsin8(4,0,3);                                                  // Moving sideways in the NOISE field, but with a sine motion.

addGlitter(sampleavg/2);     

  waveitligne();                                                                     // Move the pixels to the haut, but not too fast.

for (int i = 0 ; i < 19 ; i++){
  leds[matrice[2][i]].fadeToBlackBy(128);                                     // Fade the bas, while waveit moves everything out to the edge.
}
                                                                   
} // fillnoisecolonne()



#endif
