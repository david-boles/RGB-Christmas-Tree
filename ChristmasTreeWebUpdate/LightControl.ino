#include <Adafruit_NeoPixel.h>
#define PIN 5
#define LOWER_LENGTH 150//450
#define UPPER_LENGTH 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LOWER_LENGTH + UPPER_LENGTH, PIN, NEO_GRB + NEO_KHZ800);

int animationMode = 4;

int lowerLights[LOWER_LENGTH];
int upperLights[UPPER_LENGTH];

void setupLights() {
  strip.begin();
  strip.show();
  //clearStrip();
  //setupRainbowFade();
  //loopRainbowFade();
  //setupSpacedPulses();
  setupAnimation();
}

void setupAnimation() {
  switch(animationMode) {
    case 0:
      setupRainbowFade();
      break;
    case 1:
      setupSpacedPulses();
      break;
    case 2:
      setupSolidWhite();
      break;
    case 3:
      setupTwinkle();
      break;
    case 4:
      setupFire();
      break;
    default:
      clearStrip();
      writeLights();
      break;
  }
}

bool enableLooping = true;
void loopLights() {
  //loopRainbowFade();
  //loopSpacedPulses();
  if(enableLooping)loopAnimation();
}

void loopAnimation() {
  switch(animationMode) {
    case 0:
      loopRainbowFade();
      break;
    case 1:
      loopSpacedPulses();
      break;
    case 3:
      loopTwinkle();
      break;
    case 4:
      loopFire();
      break;
    default:
      break;
  }
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

void setLower(uint32_t c) {
  for(int i = 0; i < LOWER_LENGTH; i++) {
    lowerLights[i] = c;
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
  setLower(0);
  setUpper(0);
  writeLights();
}
