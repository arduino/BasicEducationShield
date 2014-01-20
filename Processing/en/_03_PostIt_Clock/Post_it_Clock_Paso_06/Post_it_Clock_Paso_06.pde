/**
 * Post-it Clock  
 * 
 * This project's goal is creating a clock using images to represent numbers.
 *
 * Step 6:
 *  - create images representing numbers (just in case here you have some made with post-it notes)
 *  - modify the program for it to show all the numbers from 0 to 9
 *  - you can use 'for()' to show the images
 *  - this program will be your base to any program you want to do where you want to represent
 *    numbers, just in case, if you want to show number 5 on the screen, just invoke 'image(img[5], coorX, coorY)'
 *
 *  Note: as you want to show all the numbers, you will have to make the images smaller, e.g. 70 pixels wide
 *  
 * (c) 2013 D. Cuartielles, Arduino Verkstad, Sweden 
 */

PImage im[] = new PImage[10];   // Array for 10 images
String imFile[] = {"0.jpg", "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg", "6.jpg", "7.jpg", "8.jpg", "9.jpg"}; 

void setup() {
  size(700, 95);  // 10 images of 70 pixels wide and 95 pixels high   
  for (int i = 0; i < 10; i = i + 1) {
    im[i] = loadImage(imFile[i]);  
  }
}

void draw() {
  for (int i = 0; i < 10; i = i + 1) {
    image(im[i], 70 * i, 0);  // Show the images in sequence
  }
}
