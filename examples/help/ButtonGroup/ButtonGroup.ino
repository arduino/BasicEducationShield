/*  
  ButtonGroup
  ButtonGroup is used for making a few buttons to work together.
  
  (c) 2013 Arduino LLC
*/
#include <BasicEducationShield.h>

//Declaring the button group
ButtonGroup bg;

//Delcaring the pins to which the buttons are connected
int buttons[]={4,5,6};

void setup(){
  Serial.begin(9600);
  //initialize the button group. The first parameter is
  //number of buttons, the seconds is the array containing
  //pins used by these buttons.
  bg.begin(3,buttons);
}
void loop(){
  Serial.println("Please press a button");
  //pressed(timeout)
  //  timeout:milliseconds within which one button should
  //          be pressed. If pressed within time, the function
  //          returns number of the button within inital list.
  //          Otherwise -1. If not used, it waits untill being
  //          pressed.
  //
  //Wait until one button is pressed.
  Serial.println(bg.pressed());
  delay(10);
}
