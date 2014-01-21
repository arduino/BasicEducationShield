/*
 * Red Snake (Serpiente Roja)
 * Paso 1
 */
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();                // Dibuja formas sin 'borde'
  fill(255, 0, 0);           // Haz que las figuras sean de color rojo
  ellipse(100, 100, 30, 30); // Circulo de 30 pixels de diametro
}
