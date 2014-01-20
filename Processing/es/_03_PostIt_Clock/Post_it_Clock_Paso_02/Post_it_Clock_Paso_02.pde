/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 2:
 *  - modifica el programa para que muestre dos imagenes
 *  - necesitaras dos variables, una para cada imagen
 *  - la funcion 'imgage()' usa coordenadas, muestra las imagenes una junto a otra
 *  - incluye la segunda imagen en el progama arrastrandola sobre el IDE
 *
 *  Nota: si tus imagenes son de 400x400, necesitaras un programa de 800x400 pixels
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im;
PImage im2;

void setup() {
  size(800, 400);   // Hacemos el programa dos veces el tamaño de la imagen en ancho
  im = loadImage("foto.jpg");  
  im2 = loadImage("foto2.jpg");  // Nombre de la segunda imagen
}

void draw() {
  image(im, 0, 0); 
  image(im2, 400, 0);  // Para mostrar la segunda imagen en la pantalla, coordenadas 400, 0
}
