/**
 * Paso 4
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
