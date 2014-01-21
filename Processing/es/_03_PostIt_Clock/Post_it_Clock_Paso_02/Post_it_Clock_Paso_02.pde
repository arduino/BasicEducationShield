/**
 * Paso 2
 */

PImage im;
PImage im2;

void setup() {
  size(800, 400);   // Hacemos el programa dos veces el tamaño de la imagen en ancho
  im = loadImage("foto.jpg");  
  im2 = loadImage("foto2.jpg");  // Nombre de la segunda imagen
}

void draw() {
  image(im, 0, 0); 
  image(im2, 400, 0);  // Para mostrar la segunda imagen en la pantalla, coordenadas 400, 0
}
