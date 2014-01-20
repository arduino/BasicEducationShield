/*
 * Red Snake (Serpiente Roja)
 *
 * Programa para crear una serpiente roja moviendose por la pantalla
 * 
 * Paso 1:
 *  - crea un programa en una ventana de 400x400 pixels
 *  - dibuja un circulo rojo de 30 pixels de diametro
 *  - haz que el dibujo no tenga borde, usa el comando 'noStroke()'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */
 
void setup() {
  size(400, 400);
}

void draw() {
  noStroke();                // Dibuja formas sin 'borde'
  fill(255, 0, 0);           // Haz que las figuras sean de color rojo
  ellipse(100, 100, 30, 30); // Circulo de 30 pixels de diametro
}
