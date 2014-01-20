/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 2:
 *  - modify the sketch to show two images
 *  - you will need two variables, one for each image
 *  - the function 'image()' uses coordinates as parameters, and shows images one by the other
 *  - include the second image in the program dragging it over the IDE
 *
 *  Note: if your images are of 400x400 pixels, you will need a program 800x400 pixels
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im;
PImage im2;

void setup() {
  size(800, 400);   // Make the sketch twice the image's width
  im = loadImage("foto.jpg");  
  im2 = loadImage("foto2.jpg");  // Load the second image
}

void draw() {
  image(im, 0, 0); 
  image(im2, 400, 0);  // To show the second image use coordinates 400, 0
}
