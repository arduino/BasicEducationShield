/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Note: if you don't know about Newton's myth with the apple, you should
 *       check it out on an encyclopedia, internet, or the like
 *
 * Step 1:
 *  - creat the game screen, the apples will be circles falling from the sky, while
 *    Newton will be represented by a square. We will change those later
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
void setup() {
  size(400, 400);  // Make the screen of an average size
}

void draw() {
  ellipse(15, 15, 20, 20);  // Draw the apple at the top of the screen
  rect(width / 2, height - 25, 20, 20);  // Draw Newton at the bottom of the screen
}
