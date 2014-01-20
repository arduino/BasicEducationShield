/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 1:
 *  - crea un programa que muestre una imagen
 *  - para cargar la imagen en tu programa, selecciona una imagen y arrastrala
 *    sobre el IDE, asi se almacenara en una carpeta accesible a tu programa
 *  - puedes comprobar que se ha creado una carpeta 'data' dentro de la carpeta
 *    de tu programa, abre la carpeta desde el menu 'Sketch --> Show Sketch Folder'
 *  - las imagenes:
 *     + son variables del tipo 'PImage'
 *     + se muestran con la funcion 'imgage()'
 *     + se cargan con 'loadImage()'
 *
 *  Nota: antes de introducir una imagen, asegurate de que no es demasiado grande,
 *        reducela de tamaño a 400x400 o similar para que encaje en tu pantalla
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im;

void setup() {
  size(400, 400);   // Hacemos el programa del tamaño de la imagen
  im = loadImage("foto.jpg");  // Nombre de la imagen
}

void draw() {
  image(im, 0, 0);  // Para mostrar la imagen en la pantalla, coordenadas 0, 0
}
