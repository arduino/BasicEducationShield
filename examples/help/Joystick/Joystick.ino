/*	Joystick
*	
*	The joystick returns the position it is being pushed to. 
*       It returns two values, one X value and one Y value. That is the
*       position on the X axis (left to right) and the position on the
*       Y axis (top to bottom).Each value can be -1, 0 or 1 where 0 is 
*       the middle position. E.g. x=-1 and y=1 means that the joysticks
*       position is left top, x=0 and y=-1 means that the position is 
*       middle bottom. 
*       
*/

#include <Castilla.h>

//The joystick uses two analog pins. One for X and one for Y.
Joystick me=Joystick(A1,A0);

void setup(){
  //Start serial comunication to be able to print values to the serial monitor
  Serial.begin(9600);
}
void loop(){
  Serial.print("X: ");  
  Serial.print(me.getX()); //Get the X value and print it. 
  Serial.print("  Y: ");
  Serial.println(me.getY()); //Get the Y value and print it. 
  delay(200);
}
