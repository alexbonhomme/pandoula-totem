#ifndef FIREWIDE_H
#define FIREWIDE_H

  uint8_t bright1 = 0,
        bright2 = 0,
        bright3 = 0;

void firewide() {         

  uint8_t vit = 600/thisdelay;

  bright1 = beatsin8(vit, 0, sampleavg, 0);
  bright2 = beatsin8(vit, 0, sampleavg, 2 * vit);
  bright3 = beatsin8(vit, 0, sampleavg, 4 * vit);

  if (bright1<10) bright1=0;
  if (bright1<10) bright1=0;
  if (bright1<10) bright1=0;

//  Serial.print(bright1);
//  Serial.print(" ");
//  Serial.print(bright2);
//  Serial.print(" ");
//  Serial.println(bright3);



  for (int i = 0; i < 16; i++) {
    showLed(i, 2, beatsin8(vit,0,255)+10*i, bright1);
    showLed(i, 1, beatsin8(vit,0,255,vit/2)+10*i, bright2);
    showLed(i, 0, beatsin8(vit,0,255,vit)+10*i, bright3);
    //    leds[matrice[2][i]] = CHSV( 3*i, 255, bright1);
    //    leds[matrice[1][i]] = CHSV( 3*i, 255, bright2);
    //    leds[matrice[0][i]] = CHSV( 3*i, 255, bright3);
  }


  fadeToBlackBy(leds, NUM_LEDS, 2000 / vit);


} // firewide()

#endif
