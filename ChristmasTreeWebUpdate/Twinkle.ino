int twinkles[LOWER_LENGTH];
#define TWINKLE_STEPS 64

void setupTwinkle() {
  clearStrip();
  setUpper(strip.Color(0, 0, 0));
  writeLights();
}

void loopTwinkle() {
//  for(int i = 0; i < LOWER_LENGTH; i+=4) {
//    lowerLights[i] = strip.Color(250, 125, 25);
//  }

  twinkles[random(0, LOWER_LENGTH)] = TWINKLE_STEPS;//One higher than it should be, gets subtracted.

  for(int i = 0; i < LOWER_LENGTH; i++) {
    if(twinkles[i] != 0){twinkles[i]--;}
    lowerLights[i] = strip.Color((250*twinkles[i])/TWINKLE_STEPS, (125*twinkles[i])/TWINKLE_STEPS, (25*twinkles[i])/TWINKLE_STEPS);
  }
  
  writeLights();
  delay(35);
}

//Cool:
//int twinkles[LOWER_LENGTH];
//#define TWINKLE_STEPS 24
//
//void setupTwinkle() {
//  clearStrip();
//  setUpper(strip.Color(0, 0, 0));
//  writeLights();
//}
//
//void loopTwinkle() {
////  for(int i = 0; i < LOWER_LENGTH; i+=4) {
////    lowerLights[i] = strip.Color(250, 125, 25);
////  }
//  twinkles[random(0, LOWER_LENGTH)] = TWINKLE_STEPS;//One higher than it should be, gets subtracted.
//
//  for(int i = 0; i < LOWER_LENGTH; i+=4) {
//    twinkles[i]--;
//    lowerLights[i] = strip.Color((250*twinkles[i])/TWINKLE_STEPS, (125*twinkles[i])/TWINKLE_STEPS, (25*twinkles[i])/TWINKLE_STEPS);
//  }
//  
//  writeLights();
//  delay(35);
//}

