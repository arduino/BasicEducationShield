/*
 * Paso 3
 */
 
int nX = 0;
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  ellipse(15, 15, 20, 20);  
  rect(nX, height - 25, 20, 20);  
}

void keyPressed() {
  // Incrementa las coordenadas en 3 unidades
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Decrementa las coordenadas en 3 unidades
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
  // Limita el valor de la coordenada X
  if (nX < 0) {
    nX = 0;
  }
  if (nX > width - 20) {  // Por la derecha tienes que tener en cuenta el tamaño del cuadrado
    nX = width - 20;
  }
}
