/*	
  StandardServo
*/
#include <BasicEducationShield.h>
#include <Servo.h>

Servo me;

void setup(){
  //Servo is initialized, 
  me.attach(9);
}

void loop(){
  //Make the servo rotate to 76 degrees.
  me.write(76);

}
