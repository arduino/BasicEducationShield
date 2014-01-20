/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 8:
 *  - mofify the apples' falling speed for them to follow the gravity
 *  - as you know, speed can be calculated from acceleration, and position
 *    from speed
 *  - introduce a variable representing acceleration, make it a 'float'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
int nY = 0; 
float mY = 0;  
int mX = 15;
float mV = 0;     // Apple's initial speed is zero
float mA = 0.05;  // Apple's intial accerlation (0.98 would be too much)
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Apple's movement
  mV = mV + mA;  // Estimate the speed according to the acceleration
  mY = mY + mV;  // Estimate the position according to the speed
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20)); 
    mV = 0;  // Apples start falling at zero speed 
  }
  
  fill(255);  
  
  // Collision detection
  if (mY + 10 > nY && mY - 10 < nY + 20) {  
    if (mX + 10 > nX && mX - 10 < nX + 20) { 
      fill(255, 0, 0);  
    } 
  }

  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20);    
}

void keyPressed() {
  // Increase the coordinates in 3 pixels
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Decrease the coordinates in 3 pixels
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
  // Limit the X coordinates
  if (nX < 0) {
    nX = 0;
  }
  if (nX > width - 20) {  
    nX = width - 20;
  }
}
