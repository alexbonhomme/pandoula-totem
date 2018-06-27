#ifndef ROND_H
#define ROND_H



uint8_t non = 0;
void rond() {
  timeval = 8;
  uint8_t bright = sampleavg + 20 ;
  uint8_t color1 = beatsin8(12, 64, 224);
  uint8_t color2 = beatsin8(12, 64, 224, 300);
  uint8_t color3 = beatsin8(12, 64, 224, 600);
  uint8_t vit = 100 ;  // beatsin8(5, 2, 70);  //vitesse de rotaion variable, pas au point...
  
//  Serial.print(color1);
//  Serial.print(" ");
//  Serial.print(color2);
//  Serial.print(" ");
//  Serial.print(color3);
//  Serial.print(" ");
//  Serial.println(vit);
  
  EVERY_N_MILLISECONDS(500 / vit) fadeToBlackBy(leds, NUM_LEDS, 20 );

  
  showLed(non * 18 / 255, 0, color1, bright);
  showLed(non * 18 / 255, 1, color2, bright);
  showLed(non * 18 / 255, 2, color3, bright);
  showLed((non+128) * 18 / 255, 0, color1+100, bright);
  showLed((non+128) * 18 / 255, 1, color2+100, bright);
  showLed((non+128) * 18 / 255, 2, color3+100, bright);
  non++;


  //      showColumn(oui + 9, color, bright);
  //      showColumn(abs(-oui), abs(100 - color), bright);
  //      Serial.println(oui);



}

#endif
