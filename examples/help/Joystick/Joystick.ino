/*	Joystick
*/

#include <BasicEducationShield.h>

//The joystick uses two analog pins. One for X and one for Y.
Joystick me=Joystick(A1,A0);

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.print("X: ");
  Serial.print(me.getX()); //Get the X value and print it.
  Serial.print("  Y: ");
  Serial.println(me.getY()); //Get the Y value and print it.
  delay(200);
}
