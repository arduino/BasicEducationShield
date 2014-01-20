/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 10:
 *  - the points are being counted extra, fix it
 *  - you can achieve this in two different ways:
 *    + you can throw the apple again as soon as you detect collision, or
 *    + stop counting once there is a collision and until a new apple
 *      falls from the tree
 *  - you will need a 'boolean' variable to check whether to add points or
 *    not, you will have to reset it to 'true' each time a new apple 
 *    falls from the top of the tree
 *  - los puntos se estan contabilizando extra, corrigelo
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;      // X coordinate, Newton
int nY = 0;      // Y coordinate, Newton
float mY = 0;    // Y coordinate, apples
int mX = 15;     // X coordinate, apples
float mV = 0;    // Y speed, apples
float mA = 0.05; // Y acceleration, apples
int p = 0;       // Points
boolean pCount = true;  // Check whether to count points or not
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Apple's movement
  mV = mV + mA;  
  mY = mY + mV;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20)); 
    mV = 0;   
    // When throwing a new apple it will be possible 
    // to start counting points again
    pCount = true;  
  }
  
  // Collision detection
  if (mY + 10 > nY && mY - 10 < nY + 20) {  
    if (mX + 10 > nX && mX - 10 < nX + 20) { 
      fill(255, 0, 0);  
      // If collision increase the points
      if (pCount) p = p + 1;
      pCount = false;  // Whenever you make it at this point, do not 
                       // count any more points
    } 
  }

  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20); 

  // Show the points on the screen
  fill(0);  // Text color
  text("Hits: " + p, 3 * width / 4, 20); // Text alligned to the right
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
