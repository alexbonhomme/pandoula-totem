#ifndef ROND_H
#define ROND_H


int oui = 0;
int non = 0;
void rond() {

  uint8_t bright = sampleavg + 20 ;
  uint8_t color = 1;
  uint8_t vit = 10;
  fadeToBlackBy(leds, NUM_LEDS, vit / 20);

  EVERY_N_MILLISECONDS( 1000 / vit ) {

    if (oui < 10) {
      showColumn(oui + 9, color, bright);
      showColumn(abs(-oui), abs(100 - color), bright);
      Serial.println(oui);

      oui++;
    }
    else oui = 0;
  }

}

#endif
