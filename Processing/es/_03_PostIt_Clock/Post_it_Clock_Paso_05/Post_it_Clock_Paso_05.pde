/**
 * Paso 5
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
