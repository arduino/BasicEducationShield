#include <Castilla.h>
#include <Servo.h>

// Servo is connected to tinkerkit digital 9
LimitedServo me=LimitedServo(9);

void setup(){
  me.begin(); //servo is initialized
}

void loop(){
/*
  Set the angle of the servo. 
  Values are from 0 degrees to 180 degrees
*/
  me.setAngle(76);
}
