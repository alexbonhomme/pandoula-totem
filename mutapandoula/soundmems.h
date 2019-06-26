#ifndef SOUNDMEMS_H
#define SOUNDMEMS_H

void soundmems() {                                                              // version de triche pour marcher sans micro
  
// Persistent local variables
  
  static long peaktime;                                                         // Time of last peak, so that they're not too close together.
  int8_t bpm = 10*maxvol;

// Temporary local variables
  int16_t    micIn = 0;                                                         // Current sample starts with negative values and large values, which is why it's 16 bit signed.


                                                                             //Version de secours si micro HS...
  uint8_t sampx = beatsin8(bpm,0,200);
  //uint8_t sampy = beatsin8(bpm,0,200);
  sample = inoise8 (sampx)-110;
  sampleavg = beatsin8 (bpm, 10, 120);
  
  
    
  EVERY_N_MILLIS(20000/bpm){
    samplepeak = 1 ; peaktime=millis();
    return samplepeak;
  }


//  Serial.print(sample);                                                           // Our oscilloscope.
//  Serial.print(" ");
//  Serial.print(sampleavg);
//  Serial.print(" ");
//  Serial.print(bpm);
//  Serial.print(" ");
//  Serial.print(samplepeak*150);
//  Serial.print(" ");
//  Serial.println(" ");
 
//  Serial.print(0);
//  Serial.print(" ");
//  Serial.print(255);
//  Serial.println(" ");


} // soundmems()

#endif
