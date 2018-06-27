#ifndef MOTIF1_H
#define MOTIF1_H
uint8_t bright1 = 0,
        bright2 = 0,
        bright3 = 0;

void motif1() {
  uint8_t vit = 60;

  bright1 = beatsin8(vit, 0, sampleavg+20, 0);
  bright2 = beatsin8(vit, 0, sampleavg+20, 2 * vit);
  bright3 = beatsin8(vit, 0, sampleavg+20, 4 * vit);

  if (bright1<10) bright1=0;
  if (bright1<10) bright1=0;
  if (bright1<10) bright1=0;

//  Serial.print(bright1);
//  Serial.print(" ");
//  Serial.print(bright2);
//  Serial.print(" ");
//  Serial.println(bright3);



  for (int i = 0; i < 19; i++) {
    showLed(i, 2, beatsin8(vit,0,255)+10*i, bright1);
    showLed(i, 1, beatsin8(vit,0,255,vit/2)+10*i, bright2);
    showLed(i, 0, beatsin8(vit,0,255,vit)+10*i, bright3);
    //    leds[matrice[2][i]] = CHSV( 3*i, 255, bright1);
    //    leds[matrice[1][i]] = CHSV( 3*i, 255, bright2);
    //    leds[matrice[0][i]] = CHSV( 3*i, 255, bright3);
  }


  fadeToBlackBy(leds, NUM_LEDS, 2000 / vit);


  //
  //#define VIT_MOTIF1 20
  //#define HISTO_SIZE 200
  //uint8_t histo[HISTO_SIZE];

  //void shiftValues() {
  //  for (int i = HISTO_SIZE - 1; i > 0; --i) {
  //    histo[i] = histo[i - 1];
  //  }
  //}
  //
  //void storeNewValue(uint8_t value) {
  //  shiftValues();
  //  histo[0] = value;
  //}
  //uint8_t posy = beatsin8(VIT_MOTIF1*3, 0, 2);
  //
  //  uint8_t value = beatsin8(VIT_MOTIF1, 0, 255);
  //  storeNewValue(value);
  ////
  //  bright3 = histo[HISTO_SIZE - 1];
  //  bright2 = histo[HISTO_SIZE / 2];
  //  bright1 = histo[0];

  //    if (msin < 85) {
  //     bright1 = map(msin, 0, 85, 0, 255);
  //    }
  //    else if (msin>=85, msin < 171) {
  //      bright2 = map(msin, 86, 170, 0, 255);
  //    }
  //    else {
  //      bright3 = map(msin, 171, 255, 0, 255);
  //    }

}

#endif

