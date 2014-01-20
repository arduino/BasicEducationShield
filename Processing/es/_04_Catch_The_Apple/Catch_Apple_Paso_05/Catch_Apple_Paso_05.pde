/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 5:
 *  - la manzana cae siempre del mismo sitio, cambia su coordenada X de origen para
 *    que cada vez salga de un sitio distinto del arbol
 *  - la funcion que te da un numero aleatorio se llama 'random()' y te devuelve un
 *    un numero entre 0 y el parametro que especifiques entre los parentesis
 *  - necesitaras una nueva variable para almacenar la posicion en X de la manzana
 *  - la coordenada habra que cambiarla solo cuando la manzana llegue al suelo
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
int nX = 0;
int mY = 0;  
int mX = 15; // Coordenada X de la manzana
 
void setup() {
  size(400, 400);  
}

void draw() {
  background(200);  
  
  mY = mY + 1;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  // Inicializa la coordenada X de forma aleatoria
  }
  ellipse(mX, mY, 20, 20);  // Añade la coordenada X para el movimiento del circulo 
  rect(nX, height - 25, 20, 20);  
}

void keyPressed() {
  // Incrementa las coordenadas en 3 unidades
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Decrementa las coordenadas en 3 unidades
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
  // Limita el valor de la coordenada X
  if (nX < 0) {
    nX = 0;
  }
  if (nX > width - 20) {  
    nX = width - 20;
  }
}
