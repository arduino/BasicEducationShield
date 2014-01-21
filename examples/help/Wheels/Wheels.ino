/*
  Wheels
*/

#include <BasicEducationShield.h>
#include <Servo.h>

//wheels(left, right)
Wheels wheels=Wheels(10, 9);

void setup(){
  //Initialize the servo wheels
  wheels.begin();
}

void loop(){
  //Makes the wheel spin forward
  wheels.goForward();
  delay(2000);
  
  //Makes the wheels spin backwards
  wheels.goBackwards();
  delay(2000);
  
  //Makes the wheels spin in opposite direction so that
  //the vehicle will spin left
  wheels.turnLeft();
  delay(2000);
  
  //Makes the wheels spin in opposite direction so that
  //the vehicle will spin right
  wheels.turnRight();
  delay(2000);
  
  //Makes the wheels stop
  wheels.standStill();
  delay(2000);
}
