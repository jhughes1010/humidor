void ledCycle(void) {
  static uint8_t hue = 0;
  //hue = random(256);
  Serial.println(hue);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    //delay(DELAY);
  }
  delay(250);
  //hue++;
  for (int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    //delay(DELAY);
  }
  delay(250);
  //hue++;
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(TAIL);
    if (i % 2 == 0) {
      leds[i] = CRGB::Aqua;
    }
  }
}