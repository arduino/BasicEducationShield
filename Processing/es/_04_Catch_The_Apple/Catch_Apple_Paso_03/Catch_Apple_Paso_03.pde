/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 3:
 *  - limita el movimiento de Newton dentro de la ventana
 *  - para esto vas a usar las funciones condicionales 'if-else'
 *  - comprobaras que la coordenada nX esta siempre dentro de la
 *    ventana del programa, es decir, habra de ser mayor que 0 y
 *    menor que la anchura de la ventana o 'width'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
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
