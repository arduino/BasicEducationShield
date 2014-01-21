/*
 * Red Snake (Serpiente Roja)
 * Paso 2
 */
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();             
  fill(255, 0, 0);          
  ellipse(mouseX, mouseY, 30, 30); // Circulo de en funcion de las coordenadas del raton
}
