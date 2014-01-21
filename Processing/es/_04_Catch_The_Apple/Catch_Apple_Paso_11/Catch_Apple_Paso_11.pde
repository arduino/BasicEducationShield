/*
 * Paso 11
 */
 
int nX = 0;      // Coordenada X, Newton
int nY = 0;      // Coordenada Y, Newton
float mY = 0;    // Coordenada Y, manzanas
int mX = 15;     // Coordenada X, manzanas
float mV = 0;    // Velocidad Y, manzanas
float mA = 0.05; // Aceleracion Y, manzanas
int p = 0;       // Puntos conseguidos
boolean pCount = true;  // Almacena si se pueden contar puntos o no
long t = 0;      // Almacena el tiempo 
 
void setup() {
  size(400, 400);  
  nY = height - 25; 
  t = millis();  // Inicializa la variable de tiempo
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

  
  // Contabilizacion del tiempo
  float timer = (millis() - t) / 1000;  // Cuenta cuanto tiempo ha pasado en segundos

  // Fin del juego (GAME OVER)
  if (timer >= 30) {  // Si el tiempo alcanza 30000 es el fin del juego
    noLoop();
  }

  // Muestra el tiempo en la pantalla
  fill(0);
  text("Tiempo: " + (30 - timer), 10, 20);

  // Muestra los puntos en pantalla
  fill(0);  
  text("Manzanazos: " + p, 3 * width / 4, 20); 
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
