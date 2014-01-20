/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 3:
 *  - modifica el programa para que use arrays
 *  - los arrays:
 *    + son variables que pueden almacenar mas de un dato
 *    + tienen un solo nombre, por ejemplo 'img'
 *    + los datos se distinguen porque "van numerados", es lo que llamamos "indexados"
 *    + el primer dato es el 0, el segundo el 1, el tercero el 2 ...
 *    + un dato se pide con el nombre del array seguido del numero entre 
 *      cochetes 'img[3]'
 *    + se declaran usando el tipo de variable con corchetes (mira el codigo)
 *    + al declararlos hay que decir cuantos datos van a contener
 *
 *  Nota: este programa hace lo mismo que el anterior, solo que de forma mas eficiente
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im[] = new PImage[2]; // Declaracion de un array de 2 imagenes

void setup() {
  size(800, 400);   
  // La primera imagen va a la primera posicion del array img[]
  im[0] = loadImage("foto.jpg");   
  // La segunda imagen va a la segunda posicion del array
  im[1] = loadImage("foto2.jpg");  
}

void draw() {
  image(im[0], 0, 0); 
  image(im[1], 400, 0);  
}
