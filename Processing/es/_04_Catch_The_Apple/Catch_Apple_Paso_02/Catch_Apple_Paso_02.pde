/*
 * Paso 2
 */
 
int nX = 0;
 
void setup() {
  size(400, 400);  // Haz la pantalla de un tamaño medio
}

void draw() {
  background(200);  // Limpia la pantalla
  ellipse(15, 15, 20, 20);  
  rect(nX, height - 25, 20, 20);  // Dibuja a Newton con coordenada X variable
}

void keyPressed() {
  // Si se presiono la tecla derecha, incrementa las coordenadas en 3 unidades
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Si se presiono la tecla inzquierda, decrementa las coordenadas en 3 unidades
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
}
