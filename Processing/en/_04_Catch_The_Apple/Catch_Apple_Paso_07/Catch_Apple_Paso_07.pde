/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 7:
 *  - modify the way the apples fall to reach higher speeds
 *  - introduce a variable to store the speed
 *  - declare that variable as 'mV' as a floating point number
 *  - you can modify the speed by changing just this variable
 *  - to control the apple's movement on the Y axis, modify the type of
 *    the 'mY' variable to be a 'float'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
int nY = 0; 
float mY = 0;  // Make mY into a float
int mX = 15;
float mV = 3;  // Apple's falling speed
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Apple's movement
  mY = mY + mV;  // Introduce the speed as an increment
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  
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
