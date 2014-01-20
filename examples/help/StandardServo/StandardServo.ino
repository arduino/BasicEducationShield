/*	
  StandardServo
  
  180º standard servos are a type of motor which have a limited 
  rotation angle. It has precise control over the angle of rotation.
  
  The ones provided for Basic Education Shield projects are 
  microservos. Microservos behave the same as a standard servo, 
  but are slimmer in size and exert less turning power. 
  
  (c) 2013 Arduino Verkstad
*/
#include <BasicEducationShield.h>

//It's necessary to include Servo.h if servo is used
#include <Servo.h>

Servo me;

void setup(){
  //Servo is initialized, 
  //in this example connected to digital pin 9
  me.attach(9);
}

void loop(){
  //write(angle):
  //	angle: the angle to which you want to rotate
  //	the servo. It is ranged between 0 and 180.
  //
  //Make the servo rotate to 76 degrees.
  me.write(76);

}
