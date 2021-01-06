int fireLen = 0;

#define RED_MAX 255
#define RED_MIN 210
#define RED_MAX_STEP 50
#define GREEN_BASE 50//50
#define GREEN_MAX 80
#define GREEN_STEP 20
#define SPURT_PROB_DENOMINATOR 40
#define ZONES 5
#define LEDs_PER_ROW 26


int fireRed = RED_MIN;
bool greenSpurt[ZONES];
int fireGreen[ZONES];

void setupFire() {
  clearStrip();

  fireRed = RED_MIN;
  for(int i = 0; i < ZONES; i++) {
    greenSpurt[i] = false;
    fireGreen[i] = GREEN_BASE;
  }
  
  //setUpper(strip.Color(0, 0, 255));
  //setLower(strip.Color(0, 0, 255));
//  for(int i = 0; i < LOWER_LENGTH; i+=3) {
//    lowerLights[i] = strip.Color(50, 50, 50);
//  }
  
  
  writeLights();
}

//bool isGreenMax = false;
void loopFire() {
  fireRed = myConstrain(fireRed + (random(RED_MAX_STEP * 2) - RED_MAX_STEP), RED_MIN, RED_MAX);
  for(int i = 0; i < ZONES; i++) {
    greenSpurt[i] = (fireGreen[i] == GREEN_MAX) ? false : greenSpurt[i];
    greenSpurt[i] = (random(SPURT_PROB_DENOMINATOR) == 0) ? true : greenSpurt[i];
    
    int greenStep = random(GREEN_STEP) * (greenSpurt[i] ? 1 : -1);
    fireGreen[i] = myConstrain(fireGreen[i] + greenStep, GREEN_BASE, GREEN_MAX);
  }
  
  for(int i = 0; i < LOWER_LENGTH; i++) {
    int zone = (i%LEDs_PER_ROW) / ZONES;
    if(((i/LEDs_PER_ROW)%2) == 1) { // Zones for odd rows are in reversed order
      zone = ZONES - 1 - zone;
    }
    
    lowerLights[i] = strip.Color(fireRed, fireGreen[zone], 0);
  }
  
  writeLights();
//  isGreenMax = (random(20) == 1) ? !isGreenMax : isGreenMax;
  delay(50);
}

int myConstrain(int val, int minVal, int maxVal) {
  if(val < minVal) {
    return minVal;
  }else if(val > maxVal) {
    return maxVal;
  }else {
    return val;
  }
}
