/*
 * Red Snake (Serpiente Roja)
 *
 * Programa para crear una serpiente roja moviendose por la pantalla
 * 
 * Paso 4:
 *  - cambia la intensidad del rojo en funcion del tiempo
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

int rojo = 255;
 
void setup() {
  size(400, 400);
}

void draw() {
  rojo = rojo - 1;            // Haz el rojo un poco mas obscuro
  if (rojo < 0) rojo = 255;   // Cuando llegue al maximo de obscuridad, hazlo claro otra vez
  
  noStroke();             
  fill(rojo, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); 
}
