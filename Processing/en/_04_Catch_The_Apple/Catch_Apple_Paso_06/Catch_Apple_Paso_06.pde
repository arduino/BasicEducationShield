/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 6:
 *  - detect the apple landing on Newton's head to be able of counting points;
 *    checking whether two objects on a screen touch each other is called 
 *    "collision detection"
 *  - use the conditional functions 'if-else' to check whether the circle is
 *    on top of the square, if so, change the filling color to red
 *  - to make the program easier, make a variable to store the square's Y coordinate
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
int nX = 0;
int nY = 0;  // Y coordinate for the square
int mY = 0;  
int mX = 15;
 
void setup() {
  size(400, 400);  
  nY = height - 25;  // Init the coordinate Y for the square to be at the end of the screen
}

void draw() {
  background(200);  
  
  mY = mY + 1;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  
  }
  
  fill(255);  // By default fill in the shapes white
  
  // Collision detection
  if (mY + 10 > nY && mY - 10 < nY + 20) {  // Is the circle at the same height as the square?
    if (mX + 10 > nX && mX - 10 < nX + 20) { // Is the circle on top of the square?
      fill(255, 0, 0);  // Change the filling color to red
    } 
  }

  // Lines to understand collision detection
  // uncomment them to test how things work
  //line(0,mY-10,width,mY-10);
  //line(mX-10,0,mX-10,height);
  //line(0,mY+10,width,mY+10);
  //line(mX+10,0,mX+10,height);
  
  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20);    // Include a variable to control the Y coordinate 
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
