/*
 * Catch the Apple (Caza la Manzana)
 *
 * Creacion de un videojuego con Processing. El objetivo de este ejercicio es
 * llevar la programacion un poco mas lejos y crear un pequeño videojuego donde
 * nuestro aguerrido heroe, el famoso cientifico Newton, intenta no perder la
 * oportunidad de que la manzana le caiga en la cabeza.
 *
 * Paso 6:
 *  - detecta que la manzana aterriza en la cabeza de Newton para poder contar
 *    puntos; la accion de detectar que dos objetos se encuentran en la pantalla
 *    se llama "deteccion de colision"
 *  - emplea las funciones condicionales 'if-else' para ver si el circulo
 *    esta sobre el cuadrado, de ser asi, cambia el color del cuadro a rojo
 *  - para hacer el programa mas sencillo, crea una variable para almacenar las 
 *    coordenadas en Y del cuadrado
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Suecia
 */
 
int nX = 0;
int nY = 0;  // Coordenada Y de la posicion del cuadrado
int mY = 0;  
int mX = 15;
 
void setup() {
  size(400, 400);  
  nY = height - 25;  // Inicializa la coordenada Y del cuadrado al fondo de la pantalla
}

void draw() {
  background(200);  
  
  mY = mY + 1;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20));  
  }
  
  fill(255);  // Por defecto pinta los objetos en blanco
  
  // Deteccion de la colision
  if (mY + 10 > nY && mY - 10 < nY + 20) {  // Detecta si el circulo esta a la altura del cuadrado
    if (mX + 10 > nX && mX - 10 < nX + 20) { // Detecta si el circulo esta sobre el cuadrado
      fill(255, 0, 0);  // Cambia el color de relleno a rojo
    } 
  }

  // Lineas para comprender la deteccion de colision
  // borra el comentario para poder ver estas lineas
  //line(0,mY-10,width,mY-10);
  //line(mX-10,0,mX-10,height);
  //line(0,mY+10,width,mY+10);
  //line(mX+10,0,mX+10,height);
  
  ellipse(mX, mY, 20, 20); 
  rect(nX, nY, 20, 20);    // Incluye la variable para controlar la coordenada Y  
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
