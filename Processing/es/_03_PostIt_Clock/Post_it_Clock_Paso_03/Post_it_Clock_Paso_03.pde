/**
 * Paso 3
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
