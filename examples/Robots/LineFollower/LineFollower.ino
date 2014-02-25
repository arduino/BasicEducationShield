/*
  LineFollower  
  
  (c) 2014 Arduino Verkstad
*/


#include <BasicEducationShield.h>
//Servo.h is necessary to be included here
#include <Servo.h>


IRArray ir = IRArray(A1, A2, A3);
//(Wheels(left, right)
Wheels wheels=Wheels(10, 9);

void setup(){
  Serial.begin(9600);
  wheels.begin();
  delay(1000);
}

void loop(){
  int dir = ir.readLine();
  wheels.follow(dir);
}
