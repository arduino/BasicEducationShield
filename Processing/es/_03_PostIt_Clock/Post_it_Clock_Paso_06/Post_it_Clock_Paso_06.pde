/**
 * Paso 6
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
