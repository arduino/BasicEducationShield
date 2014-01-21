/*
 * Paso 5
 */
 
int nX = 0;
int mY = 0;  
int mX = 15; // Coordenada X de la manzana
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  
  mY = mY + 1;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  // Inicializa la coordenada X de forma aleatoria
  }
  ellipse(mX, mY, 20, 20);  // Añade la coordenada X para el movimiento del circulo 
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
