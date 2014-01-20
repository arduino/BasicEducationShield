/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 2:
 *  - haz que Newton (el cuadrado) se mueva con las flechas del teclado
 *  - el teclado se llama 'keyboard' en ingles, y las teclas 'keys'
 *  - cada tecla tiene un 'keyCode', es el valor o codigo del simbolo que representa
 *  - para ver que tecla se presiono, crea una funcion llamada 'keyPressed()'
 *  - para mover el cuadro necesitaras una variable para almacenar su coordenada
 *    en el eje X (horizontal)
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
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
