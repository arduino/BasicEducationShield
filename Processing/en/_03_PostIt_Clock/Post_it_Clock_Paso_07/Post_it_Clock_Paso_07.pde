/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 7:
 *  - take the time from the computer and represent the numbers using the images
 *  - get the hour from the system using 'hour()'
 *  - take into account that the hour has two digits and that you need to find a way
 *    to separate those
 *
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im[] = new PImage[10];   // Array for 10 images
String imFile[] = {"0.jpg", "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg", "6.jpg", "7.jpg", "8.jpg", "9.jpg"}; 

void setup() {
  size(140, 95);  // 2 digits of 70x95 pixels
  for (int i = 0; i < 10; i = i + 1) {
    im[i] = loadImage(imFile[i]);  
  }
}

void draw() {
  int h = hour();             // Take the hour from the computer and store it into a variable
  int h_dec = int(h / 10);    // Get the most significant digit
  int h_uni = h - h_dec * 10; // Get the least significant digit
  
  image(im[h_dec], 0, 0);     // Show the most significant digit
  image(im[h_uni], 70, 0);    // Show the least significant digit
}
