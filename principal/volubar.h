#ifndef VOLUBAR_H
#define VOLUBAR_H

uint8_t vol = 0;

void volubar() {

  timeval = 1;
  //uint8_t coord = 1;
  uint8_t bright = 64;
  uint8_t ubar = 18 * vol / 255;

  if (sampleavg > 20) leds[matrice[2][0]] = CHSV( 96, 255, map (sampleavg, 20, 39, 0, 255));
  if (sampleavg > 40)leds[matrice[1][0]] = CHSV( 96, 255, map (sampleavg, 40, 59, 0, 255));
  if (sampleavg > 60)leds[matrice[0][0]] = CHSV( 96, 255, map (sampleavg, 60, 100, 0, 255));
  //if (sampleavg > 80)leds[matrice[0][0]] = CHSV( 0, 255, bright);

  
//    for (uint8_t j = 18; j >= 0 ; j--)  {
//      leds[matrice[2][j]] = leds[matrice[2][j - 1]];
//        }
//  for (uint8_t ubar = 19; ubar > 0; ubar--) {
    leds[matrice[2][ubar]] = leds[matrice[2][ubar - 1]];
    leds[matrice[1][ubar]] = leds[matrice[1][ubar - 1]];
    leds[matrice[0][ubar]] = leds[matrice[0][ubar - 1]];
//  }
  vol--;
  Serial.print(sampleavg);
  Serial.print(" ");


}
#endif
