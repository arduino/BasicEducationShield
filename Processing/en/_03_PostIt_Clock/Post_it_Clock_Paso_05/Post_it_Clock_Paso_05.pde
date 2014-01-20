/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 5:
 *  - add more images to your program
 *  - remember you need to drag them over the IDE or copy them directly in the
 *    'data' folder inside your sketch
 *  - use the 'for()' loop to load all of the images into the array in a more
 *    efficient way
 *  - the 'for()' loop:
 *    + is used to execute repetitive actions
 *    + is useful to navigate through arrays
 *    + has three parameters separated by ';' (semicolon)
 *    + for( initialization; comparison; increment)
 *
 *  Note: look for more information about 'for' in Processing's reference
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im[] = new PImage[4];   // Make your array bigger for it to contain 4 images
String imFile[] = {"postit.jpg", "peninsula.jpg", "tortilla.jpg", "banana.jpg"}; 

void setup() {
  size(800, 800);  // Make your sketch bigger to show all the images at once   
  for (int i = 0; i < 4; i = i + 1) {
    im[i] = loadImage(imFile[i]);  // Load images according to the counter 'i'
  }
}

void draw() {
  image(im[0], 0, 0);   // Show the images
  image(im[1], 400, 0);  
  image(im[2], 0, 400);  
  image(im[3], 400, 400);  
}
