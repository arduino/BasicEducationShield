/**
 * Hunting Cookie Monster
 *
 * Someone is eating our cookies, let's gather some proof
 * about that person and get him/her to confess.
 *
 * This program initializes a webcam connected to a PC
 * and listens to the serial port. If a "P" command arrives
 * it will then take a picture with the webcam and store it
 * locally in the sketch folder.
 * 
 * (c) 2013 B. & D. Cuartielles in a quest for the truth 
 * This is Free Software under GPLv3
 * Based on previous code by C. Reas and B. Fry
 */ 
 
import processing.video.*;
import processing.serial.*;

Capture cam;
Serial myPort;  // The serial port

void setup() {
  size(640, 480, P2D);

  initializeCamera(0);

  // List all the available serial ports
  println(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  if (cam.available() == true) {
    cam.read();
  }
  image(cam, 0, 0);
  
  String timeStamp=createTimeStamp();
  
  text(timeStamp, 10, height-10);


  
  // for the keyboard detection to work, you need to have
  // clicked on the application window first (aka focus)
  if(keyPressed) {
    if (key == 'p' || key == 'P') {
      captureImage(timeStamp);
    }
  }
  
  if (myPort.available() > 0) {
    int inByte = myPort.read();
    if(inByte == 'p') {
      captureImage(timeStamp);
    }
  }  
}





void initializeCamera(int camNum){
  String[] cameras = Capture.list();
  
  if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("Available cameras:");
    for (int i = 0; i < cameras.length; i++) {
      println("["+i+"] "+cameras[i]);
    }
    
    // The camera can be initialized directly using an element
    // from the array returned by list():
    cam = new Capture(this, cameras[camNum]);
    cam.start();     
  }   

  // we don't need the camera at full blast
  frameRate(1);  

}

String createTimeStamp(){
  String timeStamp = String.format("%02d", hour());
  timeStamp += ":" + String.format("%02d", minute());
  timeStamp += ":" + String.format("%02d", second());
  timeStamp += " " + year();
  timeStamp += "/" + String.format("%02d", month());
  timeStamp += "/" + String.format("%02d", day());
  
  return timeStamp;
}

void captureImage(String timeStamp){
      saveFrame("pic-######.png");
      println("capturing Frame at: " + timeStamp);
}
