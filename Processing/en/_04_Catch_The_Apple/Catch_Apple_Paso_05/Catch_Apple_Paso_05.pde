/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 5:
 *  - the apple is always falling from the same place on the screen, change its X
 *    coordinate when created to show up at different places
 *  - the 'random()' function will create a random number, it returns a number
 *    between 0 and whatever number you pass to it as a parameter between the brackets
 *  - you will need a new variable to store the X position of the apple
 *  - the coordinate value has to be changed only when the apple touches the ground
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
int mY = 0;  
int mX = 15; // Apple's X coordinate
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  
  mY = mY + 1;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  // Initialize the X coordinate of the apple to a random number
  }
  ellipse(mX, mY, 20, 20);  // Include the changes to the X coordinate to the circle's movement 
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
