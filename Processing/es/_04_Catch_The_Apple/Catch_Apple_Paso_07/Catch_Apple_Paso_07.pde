/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 7:
 *  - modifica la forma en la que caen las manzanas para que caigan con mayor velocidad
 *  - introduce una variable para almacenar la velocidad de caida de la manzana
 *  - declara esa variable 'mV' como un numero en coma flotante
 *  - puedes cambiar la velocidad con solo cambiar el valor de esa variable
 *  - para poder controlar mejor el movimiento en el eje Y de la manzana, modifica el tipo
 *    de variable de 'mY' para que sea 'float'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
int nX = 0;
int nY = 0; 
float mY = 0;  // Modifica el tipo de la variable mY a float
int mX = 15;
float mV = 3;  // Velocidad de caida de las manzanas
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Movimiento de la manzana
  mY = mY + mV;  // Introduce la velocidad en forma de incremento
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  
  }
  
  fill(255);  
  
  // Deteccion de la colision
  if (mY + 10 > nY && mY - 10 < nY + 20) {  
    if (mX + 10 > nX && mX - 10 < nX + 20) { 
      fill(255, 0, 0);  
    } 
  }

  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20);    
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
