/**
 * Paso 1
 */

PImage im;

void setup() {
  size(400, 400);   // Hacemos el programa del tamaño de la imagen
  im = loadImage("foto.jpg");  // Nombre de la imagen
}

void draw() {
  image(im, 0, 0);  // Para mostrar la imagen en la pantalla, coordenadas 0, 0
}
