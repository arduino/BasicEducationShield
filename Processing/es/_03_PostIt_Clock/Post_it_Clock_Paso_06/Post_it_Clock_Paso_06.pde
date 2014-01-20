/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 6:
 *  - crea imagenes que representen numeros (por si acaso, aqui tienes unas
 *    hechas con post-it)
 *  - modifica el programa para que muestre todos los numeros del 0 al 9
 *  - puedes usar 'for()' para mostrar las imagenes
 *  - este programa te servira como base para cualquier programa donde quieras
 *    representar numeros, si por ejemplo quieres mostrar el 5 en la pantalla,
 *    solo tienes que invocar 'image(img[5], coorX, coorY)'
 *
 *  Nota: como quieres mostrar todos los numeros, tendras que hacer imagenes mas
 *        pequeñas, por ejemplo de 70 pixels de ancho
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im[] = new PImage[10];   // Array para 10 imagenes
String imFile[] = {"0.jpg", "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg", "6.jpg", "7.jpg", "8.jpg", "9.jpg"}; 

void setup() {
  size(700, 95);  // 10 imagenes de 70 pixels de ancho y 95 de alto   
  for (int i = 0; i < 10; i = i + 1) {
    im[i] = loadImage(imFile[i]);  
  }
}

void draw() {
  for (int i = 0; i < 10; i = i + 1) {
    image(im[i], 70 * i, 0);  // Muestra las imagenes en secuencia
  }
}
