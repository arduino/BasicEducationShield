/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 2:
 *  - make Newton (square) move using the keys in the keyboard
 *  - each key in a keyboard has a 'keyCode' represting a value or 
 *    symbol code
 *  - to check which key was pressed, create a function called 'keyPressed()'
 *  - to move the square you will need a variable to store its X coordinate
 *    (horizontal movement)
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
 
void setup() {
  size(400, 400);  // Draw the sketch at a not-too-small size
}

void draw() {
  background(200);  // Clear the screen
  ellipse(15, 15, 20, 20);  
  rect(nX, height - 25, 20, 20);  // Draw Newton with a varaible X coordinate
}

void keyPressed() {
  // If the right key was pressed, increase the X coordinate in 3 units
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // If the left key was pressed, decrease the X coordinate in 3 units
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
}
