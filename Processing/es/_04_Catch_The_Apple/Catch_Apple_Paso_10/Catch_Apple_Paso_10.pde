/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 10:
 *  - los puntos se estan contabilizando extra, corrigelo
 *  - esto lo podras conseguir de dos formas:
 *    + volviendo a lanzar la manzana en cuanto se detecte colision, o
 *    + dejando de contar una vez hay colision y hasta que se lance una
 *      nueva manzana
 *  - en cualquier caso, necesitas una variable de tipo 'boolean' que 
 *    almacenara el estado de poder contar o no puntos, la tendras que
 *    reiniciar a 'true' cada vez que se lance la manzana de nuevo
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
int nX = 0;      // Coordenada X, Newton
int nY = 0;      // Coordenada Y, Newton
float mY = 0;    // Coordenada Y, manzanas
int mX = 15;     // Coordenada X, manzanas
float mV = 0;    // Velocidad Y, manzanas
float mA = 0.05; // Aceleracion Y, manzanas
int p = 0;       // Puntos conseguidos
boolean pCount = true;  // Almacena si se pueden contar puntos o no
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
}

void draw() {
  background(200);  
  
  // Movimiento de la manzana
  mV = mV + mA;  
  mY = mY + mV;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20)); 
    mV = 0;   
    pCount = true;  // Al lanzar una nueva manzana, se podran volver a contar puntos
  }
  
  fill(255);  
  
  // Deteccion de la colision
  if (mY + 10 > nY && mY - 10 < nY + 20) {  
    if (mX + 10 > nX && mX - 10 < nX + 20) { 
      fill(255, 0, 0);  
      // Si hay colision, incrementa un punto
      if (pCount) p = p + 1;
      pCount = false;  // En cualquier caso, cada vez que se entre 
                       // aqui, ya no se pueden contar puntos
    } 
  }

  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20); 

  // Muestra los puntos en pantalla
  fill(0);  // Color del texto
  text("Manzanazos: " + p, 3 * width / 4, 20);  // Texto a la derecha de la pantalla
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
