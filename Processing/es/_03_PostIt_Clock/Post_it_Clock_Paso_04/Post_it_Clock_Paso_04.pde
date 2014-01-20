/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 4:
 *  - modifica el programa de modo que los nombres de imagenes se almacenen
 *    en un array, de este modo tendras dos arrays, uno para los nombres de
 *    imagenes y otro para las imagenes
 *  - toma ventaja del hecho de que se puede hacer un array declarando sus
 *    contenidos entre llaves '{dato, dato2 ...}' con los datos separados por comas
 *  - en el programa ejemplo, "foto.jpg" es la posicion 0 del array, 
 *    "foto2.jpg" es la 1
 *
 *  Nota: este programa hace lo mismo que el anterior
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im[] = new PImage[2]; 
String imFile[] = {"foto.jpg", "foto2.jpg"};  // Array de nombres de fichero

void setup() {
  size(800, 400);   
  im[0] = loadImage(imFile[0]);  // Primer fichero a la funcion 'loadImage()'
  im[1] = loadImage(imFile[1]);  // Segundo fichero
}

void draw() {
  image(im[0], 0, 0); 
  image(im[1], 400, 0);  
}
