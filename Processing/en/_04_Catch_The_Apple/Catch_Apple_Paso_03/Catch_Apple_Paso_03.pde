/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 3:
 *  - limit Newton's movement within the window
 *  - for this you will use the conditional functions 'if-else'
 *  - you will check that the coordinate nX is always within the
 *    program's window. This means it will have to be bigger than 0
 *    and smaller than the window's 'width'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  ellipse(15, 15, 20, 20);  
  rect(nX, height - 25, 20, 20);  
}

void keyPressed() {
  // Increment the coordinates in 3 
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Decrement the coordinates in 3 u
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
  // Limit the valu of the X coordinate
  if (nX < 0) {
    nX = 0;
  }
  if (nX > width - 20) {  // Check the size of the square on the right side
    nX = width - 20;
  }
}
