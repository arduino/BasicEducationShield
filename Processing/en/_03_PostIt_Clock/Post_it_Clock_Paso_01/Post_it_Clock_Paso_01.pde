/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 1:
 *  - create a sketch showing an image
 *  - to load the image in your sketch, choose an image and drag it over the IDE,
 *    it will then be stored in a folder accessible to your program
 *  - you can check that the IDE created a subfolder called 'data' inside the
 *    folder in your program, open the folder from the menu 'Sketch --> Show Sketch Folder'
 *  - the images:
 *    + are from the 'PImage' type
 *    + are shown using the function 'image()'
 *    + are loaded using 'loadImage()'
 *
 *  Note: before inserting an image into a sketch, make sure it is not too big,
 *        reduce it's size to fit the 400x400 pixels of the program's size
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im;

void setup() {
  size(400, 400);   // We make the sketch the size of the image
  im = loadImage("foto.jpg");  // Image name
}

void draw() {
  image(im, 0, 0);  // To show the image on the screen at the coordinates 0, 0
}
