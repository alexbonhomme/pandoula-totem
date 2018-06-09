#ifndef MOTIF1_H
#define MOTIF1_H


// micro constants
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

unsigned int value;
int index = 0;

//fonctions


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

void showLeds(unsigned int coord, unsigned int bright) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, coord, bright);
  }
}

void showLed(int x, int y, unsigned int coord, unsigned int bright) {
  int pos = matrix[y][x];
  leds[pos] = ColorFromPalette(currentPalette, coord, bright);
}

void showColumn(int x, unsigned int coord, unsigned int bright) {
  showLed(x, 0, coord, bright);
  showLed(x, 1, coord, bright);
  showLed(x, 2, coord, bright);
}

//Test Thomas.Hmm, ça ne marche pas tip top.
void showLine(int y, unsigned int coord, unsigned int bright) {
  for (int j = 0; j < 19; j++) {
    showLed(j, y, coord, bright);
  }
}

void motif1(){

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



#endif

