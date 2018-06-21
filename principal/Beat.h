#ifndef BEAT_H
#define BEAT_H

void Beat() {
  unsigned long time = micros(); // Used to track rate
  float sampli, valui, envelope, beat, thresh;
  unsigned char i;
  bool boom = false;

  for (i = 0;; ++i) {
    // Read ADC and center so +-512
    sampli = (float)analogRead(0) - 503.f;

    // Filter only bass component
    valui = bassFilter(sampli);

    // Take signal amplitude and filter
    if (valui < 0)valui = -valui;
    envelope = envelopeFilter(valui);

    // Every 200 samplis (25hz) filter the envelope
    if (i == 200) {
      // Filter out repeating bass sounds 100 - 180bpm
      beat = beatFilter(envelope);

      // Threshold it based on potentiometer on AN4
      thresh = 0.02f * (float)analogRead(4);

      // If we are above threshold, light up LED
      if (beat > thresh) {
        boom = true;
        showLed(2, 2, 255, 64);
      }
      else {

        showLed(2, 2, 64, 16);
        boom = false;
      }


      //Reset sampli counter
      i = 0;
      FastLED.show();
    }

    // Consume excess clock cycles, to keep at 5000 hz
    for (unsigned long up = time + SAMPLEPERIODUS; time > 20 && time < up; time = micros());
  }
  
}
#endif
