/*
 * Red Snake (Serpiente Roja)
 * Paso 3
 */

int rojo = 255;
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();             
  fill(rojo, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); // Circulo de en funcion de las coordenadas del raton
}
