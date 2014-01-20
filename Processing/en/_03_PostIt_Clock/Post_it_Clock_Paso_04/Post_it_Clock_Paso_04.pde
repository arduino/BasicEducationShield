/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 4:
 *  - modify the program so that image names are stored in an array, in this way you
 *    will have two arrays, one for the image names and one for the actual images
 *  - take advantage of the fact that you can make an array declaring it's content
 *    between curly brackets '{data, data2, ...} with the different data separated by commas
 *  - in the example, "foto.jpg" is array's position 0, "foto2.jpg" is 1
 *
 *  Note: this program is making the same as the previous one
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im[] = new PImage[2]; 
String imFile[] = {"foto.jpg", "foto2.jpg"};  // Array with the file names

void setup() {
  size(800, 400);   
  im[0] = loadImage(imFile[0]);  // Use 'loadImage()' to load the first image file
  im[1] = loadImage(imFile[1]);  // Second image file
}

void draw() {
  image(im[0], 0, 0); 
  image(im[1], 400, 0);  
}
