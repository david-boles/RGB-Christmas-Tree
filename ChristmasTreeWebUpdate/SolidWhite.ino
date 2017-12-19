void setupSolidWhite() {
  clearStrip();
  setUpper(strip.Color(250, 125, 25));
  
  //setUpper(strip.Color(0, 0, 255));
  //setLower(strip.Color(0, 0, 255));
  for(int i = 0; i < LOWER_LENGTH; i+=3) {
    lowerLights[i] = strip.Color(50, 50, 50);
  }
  
  writeLights();
}
