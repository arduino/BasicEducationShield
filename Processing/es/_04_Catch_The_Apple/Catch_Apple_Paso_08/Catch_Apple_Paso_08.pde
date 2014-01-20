/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 8:
 *  - modifica la caida de las manzanas para que responda a la aceleracion
 *    de la gravedad
 *  - como sabes, la velocidad se calcula desde la aceleracion, y la posicion
 *    desde la velocidad
 *  - introduce una variable que represente la aceleracion, hazla de tipo 'float'
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
int nX = 0;
int nY = 0; 
float mY = 0;  
int mX = 15;
float mV = 0;     // La velocidad inicial de las manzanas es cero
float mA = 0.05;  // Aceleracion de caida de la manzana (0.98 seria demasiado)
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Movimiento de la manzana
  mV = mV + mA;  // Calcula la velocidad instantanea en funcion de la aceleracion
  mY = mY + mV;  // Calcula la posicion en funcion de la velocidad
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20)); 
    mV = 0;  // Al comenzar a caer, las manzanas empiezan con velocidad cero 
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
