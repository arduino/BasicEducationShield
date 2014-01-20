/**
 * Post-it Clock (Reloj de Post-it) 
 * 
 * El objetivo de este proyecto es crear un reloj usando imagenes para
 * representar los numeros. 
 *
 * Paso 5:
 *  - añade mas imagenes a tu programa (aqui te pasamos un par mas)
 *  - recuerda que tienes que arrastrarlas sobre el IDE o copiarlas directamente
 *    en la carpeta 'data' de tu programa
 *  - usa el bucle 'for()' para cargar todas tus imagenes en el array de forma
 *    mas eficiente
 *  - el bucle 'for()':
 *    + se usa en programacion para ejecutar acciones que se repiten varias veces
 *    + es util para recorrer arrays
 *    + tiene tres parametros separados por ';' (punto y coma)
 *    + for( inicializacion; comprobacion; incremento )
 *
 *  Nota: busca mas informacion sobre for en la referencia de Processing
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia 
 */

PImage im[] = new PImage[4];   // Haz tu array mas grande para que le quepan 4 imagenes
String imFile[] = {"postit.jpg", "peninsula.jpg", "tortilla.jpg", "banana.jpg"}; 

void setup() {
  size(800, 800);  // Haz tu programa mas grande para acomodar todas las imagenes   
  for (int i = 0; i < 4; i = i + 1) {
    im[i] = loadImage(imFile[i]);  // Carga la imagen segun el contador 'i'
  }
}

void draw() {
  image(im[0], 0, 0);   // Muestra las imagenes
  image(im[1], 400, 0);  
  image(im[2], 0, 400);  
  image(im[3], 400, 400);  
}
