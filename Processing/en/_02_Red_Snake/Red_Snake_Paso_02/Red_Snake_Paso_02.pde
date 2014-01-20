/*
 * Red Snake 
 *
 * Program to create a red snake moving through the screen
 * 
 * Step 2:
 *  - make the circle move according to the mouse coordinates ('mouseX' and 'mouseY')
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();             
  fill(255, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); // Circle's placement following the mouse pointer
}
