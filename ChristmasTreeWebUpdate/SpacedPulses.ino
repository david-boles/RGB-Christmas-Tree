void setupSpacedPulses() {
  setUpper(strip.Color(250, 125, 25));
  writeLights();
}

int posSpacedPulses = 0;
int incSpacedPulses = 1;
int timesSpacedPulses = 0;
void loopSpacedPulses() {
  incrementLower();
  if(timesSpacedPulses%2 == 0)lowerLights[0] = strip.Color(0, posSpacedPulses*2.5, 0);//should max at ~50
  if(timesSpacedPulses%2 == 1)lowerLights[0] = strip.Color(posSpacedPulses*2.5, 0, 0);
  posSpacedPulses+=incSpacedPulses;
  if(posSpacedPulses == 16) incSpacedPulses = -1;
  else if(posSpacedPulses == 0) {
    incSpacedPulses = 1;
    timesSpacedPulses++;
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
