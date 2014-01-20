/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 3:
 *  - modify the sketch to use arrays
 *  - arrays:
 *    + are variables that can store more than one data
 *    + have a single name, e.g. 'img'
 *    + the data can be distinguished because it is "numbered", it is what we call "indexed"
 *    + the first piece of data is indexed with 0, the second is 1, the third is 2 ...
 *    + a block of data can be addressed with the array name followed by the index number
 *      between square brackets 'img[3]'
 *    + are declared using the variable type and square brackets (check the code)
 *    + when declared you need to specify how many blocks of data it will contain
 *
 *  Note: this program is doing the same as the previous one, but in a more efficient way
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im[] = new PImage[2]; // Declare an array to contain 2 images

void setup() {
  size(800, 400);   
  // The first image goes into the first position of the array img[]
  im[0] = loadImage("foto.jpg");   
  // The second image goes into the second position of the array
  im[1] = loadImage("foto2.jpg");  
}

void draw() {
  image(im[0], 0, 0); 
  image(im[1], 400, 0);  
}
