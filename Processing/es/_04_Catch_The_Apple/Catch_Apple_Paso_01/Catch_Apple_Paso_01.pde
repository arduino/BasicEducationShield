/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Nota: si no conoces el mito de Newton y la manzana, te recomiendo que lo busques
 *       en la enciclopedia, internet, o similar
 *
 * Paso 1:
 *  - crea la pantalla del juego, las manzanas, por ahora, seran circulos que caen del
 *    cielo, mientras que Newton sera un cuadrado
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
void setup() {
  size(400, 400);  // Haz la pantalla de un tamaño medio
}

void draw() {
  ellipse(15, 15, 20, 20);  // Dibuja una manzana en lo alto de la pantalla
  rect(width / 2, height - 25, 20, 20);  // Dibuja a Newton al fondo de la pantalla
}
