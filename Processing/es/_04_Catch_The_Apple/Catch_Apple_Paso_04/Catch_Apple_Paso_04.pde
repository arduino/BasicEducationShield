/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 4:
 *  - modifica el programa para hacer que la manzana caiga
 *  - necesitaras una variable para contener la coordenada Y de la manzana
 *  - cuando la manzana toque el suelo, deberas volver a "colgarla" del arbol
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
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
