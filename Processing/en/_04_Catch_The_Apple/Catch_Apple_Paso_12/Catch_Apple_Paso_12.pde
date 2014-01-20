/*
 * Catch the Apple 
 *
 * Create a videogame using Processing. The game for this exercise is
 * getting your programming skills a little further and making a computer
 * game where our hero, the famous scientist Newton, will no let the chance
 * go of having an apple hitting his head.
 *
 * Step 12:
 *  - include images to show the apple, the background picture and Newton
 *  - you can make your own images or look for them on the internet
 *  - it is important that you use PNG images if you want to have transparency
 *    between the background and the other images
 *  - check that when you change the images, you are also changing the game's 
 *    proportions, you might have to adjust that in the code
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden
 */
 
String[] imFiles = {"fondo.png", "manzana.png", "newton1.png", "newton2.png"};
PImage[] im = new PImage[4];
 
int nX = 0;      // X coordinate, Newton
int nY = 0;      // Y coordinate, Newton
float mY = 0;    // Y coordinate, apples
int mX = 15;     // X coordinate, apples
float mV = 0;    // Y speed, apples
float mA = 0.05; // Y acceleration, apples
int p = 0;       // Points
boolean pCount = true;  // Check whether to count points or not
long t = 0;      // Store the time 

void setup() {
  size(400, 400);  
  nY = height - 135; 
  t = millis();  
  
  // Load the images
  for(int i = 0; i < 4; i = i + 1) {
    im[i] = loadImage(imFiles[i]);
  }
}

void draw() {
  background(200);
  image(im[0], 0, 0, width, height);  // Background image
  
  // Apple's movement
  mV = mV + mA;  
  mY = mY + mV;  
  if (mY > height) {
    mY = 15;    
    mX = int(random(width - 20)); 
    mV = 0;   
    // When throwing a new apple it will be possible 
    // to start counting points again
    pCount = true;  
  }
  
  fill(255);  
  
  // Collision detection
  if (mY + 50 > nY && mY < nY + 135) {  
    if (mX + 40 > nX && mX < nX + 128) { 
      fill(255, 0, 0);  
      // If collision increase the points
      if (pCount) p = p + 1;
      pCount = false;  // Whenever you make it at this point, do not 
                       // count any more points
    } 
  }

  image(im[1], mX, mY);  // Apple
  if(pCount) {
    image(im[2], nX, nY);  // Newton looking for apples
  } else {
    image(im[3], nX, nY);  // Newton got an apple
  } 
  
  // Count the time
  float timer = (millis() - t) / 1000;  // Count how much time has passed in seconds

  // GAME OVER
  if (timer >= 30) {  // If time reaches 30 seconds, end the game
    noLoop();
  }

  // Show the time on the screen
  fill(0);
  textSize(20);  // Increase the font size
  text("Time: " + (30 - timer), 10, 20);

  // Show the points on the screen
  fill(0);  
  textSize(20);  // Increase the font size
  text("Hits: " + p, 3 * width / 4, 20); 
}

void keyPressed() {
  // Increase the coordinates in 3 pixels
  if (keyCode == RIGHT) {
    nX = nX + 3;
  }
  // Decrease the coordinates in 3 pixels
  if (keyCode == LEFT) {
    nX = nX - 3;
  }
  // Limit the X coordinates
  if (nX < 0) {
    nX = 0;
  }
  if (nX > width - 20) {  
    nX = width - 20;
  }
}
