#ifndef MOTIF1_H
#define MOTIF1_H

byte i = 0;
void motif1() {
  uint8_t vit = 20 ;
  uint8_t posy = beatsin8(vit*3, 0, 2);


 // fadeToBlackBy(leds, NUM_LEDS, 3);
  //  showLine( posy, color, sampleavg);
  //  showColumn(posx, color, sampleavg);
  EVERY_N_MILLIS(3000/vit) {
    
  fadeToBlackBy(leds, NUM_LEDS,2);
    if (i<19){
      leds[matrice[posy][i]]+= CHSV( 10, 255, 55);
      leds[matrice[posy+1][i]]+= CHSV( 120, 255, 55);
      leds[matrice[posy-1][i]]+= CHSV( 120, 255, 55);
      leds[matrice[posy+2][i]]+= CHSV( 158, 255, 55);
      leds[matrice[posy-2][i]]+= CHSV( 158, 255, 55);
         //showLed(i, posy, color, 16);
         i++;
    }
    else i=0;
  }
}




#endif

