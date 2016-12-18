#include <Adafruit_NeoPixel.h>
#define PIN 5
#define LOWER_LENGTH 420
#define UPPER_LENGTH 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LOWER_LENGTH + UPPER_LENGTH, PIN, NEO_GRB + NEO_KHZ800);

int lowerLights[LOWER_LENGTH];
int upperLights[UPPER_LENGTH];

void setupLights() {
  strip.begin();
  strip.show();
  clearStrip();
  setUpper(strip.Color(250, 125, 25));
  writeLights();
}

int pos = 0;
int inc = 1;
int times = 0;
void loopLights() {
  incrementLower();
  if(times%2 == 0)lowerLights[0] = strip.Color(0, pos*2.5, 0);//should max at ~50
  if(times%2 == 1)lowerLights[0] = strip.Color(pos*2.5, 0, 0);
  pos+=inc;
  if(pos == 16) inc = -1;
  else if(pos == 0) {
    inc = 1;
    times++;
    int blank = random(50);
    for(int i = 0; i < blank; i++) {
      incrementLower();
      writeLights();
      delay(35);
    }
  }
  writeLights();
  delay(35);
}

void writeLights() {
  for(int i = 0; i < LOWER_LENGTH; i++) {
    strip.setPixelColor(i, lowerLights[i]);
    httpServer.handleClient();
  }

  for(int i = LOWER_LENGTH; i < LOWER_LENGTH+UPPER_LENGTH; i++) {
    strip.setPixelColor(i, upperLights[i-LOWER_LENGTH]);
    httpServer.handleClient();
  }
  
  strip.show();
}

void setUpper(uint32_t c) {
  for(int i = 0; i < UPPER_LENGTH; i++) {
    upperLights[i] = c;
    httpServer.handleClient();
  }
}

void incrementLower() {
  for(int i = LOWER_LENGTH-1; i > 0; i--) {
    lowerLights[i] = lowerLights[i-1];
    httpServer.handleClient();
  }
  lowerLights[0] = 0;
}

void clearStrip() {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
    httpServer.handleClient();
  }
  strip.show();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<LOWER_LENGTH; i++) {
      lowerLights[i] = (Wheel((i+j) & 255));
      httpServer.handleClient();
    }
    writeLights();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color((255 - WheelPos * 3)/5, 0, (WheelPos * 3)/5);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, (WheelPos * 3)/5, (255 - WheelPos * 3)/5);
  }
  WheelPos -= 170;
  return strip.Color((WheelPos * 3)/5, (255 - WheelPos * 3)/5, 0);
}
