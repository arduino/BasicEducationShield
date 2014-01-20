/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 4:
 *  - modify the program to make the apple fall
 *  - you will need a variable to store the Y coordinate for the apple
 *  - when the apple touches the ground, you will need to "hang it" from the tree again
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
int mY = 0;  // Apple's Y coordinate
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  
  mY = mY + 1;  // Increase apple's coordinate
  if (mY > height) {
    mY = 15;    // If the apple touches the ground, lift it again
  }
  ellipse(15, mY, 20, 20);   // Make the Y coordinate into a variable 
  rect(nX, height - 25, 20, 20);  
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
