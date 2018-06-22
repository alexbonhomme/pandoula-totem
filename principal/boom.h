#ifndef BEAT_H
#define BEAT_H
//===========================================================================

// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

// Our Global Sample Rate, 5000hz
#define SAMPLEPERIODUS 100

//===========================================================================



unsigned long time = micros(); // Used to track rate
float sampli, valui, envelope, beat, thresh;
unsigned int counter = 0;
bool boom = false;

bool detectBoom() {
  // sample counter
  counter++;
  
  // Read ADC and center so +-512
  sampli = (float)analogRead(0) - 503.f;

  // Filter only bass component
  valui = bassFilter(sampli);

  // Take signal amplitude and filter
  if (valui < 0) {
    valui = -valui;
  }
  
  envelope = envelopeFilter(valui);

  //Serial.println(counter);

  // Every 200 samplis (25hz) filter the envelope
  if (counter >= SAMPLEPERIODUS) {
    // Filter out repeating bass sounds 100 - 180bpm
    beat = beatFilter(envelope);

    // Threshold it based on potentiometer on AN4
    thresh = 0.02f * (float)analogRead(4);

    // If we are above threshold, light up LED
    boom = beat > thresh;

//    Serial.print(beat);
//    Serial.print(" ");
//    Serial.print(thresh);
//    Serial.print(" ");
//    Serial.println(boom);

    //Reset sampli counter
    counter = 0;
  }

  // Consume excess clock cycles, to keep at 5000 hz
  //for (unsigned long up = time + SAMPLEPERIODUS; time > 20 && time < up; time = micros());

  return boom;
}
#endif
