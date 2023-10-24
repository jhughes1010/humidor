//RelHum controller code for humidor
//James Hughes 10-5-2023



#include <FastLED.h>
#include <Wire.h>

#define INTAKE 3
#define EXHAUST 5

#define NUM_LEDS 60
#define DATA_PIN 2

#define DELAY 50
#define TAIL 250

CRGB leds[NUM_LEDS];

void setup() {
  // LEDs
  Serial.begin(115200);
  Serial.println("resetting");
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(32);
  // limit my draw to 1A at 5v of power draw
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  //set up fans
  pinMode(INTAKE, OUTPUT);
  pinMode(EXHAUST, OUTPUT);
  setFan(INTAKE, 100);
  setFan(EXHAUST, 100);


  Wire.begin();
  delay(5000);
}

void loop() {
  static long time = 0;
  time = millis();
  //check humidity
  //fan control update
  setFan(INTAKE, 50);
  setFan(EXHAUST, 50);
  //LED management/update
  ledCycle();
}
