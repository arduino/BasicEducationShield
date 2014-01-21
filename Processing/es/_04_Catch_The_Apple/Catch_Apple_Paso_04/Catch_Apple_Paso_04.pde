/*
 * Paso 4
 */
 
int nX = 0;
int mY = 0;  // Coordenada Y de la manzana
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  
  mY = mY + 1;  // Incrementa la coordenada de la manzana
  if (mY > height) {
    mY = 15;    // Si la manzana llega al suelo, ponla arriba de nuevo
  }
  ellipse(15, mY, 20, 20);   // Cambia la coordenada Y para que sea la variable 
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
  if (nX > width - 20) {  
    nX = width - 20;
  }
}
