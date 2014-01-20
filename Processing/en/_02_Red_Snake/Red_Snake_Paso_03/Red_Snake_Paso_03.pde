/*
 * Red Snake 
 *
 * Program to create a red snake moving through the screen
 * 
 * Step 3:
 *  - store the intensity of the red color in a variable
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */
 
int rojo = 255;
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();             
  fill(rojo, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); // Circle according to the mouse coordinates
}
