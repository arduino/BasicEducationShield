/*
 * Red Snake 
 *
 * Program to create a red snake moving through the screen
 * 
 * Step 1:
 *  - create a program in a 400x400 pixels window
 *  - draw a red circle of 30 pixels diameter
 *  - make the drawing without a border, use the 'noStroke()' command
 *  - the number '20' in the equation calculating the amount of red determines
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();                // Draw borderless shapes
  fill(255, 0, 0);           // Fill shapes with pure red color
  ellipse(100, 100, 30, 30); // Circle of 30 pixels diameter
}
