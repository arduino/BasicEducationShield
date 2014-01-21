/**
 * Paso 7
 */

PImage im[] = new PImage[10];   // Array para 10 imagenes
String imFile[] = {"0.jpg", "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg", "6.jpg", "7.jpg", "8.jpg", "9.jpg"}; 

void setup() {
  size(140, 95);  // 2 digitos de 70 pixels de ancho y 95 de alto   
  for (int i = 0; i < 10; i = i + 1) {
    im[i] = loadImage(imFile[i]);  
  }
}

void draw() {
  int h = hour();             // Toma la hora del reloj del ordenador y almacenalo en una variable
  int h_dec = int(h / 10);    // Extrae el digito de mayor peso de la hora (decenas)
  int h_uni = h - h_dec * 10; // Extrae el digito de menor peso de la hora (unidades)
  
  image(im[h_dec], 0, 0);     // Muestra el digito de las decenas
  image(im[h_uni], 70, 0);    // Muestra el digito de las unidades
}
