/*
 * Red Snake 
 *
 * Program to create a red snake moving through the screen
 * 
 * Step 5:
 *  - change the intensity of red with the time
 *  - for a better visual effect and avoiding the color red of changing
 *    abruptly, use a mathematical function (e.g. 'sin()')
 *  - you will need a variable to count the time
 *  - the number '20' in the equation calculating the amount of red determines
 *    how often will a color be repeated
 *
 * Note: the function 'sin()' will return a floating point number (of the type 'float')
 *       and therefore we need to use the function 'int()' to assign that value to the
 *       variable storing the color
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

int rojo = 255;
int tiempo = 0;
 
void setup() {
  size(400, 400);
}

void draw() {
  tiempo = tiempo + 1;  // Increase time in one unit
  rojo = int(128 * (1 + sin(tiempo * 2 * PI / frameRate / 20)));  // Change the color red, repeat every 20s
  
  noStroke();             
  fill(rojo, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); 
}
