#define qsubd(x, b)  ((x>b)?b:0)                                                // Digital unsigned subtraction macro. if result <0, then => 0. Otherwise, take on fixed value.
#define qsuba(x, b)  ((x>b)?x-b:0)                                              // Analog Unsigned subtraction macro. if result <0, then => 0. By Andrew Tuline.

#include "FastLED.h"                                          // FastLED library. Please use the latest development version.


#define LED_DT 6                                             // Data pin to connect to the strip.
#define COLOR_ORDER RGB                                     // ??? It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE WS2811                                       // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 50                                         // Number of LED's.
#define MIC_PIN    0                                                            // Microphone
#define POT_PIN    4                                                            // Potentiometer


//Variables modifiables à la volée.
uint8_t max_bright = 128;                                      // Overall brightness definition. It can be changed on the fly.
struct CRGB leds[NUM_LEDS];                                   // Initialize our LED array.

CRGBPalette16 currentPalette(OceanColors_p);
CRGBPalette16 targetPalette(OceanColors_p);
TBlendType    currentBlending = LINEARBLEND;                                    // NOBLEND or LINEARBLEND 

//fin des def fastled
//matrice de leds
int matrice[3][19] = {
  {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
  {11, 11, 12, 13, 14, 15, 16, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 26, 26},
  {0,  0,  1,  1,  2,  3,  3,  4,  4,  5,  5,  6,  7,  7,  8,  8,   9,  9, 10}
};

// Global timer value
uint8_t timeval = 20;                                                           // Currently 'delay' value. No, I don't use delays, I use EVERY_N_MILLIS_I instead.
uint16_t loops = 0;                                                             // Our loops per second counter.

// Global sound variables used in other routines.
bool     samplepeak = 0;                                                        // This sample is well above the average, and is a 'peak'.
uint16_t sampleavg = 0;                                                         // Average of the last 64 samples.
uint16_t oldsample = 0;                                                         // Previous sample is used for peak detection and for 'on the fly' values.

// Global visual variables used in display and other routines.
bool thisdir = 0;                                                               // Used in a display routine as well as a support routine.

uint8_t bpm=120; // Il faudrait pouvoir le mesurer plutôt que de le fixer comme ça...

void setup() {
  Serial.begin(57600);                                        // Initialize serial port for debugging.
  delay(1000);                                                // Soft startup to ease the flow of electrons.

  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);  // Use this for WS2812

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, 100);               // FastLED Power management set at 5V, 100mA.
}//setup


// Include various routines. Makes for an easier to read main program.

#include "soundmems.h"                                                          // Sample the sounds and provide a current sample, average of last 64 samples and peak detector.

#include "support.h"                                                            // A few extra routines for good luck.

#include "fillnoise8.h"                                                         // Here's the various sound reactive displays.
#include "jugglep.h"
#include "matrix.h"
#include "pixel.h"
#include "onesine.h"
#include "plasma.h"
#include "ripple.h"
#include "noisefire.h"
#include "rainbowbit.h"
#include "rainbowg.h"
// #include "Beat.h" //pas encore prêt mais dans l'idée plus puissant que soundmems
#include "motif1.h"

typedef void (*SimplePatternList[])();                                          // List of patterns to cycle through.  Each is defined as a separate function below.

SimplePatternList gPatterns = {fillnoise8, jugglep, matrix, noisefire, onesine, pixel, plasma, rainbowbit, rainbowg, ripple/*motif1*/};                                         // HERE IS WHERE YOU ADD YOUR ROUTINE TO THE LIST!!!!
// fillnoise8, jugglep, matrix, noisefire, onesine, pixel, plasma, rainbowbit, rainbowg, ripple

uint8_t gCurrentPatternNumber = 0;                                              // Index number of which pattern is current.


void loop() {       
  
  soundmems();
  
//  showfps();                                                                  // Show the frames per second. It had better not dip too far.

  EVERY_N_MILLISECONDS(20) {
    uint8_t maxChanges = 24; 
    nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);      // Awesome palette blending capability.
  }

  EVERY_N_MILLIS_I(thisTimer,timeval) {
    thisTimer.setPeriod(timeval);                                               // We can change the timeval on the fly with this line, which is pretty sweet.
    gPatterns[gCurrentPatternNumber]();                                         // Call the current pattern function.
  }
  
  EVERY_N_SECONDS(5) {                                                          // Change the target palette to a related colours every 5 seconds.
    uint8_t baseclr = random8();                                                // This is the base colour. Other colours are within 16 hues of this. One color is 128 + baseclr.
    targetPalette = CRGBPalette16(CHSV(baseclr, 255, random8(128,255)), CHSV(baseclr+128, 255, random8(128,255)), CHSV(baseclr + random8(16), 192, random8(128,255)), CHSV(baseclr + random8(16), 255, random8(128,255)));
  }

  FastLED.show();                                                               // Send the 'leds' array out to the actual LED strip.

  EVERY_N_SECONDS(10) {                                                         // Change the current pattern function periodically.
    nextPattern();
  }
  
} // loop()



#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))                              // Kriegsman came up with this line. I knew what it did at one time. . Something, something make an array with enough room for the function names something. . 



void nextPattern() {                                                            // Add one to the current pattern number, and wrap around at the end.

  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);  // Another Kriegsman piece of magic.
  
} // nextPattern()


