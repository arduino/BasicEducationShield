/*
 * Paso 1
 */
 
void setup() {
  size(400, 400);  // Haz la pantalla de un tamaño medio
}

void draw() {
  ellipse(15, 15, 20, 20);  // Dibuja una manzana en lo alto de la pantalla
  rect(width / 2, height - 25, 20, 20);  // Dibuja a Newton al fondo de la pantalla
}
