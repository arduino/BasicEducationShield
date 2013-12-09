/*
POV (Persistence of Vision)

This is a toy consisting of a row of 5 LEDs(VU-meter).
It is a proof of concept of the illusion of a text display
using little effort. The user will have to wave the row of LEDs
quickly back and forth to achieve the effect.
The button helps change settings for the display of this effect.
*/

#include <BasicEducationShield.h>
/*
An array of pin numbers to which LEDs are attached
the defaults are 2 to 6 but you can choose any of the digital pins
*/
int ledPins[] = {2, 3, 4, 5, 6};
int pinCount = 5;
VUMeter vuMeter;

int rowCount = 0; // Stores the number of rows
int rowLength = 22; // Width of the message, copy this number the message array
int delayTime = 9; // Time it takes to show a row in milliseconds

// The message where 0 is LOW and 1 is HIGH
boolean message[5][22]={
  // H H H H   O O O O   L L L L   A A A A
  {0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0}

};

void setup(){
  // If your are using other pins than 2 to 6 you need to configure that here
  vuMeter.config(pinCount, ledPins);

  vuMeter.begin(); //does the same as pinMode, LEDs are outputs
}

void loop(){
 // If the whole array has been drawn
  if(rowCount == rowLength) {
    rowCount = 0; // Reset the rowCount
  } else {
    // Shows the message
    for (int i = 0; i < pinCount; i++) {
      // Checks if the array says HIGH
      if (message[i][rowCount] == 1) {
        vuMeter.on(i);
      } else {
        vuMeter.off(i);
      }
    }
    rowCount++;
  }

  delay(delayTime);// This is the delay per row

}
