#ifndef MOTIF1_H
#define MOTIF1_H

#define VIT_MOTIF1 20
#define HISTO_SIZE 200

uint8_t bright1 = 0, 
        bright2 = 0, 
        bright3 = 0;
uint8_t histo[HISTO_SIZE];

void shiftValues() {
  for (int i = HISTO_SIZE - 1; i > 0; --i) {
    histo[i] = histo[i - 1];
  }
}

void storeNewValue(uint8_t value) {
  shiftValues();
  histo[0] = value;
}

void motif1() {
  //uint8_t posy = beatsin8(VIT_MOTIF1*3, 0, 2);

  uint8_t value = beatsin8(VIT_MOTIF1, 0, 255);
  storeNewValue(value);
  
  bright3 = histo[HISTO_SIZE - 1];
  bright2 = histo[HISTO_SIZE / 2];
  bright1 = histo[0];
  
  Serial.print(bright1);
  Serial.print(" ");
  Serial.print(bright2);
  Serial.print(" ");
  Serial.println(bright3);

  
//    if (msin < 85) {
//     bright1 = map(msin, 0, 85, 0, 255);
//    }
//    else if (msin>=85, msin < 171) {
//      bright2 = map(msin, 86, 170, 0, 255);
//    }
//    else {
//      bright3 = map(msin, 171, 255, 0, 255);
//    }

  for (int i = 0; i < 19; i++) {
    leds[matrice[2][i]] = CHSV( 10, 255, bright1);
    leds[matrice[1][i]] = CHSV( 10, 255, bright2);
    leds[matrice[0][i]] = CHSV( 10, 255, bright3);
  }


  fadeToBlackBy(leds, NUM_LEDS, 100);

}

#endif

