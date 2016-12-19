void setupRainbowFade() {
  setUpper(strip.Color(250, 125, 25));
  writeLights();
}

void loopRainbowFade() {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<LOWER_LENGTH; i++) {
      lowerLights[i] = (Wheel((i+j) & 255));
      httpServer.handleClient();
    }
    writeLights();
    delay(20);
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
