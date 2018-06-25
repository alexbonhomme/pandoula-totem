#ifndef VAGUE_H
#define VAGUE_H

void vague() {
uint8_t bright1, bright2, bright3;

  bright1 = map (sampleavg,   0,  59, 0, 255);
  bright2 = map (sampleavg,  60, 119, 0, 255);         //ça déconne, mais je comprends pas pourquoi. normalement bright 2 reste à 0 tant que sampleavg ne dépasse pas 60 non ?
  bright3 = map (sampleavg, 120, 169, 0, 255);
//  bright4 = map (sampleavg, 170, 240, 0, 255);

  Serial.print(bright1);
  Serial.print(" ");
  Serial.print(bright2);         //on voit que ça oscille à haute fréquence entre 0 et 255
  Serial.print(",");
  Serial.println(bright3);

  for (byte i = 0; i < 19; i++) {
  leds[matrice[2][i]] = CHSV(96, 255, bright1);
    leds[matrice[1][i]] = CHSV(96, 255, bright2);
    leds[matrice[0][i]] = CHSV(0, 255, bright3);

  }
}
#endif
