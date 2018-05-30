#include "FastLED.h"                                          // FastLED library. Please use the latest development version.

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif
 
// Fixed definitions cannot change on the fly.
#define LED_DT 6                                             // Data pin to connect to the strip.
#define COLOR_ORDER GRB                                     // It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE WS2811                                       // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 50                                         // Number of LED's.

int matrix[3][19] = {
  {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
  {11, 11, 12, 13, 14, 15, 16, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 26, 26},
  {0,  0,  1,  1,  2,  3,  3,  4,  4,  5,  5,  6,  7,  7,  8,  8,   9,  9, 10} 
};

// Global variables can be changed on the fly.
uint8_t max_bright = 128;                                      // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                   // Initialize our LED array.

DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
0,     0,  0,    225,   // blue
128,   255, 255,  0,   // yellow
255,   0, 255,    0 }; // red

CRGBPalette16 currentPalette(heatmap_gp);
CRGBPalette16 targetPalette(heatmap_gp);

// micro constants
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

unsigned int value;
int index = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);                                        // Initialize serial port for debugging.
  delay(1000);                                                // Soft startup to ease the flow of electrons.
  
//  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2801 or APA102
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2812
  
  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, 500);               // FastLED Power management set at 5V, 500mA.
}

void loop() {
  value = collectValue();
  
  //Serial.println(value);
  
  showLeds(value, 16);

  if (index < 19) {
    index++;
  } else {
    index = 0;
  }
  
  showColumn(index, value, 128);
  
  FastLED.show();
}


void showLeds(unsigned int value, unsigned int bright) {
  for (int i=0; i<NUM_LEDS; i++) { 
    leds[i] = ColorFromPalette(currentPalette, value, bright);
  }
}

void showLed(int x, int y, unsigned int value, unsigned int bright) {
  int pos = matrix[y][x];
  leds[pos] = ColorFromPalette(currentPalette, value, bright);
}

void showColumn(int x, unsigned int value, unsigned int bright) {
  showLed(x, 0, value, bright);
  showLed(x, 1, value, bright);
  showLed(x, 2, value, bright);
}

unsigned int collectValue() {
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
  
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
  
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude

   return min((peakToPeak / 513.0) * 255.0, 255.0);
}

